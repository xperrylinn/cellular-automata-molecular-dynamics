   import random
import threading
import time
import csv
import math
import tkinter.messagebox
import functools
import tkinter as tk  
from random import sample


data_file = './data/random.csv'


## this is the function for user can click for the button and show the next state for neighbors around specific cell 
def creatButtons(window, col_num, row_num):  
    length = 15
    buttons = []

    def setColor(i, j):
        pass

    for i in range(row_num):
        buttons.append([])
        for j in range(col_num):
            buttons[i].append(tk.Button(master=window, bitmap='gray12', width=length, height=length, bg='white',
                                        command=functools.partial(setColor, i=i, j=j)))
            buttons[i][j].grid(row=i, column=j, )
    return buttons


def creatMenu(window, buttons, lock):
    menubar = tk.Menu(window)
    filemenu = tk.Menu(menubar, tearoff=0)
    menubar.add_cascade(label='options', menu=filemenu)

    def start():
        try:
            lock.release()
        except:
            pass

    def pause():
        lock.acquire()

    def reset():
        cellMove.stop = True
        print("restarting")

    def quit():
        cellMove.stop = True
        window.quit()

    def save():

        with open('image.txt', 'w') as f:
            for x in range(len(buttons)):
                for y in range(len(buttons[x])):
                    if buttons[x][y]['bg'] == 'black':
                        f.write('[' + str(x) + ',' + str(y) + '],')

    filemenu.add_command(label='start', command=start)
    filemenu.add_command(label='stop', command=pause)
    filemenu.add_command(label='restart', command=reset)
    filemenu.add_command(label='save', command=save)
    filemenu.add_command(label='quit', command=quit)
    setmenu = tk.Menu(menubar, tearoff=0)

    menubar.add_cascade(label='setting', menu=setmenu)

    speedmenu = tk.Menu()
    setmenu.add_cascade(label='speed_of_moving', menu=speedmenu)

    def setSpeed(newspeed):
        cellMove.speed = newspeed

    speedmenu.add_command(label='low', command=functools.partial(setSpeed, newspeed=2))
    speedmenu.add_command(label='medium low', command=functools.partial(setSpeed, newspeed=1.5))
    speedmenu.add_command(label='medium', command=functools.partial(setSpeed, newspeed=1))
    speedmenu.add_command(label='medium fast', command=functools.partial(setSpeed, newspeed=0.5))
    speedmenu.add_command(label='fast', command=functools.partial(setSpeed, newspeed=0.1))

    imgmenu = tk.Menu()
    setmenu.add_cascade(label='different random inputs', menu=imgmenu)

    def change_data(file_name, size, max_val):
        # change data
        cellMove.data_file = file_name
        cellMove.size = size
        cellMove.max_val = max_val
        print(f"data file set to {cellMove.data_file}")

    imgmenu.add_command(label='random', command=functools.partial(change_data, file_name='./data/random.csv', size=[4,4], max_val=6))
    imgmenu.add_command(label='preset', command=functools.partial(change_data, file_name='./data/solute_dispersion.csv.csv', size=[4,4], max_val=2))
    imgmenu.add_command(label='solute_dispersion1', command=functools.partial(change_data, \
        file_name='./data/solute_dispersion1.csv', size=[30,20], max_val=100))
    imgmenu.add_command(label='solute_dispersion2', command=functools.partial(change_data, \
        file_name='./data/solute_dispersion2.csv', size=[25,25], max_val=45))

    def instruction():
        tkinter.messagebox.showinfo(title='CA', message="input ")

    menubar.add_command(label='description', command=instruction)
    window.config(menu=menubar)


def calc_pos(data_size, board_size, index):
    data_row, data_col = data_size
    max_row, max_col = board_size

    # calculate row/col position and shift data center toward board center

    row = index // data_row - math.floor((data_row - max_row)/2)
    row = row if row < max_row and row >= 0 else False

    col = index % data_col - math.floor((data_col - max_col)/2)
    col = col if col < max_col and col >= 0 else False

    return row, col

def function_disp(data, buttons, size, max_val):
    """
    data: data from csv
    buttons: tk button
    size: size of data
    """
    data_row, data_col = size
    board_row = len(buttons)
    board_col = len(buttons[0])

    for i in range(len(data)):
        row, col = calc_pos(size, [board_row, board_col], i)

        print(f'data index={i} row={row}, col={col}, value={data[i]}, max_val={max_val}, ', end='')

        # row/col is False means out of bound
        if row is False: continue
        if col is False: continue

        if int(data[i]) <= 100:
            # normalize to between 1 and 99, tk offers grey1 to grey99
            val = int(( 98 * (max_val - int(data[i])) / max_val ) + 1)

            # color the buttons
            buttons[row][col]['bg'] = 'grey' + str(val)
            print(f"Color={buttons[row][col]['bg']}")

        # if data[i] == 999 trigger random function
        elif data[i] == '999':
            # for each position, sample one color
            buttons[row][col]['bg'] = sample(['grey1', 'grey20', 'grey40', 'grey60', 'grey80', 'grey99'], 1)[0]
            print('')
    return

def clear_board(buttons):
    for i in buttons:
        for j in i:
            j['bg'] = 'white'


class cellMove():
    speed = 1
    stop = False
    data_file = "./data/random.csv"
    size = [4,4]
    max_val = 4

    def __init__(self, buttons):
        self.length = len(buttons)

    def cellMove(self):

        cur_data_file = self.data_file

        while True:

            print("cellMove loop")
            print(f'cur_data_file = {cur_data_file}\ndata_file = {self.data_file}')
            print(f"size={self.size}")
            clear_board(buttons)

            with open(cur_data_file, newline='') as f:
                next(f)
                reader = csv.reader(f)
                self.data = list(reader)

            data_row_num = 0
            for data_row in self.data:
                print(f"data_row_num: {data_row_num}")
                if self.stop:
                    print("Stopping")
                    stop = False
                    clear_board(buttons)
                    return

                if cur_data_file != self.data_file:
                    print(f"data file changed detected in cellMove: {self.data_file}")
                    cur_data_file = self.data_file
                    break

                lock.acquire()
                function_disp(data_row[1:], buttons, self.size, self.max_val)
                lock.release()

                time.sleep(self.speed)
                data_row_num = data_row_num + 1

            print('Done')


if __name__ == '__main__':
    window = tk.Tk() 
    window.title('CA_TEST')
    window.geometry('700x700')
    buttons = creatButtons(window, 25, 30) # col, row
    lock = threading.RLock() 
    lock.acquire()
    cellMove = cellMove(buttons)
    dataThread = threading.Thread(target=cellMove.cellMove)
    creatMenu(window, buttons, lock)  
    dataThread.start()  
    window.mainloop()  
    # winThread.run()
