/*
    Cellular Automaton: Tests for Computational Servicees
    ROOT/test/test_input_services.cxx
    This file, test_input_services.cxx, contains the test suite for the input services of the Cellular Automaton.
*/
#include <cellular_automaton.h>
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <cassert>

using namespace std;

int main() {
    cout << "This is the test suite for the input functions of the CellularAutomaton" << endl << endl;

    // Constructor
    vector<int> v3 = {
        0, 0, 0, 0,
        0, 1, 1, 0,
        0, 1, 1, 0,
        0, 0, 0, 0,
    };

    vector<string> boundary_conds_map_for_ca3 = {"cutoff","cutoff", "periodic", "periodic"};

    // Testing validating input parameters for n and m
    try{
        CellularAutomaton ca4 = CellularAutomaton(
            -1,
            5,
            boundary_conds_map_for_ca3,
            "parity",
            "VonNeumann",
            v3,
            true
        );
    } catch (char const* e){
        std::cout << "Succesfully validated non positive n and m inputs" << std::endl;
    }

    // Testing validating input parameters for n and m
    try{
        vector<int> v4 = {
            0, 0,
            0, 1
        };
        CellularAutomaton ca5 = CellularAutomaton(
            5,
            5,
            boundary_conds_map_for_ca3,
            "parity",
            "VonNeumann",
            v4,
            true
        );
    } catch (char const* e){
        std::cout << "Succesfully validated n and m inputs that do not match the initial_configuration size" << std::endl;
    }

    // Testing validating boundary conditions for each side of the grid
    try{
        vector<string> boundary_conds_map_for_ca6 = {"cutoff", "periodic", "periodic"};
        CellularAutomaton ca6 = CellularAutomaton(
            4,
            4,
            boundary_conds_map_for_ca6,
            "parity",
            "VonNeumann",
            v3,
            true
        );
    } catch (char const* e){
        std::cout << "Succesfully validated boundary conditions are specified for each of the four sides" << std::endl;
    }

    // Testing validating each specified boundary condition is supported
    try{
        vector<string> boundary_conds_map_for_ca7 = {"bad", "cutoff", "periodic", "periodic"};
        CellularAutomaton ca7 = CellularAutomaton(
            4,
            4,
            boundary_conds_map_for_ca7,
            "parity",
            "VonNeumann",
            v3,
            true
        );
    } catch (char const* e){
        std::cout << "Succesfully validated specified boundary conditions are in the valid set of bounary conditions: periodic, fixed, cutoff, and none" << std::endl;
    }

    // Testing validating periodic boundary conditions have a complementary periodic boundary condition side
    try{
        vector<string> boundary_conds_map_for_ca8 = {"periodic", "fixed", "cutoff", "cutoff"};
        CellularAutomaton ca8 = CellularAutomaton(
            4,
            4,
            boundary_conds_map_for_ca8,
            "parity",
            "VonNeumann",
            v3,
            true
        );
    } catch (char const* e){
        std::cout << "Succesfully validated each periodic boundary has a complementary periodic boundary condition side" << std::endl;
    }

    cout<<endl<<"End of test suite. All Functions perform as expected."<<endl;
    return 0;
}