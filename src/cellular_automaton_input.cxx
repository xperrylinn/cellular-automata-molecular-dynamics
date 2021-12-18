/*
    Cellular Automaton: Input Services
    ROOT/src/cellular_automaton_input.cxx
    This file, cellular_automaton_input.cxx, contains all the source code for the input service functions of the CellularAutomaton,
        including contruction, attribute setting, and user validation.
*/

#include <cellular_automaton.h>
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>
#include <cassert>
#include <set>

using namespace std;


CellularAutomaton::CellularAutomaton(
    int n,
    int m,
    vector<string> boundary_condition_map,
    string rule,
    string neighborhood,
    vector<int> initial_configuration,
    bool sequential) 
{

    vaidate_user_input(n, m, boundary_condition_map, neighborhood, initial_configuration);

    this->n = n;
    this->m = m;
    this->boundary_condition_map = boundary_condition_map;
    this->rule = rule;
    this->neighborhood = neighborhood;
    this->sequential = sequential;
    this->current_state=initial_configuration;
    int max=0;
    for (auto i:current_state)  {
        if (i>max)  {
            this->max=i;
        }
    }
    append_snapshot(initial_configuration);
}

void CellularAutomaton::set_boundary_conditions(vector<string> boundary_condition_map)  {
    this->boundary_condition_map = boundary_condition_map;
}

void CellularAutomaton::set_neighborhood(string neighborhood)  {
    this->neighborhood = neighborhood;
}

void CellularAutomaton::vaidate_user_input(
    int n,
    int m,
    vector<string> boundary_condition_map,
    string neighborhood,
    vector<int> initial_configuration
) {
    // Check that n and m are greator than zero
    if (n <= 0 && m <= 0) {
        std::cout << "n amd m, grid dimension parameters must be greater than zero" << std::endl;
        throw "n amd m, grid dimension parameters must be greater than zero";
    }
    // Check that n * m is equal to the initial_configuration
    if (n * m != initial_configuration.size()) {
        std::cout << "n * m must equal to the size of the initial_configuration" << std::endl;
        throw "n * m must equal to the size of the initial_configuration";
    }
    // Check the bounary conditions map is length for - one boundary condition for each of the four side of the grid
    if (boundary_condition_map.size() != 4) {
        std::cout << "You must specify exactly one boundary condition type for each or the four sides of the grid" << std::endl;
        throw "You must specify exactly one boundary condition type for each or the four sides of the grid";
    }
    // Check that the boundary conditions in the boundary condition map are valid
    for (int i = 0; i < boundary_condition_map.size(); i++) {
        std::string curr_boundary_condition = boundary_condition_map[i];
        if (
            not (curr_boundary_condition == "periodic" || 
            curr_boundary_condition == "fixed" || 
            curr_boundary_condition == "cutoff" || 
            curr_boundary_condition == "none")
            )
        {
            std::cout << "Each boundary condition must be one of the following values: \"perodic\", \"fixed\", \"cutoff\", \"none\"" << std::endl;
            throw "Each boundary condition must be one of the following values: \"perodic\", \"fixed\", \"cutoff\", \"none\"";
        }
    }
    // Check that each periodic boundary condition has it's complementaryt side as also periodic
    if (
        (boundary_condition_map[0] == "periodic" && boundary_condition_map[1] != "periodic") ||
        (boundary_condition_map[0] != "periodic" && boundary_condition_map[1] == "periodic") ||
        (boundary_condition_map[2] == "periodic" && boundary_condition_map[3] != "periodic") ||
        (boundary_condition_map[2] != "periodic" && boundary_condition_map[3] == "periodic")
    ) 
    {
        std::cout << "Periodic boundary on conditions on one side of the grid must have matching periodic boundary conditions on the oppposite side" << std::endl;
        throw "Periodic boundary on conditions on one side of the grid must have matching periodic boundary conditions on the oppposite side";
    }

}