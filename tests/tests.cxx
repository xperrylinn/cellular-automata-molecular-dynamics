#include <cellular_automaton.h>
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <cassert>

using namespace std;

int main() {
    cout << "Hello World! From tests.cxx" << endl;

    // Constructor
    vector<int> v;
    v.push_back(0);
    v.push_back(1);
    v.push_back(0);
    v.push_back(2);
    v.push_back(1);
    v.push_back(0);
    v.push_back(1);
    v.push_back(1);
    v.push_back(0);

    vector<string> boundary_conds_map_for_ca2 = {"periodic", "periodic", "periodic", "periodic"};

    CellularAutomaton ca2 = CellularAutomaton(
        3,
        3,
        boundary_conds_map_for_ca2,
        "majority",
        "VonNeumann",
        v,
        true
    );
    
    // Test get last snap shot
    vector<int> lsn = ca2.get_last_snapshot();

    // Test print_grid()
    ca2.print_grid(lsn);

    // Test get_neighbors()
    for (auto neighbor:ca2.get_neighbors(4))    {
        cout<<neighbor<<" ";
    }
    cout<<endl;

    for (auto neighbor:ca2.get_neighbors(0))    {
        cout<<neighbor<<" ";
    }
    cout<<endl;

    // Test Majority Rule()
    ca2.majority_rule(3);

    // Test state_transition_function()
    ca2.state_transition_function();
    ca2.print_current();

    // Test parity_rule()
    vector<int> v3 = {
        0, 0, 0, 0,
        0, 1, 1, 0,
        0, 1, 1, 0,
        0, 0, 0, 0,
    };

    vector<string> boundary_conds_map_for_ca3 = {"cutoff","cutoff", "periodic", "periodic"};

    CellularAutomaton ca3 = CellularAutomaton(
        4,
        4,
        boundary_conds_map_for_ca3,
        "parity",
        "VonNeumann",
        v3,
        true
    );

    ca3.print_current();
    ca3.state_transition_function();
    ca3.print_current();

    ca3.write_snap_shots_to_csv("./testing_write_snap_shots_to_csv.csv");

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

    return 0;
}