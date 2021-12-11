#include <cellular_automaton.h>
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;


// n * j - 1 
void CellularAutomaton::print_grid() {
    for (int i = 0; i < this->n; i++) {
        for (int j = 0; j < this-> m; j++) {
            cout << this->get_last_snapshot()[i * this->n + j] << " ";
        }
        cout << endl;
    }
}