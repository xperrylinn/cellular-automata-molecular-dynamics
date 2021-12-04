#include <cellular_automaton.h>
#include <iostream>
#include <string>
#include <vector>

using namespace std;


/* CONSTRUCTORS */
CellularAutomaton::CellularAutomaton() {
    
}

CellularAutomaton::CellularAutomaton(
    int n,
    int m,
    std::string boundary_conditions,
    std::string rule,
    std::vector<int> initial_configuration,
    bool sequential) {
    std::cout << "Hello World! From CellularAutomaton constructor!" << std::endl;
}


