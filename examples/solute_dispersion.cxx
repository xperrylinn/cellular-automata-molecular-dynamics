#include<cellular_automaton.h>
#include<iostream>

class SoluteDispersion : public CellularAutomaton {
    public:
        void print_hello_world() {
            std::cout << "Hello World! From solute_dipersion.cxx" << std::endl;
        }
};

int main() {
    std::cout << "Hello World! solute_dispersion.cxx" << std::endl;
    return 0;
}
