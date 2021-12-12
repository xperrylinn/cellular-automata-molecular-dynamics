#include <cellular_automaton.h>
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;


/* CONSTRUCTORS */
CellularAutomaton::CellularAutomaton() {

}

CellularAutomaton::CellularAutomaton(
    int n,
    int m,
    vector<string> boundary_condition_map,
    std::string rule,
    std::string neighborhood,
    std::vector<int> initial_configuration,
    bool sequential) 
{
    std::cout << "Hello World! From CellularAutomaton constructor!" << std::endl;
    this->n = n;
    this->m = m;
    this->boundary_condition_map = boundary_condition_map;
    this->rule = rule;
    this->neighborhood = neighborhood;
    this->sequential = sequential;
    this->current_state=initial_configuration;
    append_snapshot(initial_configuration);

}
