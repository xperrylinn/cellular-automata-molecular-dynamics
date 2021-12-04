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
    std::string neighborhood,
    std::vector<int> initial_configuration,
    bool sequential) 
{
    std::cout << "Hello World! From CellularAutomaton constructor!" << std::endl;
    this->n = n;
    this->m = m;
    this->boundary_conditions = boundary_conditions;
    this->rule = rule;
    this->initial_configuration = initial_configuration;
    this->neighborhood = neighborhood;
    this->sequential = sequential;
}


