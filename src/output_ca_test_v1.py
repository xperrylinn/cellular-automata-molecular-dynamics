import random
import threading
import time
import tkinter.messagebox
import functools
import tkinter as tk  


def creatButtons(window, size):  
    length = 600 / size - 1
    buttons = []

    def setColor(i, j):  
        # print(i)
        if buttons[i][j]['bg'] == 'black':
            buttons[i][j]['bg'] = 'white'
        else:
            buttons[i][j]['bg'] = 'black'

    for i in range(size):
        buttons.append([])  
        for j in range(size):
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

    def reseat():  
        lock.acquire()
        for i in buttons:
            for j in i:
                j['bg'] = 'white'

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
    filemenu.add_command(label='restart', command=reseat)
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

    def setImg(locs):  
        for x in buttons:
            for y in x:
                y['bg'] = 'white'
        for l in locs:
            buttons[l[0]][l[1]]['bg'] = 'black'

    def randImg():  
        for x in buttons:
            for y in x:
                if random.choice((True, False)):
                    y['bg'] = 'black'
                else:
                    y['bg'] = 'white'
    
    # just randomly the put the different input positions 
    loc1 = [[3, 25], [3, 28], [4, 24], [5, 24], [5, 28], [6, 24], [6, 25], [6, 26], [6, 27], [12, 21], [12, 22],
            [13, 20], [13, 21], [13, 22], [13, 23], [14, 19], [14, 20], [14, 22], [14, 23], [15, 20], [15, 21],
            [20, 25], [20, 28], [21, 24], [22, 24], [22, 28], [23, 24], [23, 25], [23, 26], [23, 27]]
    loc2 = [[0, 6], [0, 14], [0, 22], [1, 1], [1, 2], [1, 3], [1, 6], [1, 9], [1, 10], [1, 11], [1, 14], [1, 17],
            [1, 18], [1, 19], [1, 22], [1, 25], [1, 26], [1, 27], [2, 6], [2, 14], [2, 22], [4, 2], [4, 10], [4, 18],
            [4, 26], [5, 2], [5, 5], [5, 6], [5, 7], [5, 10], [5, 13], [5, 14], [5, 15], [5, 18], [5, 21], [5, 22],
            [5, 23], [5, 26], [6, 2], [6, 10], [6, 18], [6, 26], [8, 6], [8, 14], [8, 22], [9, 1], [9, 2], [9, 3],
            [9, 6], [9, 9], [9, 10], [9, 11], [9, 14], [9, 17], [9, 18], [9, 19], [9, 22], [9, 25], [9, 26], [9, 27],
            [10, 6], [10, 14], [10, 22], [12, 2], [12, 10], [12, 18], [12, 26], [13, 2], [13, 5], [13, 6], [13, 7],
            [13, 10], [13, 13], [13, 14], [13, 15], [13, 18], [13, 21], [13, 22], [13, 23], [13, 26], [14, 2], [14, 10],
            [14, 18], [14, 26], [16, 6], [16, 14], [16, 22], [17, 1], [17, 2], [17, 3], [17, 6], [17, 9], [17, 10],
            [17, 11], [17, 14], [17, 17], [17, 18], [17, 19], [17, 22], [17, 25], [17, 26], [17, 27], [18, 6], [18, 14],
            [18, 22], [20, 2], [20, 10], [20, 18], [20, 26], [21, 2], [21, 5], [21, 6], [21, 7], [21, 10], [21, 13],
            [21, 14], [21, 15], [21, 18], [21, 21], [21, 22], [21, 23], [21, 26], [22, 2], [22, 10], [22, 18], [22, 26],
            [24, 6], [24, 14], [24, 22], [25, 1], [25, 2], [25, 3], [25, 6], [25, 9], [25, 10], [25, 11], [25, 14],
            [25, 17], [25, 18], [25, 19], [25, 22], [25, 25], [25, 26], [25, 27], [26, 6], [26, 14], [26, 22]]
    loc3 = [[0, 14], [1, 13], [1, 15], [2, 12], [2, 14], [2, 16], [3, 11], [3, 13], [3, 15], [3, 17], [4, 10], [4, 12],
            [4, 14], [4, 16], [4, 18], [5, 9], [5, 11], [5, 13], [5, 15], [5, 17], [5, 19], [6, 8], [6, 10], [6, 12],
            [6, 14], [6, 16], [6, 18], [6, 20], [7, 7], [7, 9], [7, 11], [7, 13], [7, 15], [7, 17], [7, 19], [7, 21],
            [8, 6], [8, 8], [8, 10], [8, 12], [8, 14], [8, 16], [8, 18], [8, 20], [8, 22], [9, 5], [9, 7], [9, 9],
            [9, 11], [9, 13], [9, 15], [9, 17], [9, 19], [9, 21], [9, 23]]
    # 
    imgmenu.add_command(label='random_test1', command=functools.partial(setImg, locs=loc1))
    imgmenu.add_command(label='random_test2', command=functools.partial(setImg, locs=loc2))
    imgmenu.add_command(label='random_test3', command=functools.partial(setImg, locs=loc3))
    imgmenu.add_command(label='random_test4', command=randImg)

    def instruction(): 
        tkinter.messagebox.showinfo(title='CA', message="input ")

    menubar.add_command(label='description', command=instruction)
    window.config(menu=menubar)

#testing function for getting neighbor 
def function_neighbor(buttons, length, data):  
    move = []
    static = []
    # print('running')
    for i in range(length):
        for j in range(length):
            if buttons[i][j]['bg'] == 'black':
                data[i][j] = 1
            else:
                data[i][j] = 0
    for i in range(length):
        for j in range(length):
            sum = 0
            for l in range(-1, 2):
                for m in range(-1, 2):
                    if l + i >= 0 and m + j >= 0 and l + i < length and m + j < length:
                        sum += data[i + l][j + m]
            sum -= data[i][j]
            # print(sum)
            if sum == 2 or sum == 3:
                if sum == 3:  
                    move.append([i, j])
            else:
                static.append([i, j])
    if len(move) == 0 and len(static) == 0:
        return
    if len(move) != 0:
        for l in move:
            buttons[l[0]][l[1]]['bg'] = 'black'
    if len(static) != 0:
        for d in static:
            buttons[d[0]][d[1]]['bg'] = 'white'


class cellMove():  
    speed = 1
    stop = False

    def __init__(self, buttons):
        self.length = len(buttons)
        self.data = [[0 for i in range(self.length)] for j in range(self.length)]

    def cellMove(self):
        while True:
            if self.stop:
                return
            lock.acquire()
            function_neighbor(buttons, self.length, self.data)
            lock.release()
            time.sleep(self.speed)


if __name__ == '__main__':
    window = tk.Tk() 
    window.title('CA_TEST')  
    window.geometry('754x754')  
    buttons = creatButtons(window, 29)  
    lock = threading.RLock() 
    lock.acquire()
    cellMove = cellMove(buttons)
    dataThread = threading.Thread(target=cellMove.cellMove)
    creatMenu(window, buttons, lock)  
    dataThread.start()  
    window.mainloop()  
    # winThread.run()
    
