#include<cellular_automaton.h>
#include<iostream>

class SoluteDispersion : public CellularAutomaton {
    public:

        SoluteDispersion() {
            std::cout << "Hello World! From SolutionDispersion() constructor" << std::endl;
        };

        void print_hello_world() {
            std::cout << "Hello World! From solute_dipersion.cxx" << std::endl;
        }
};

int main() {
    std::cout << "Hello World! solute_dispersion.cxx" << std::endl;

    SoluteDispersion();

    return 0;
}
