#include <cellular_automaton.h>
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <cassert>

using namespace std;

int main() {
    cout << "Hello World! From tests.cxx" << endl;
    
    // Testing dummy constructor which will be removed soon
    CellularAutomaton ca = CellularAutomaton();

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
    ca2.print_grid();

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
    ca2.print_grid();

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

    ca3.print_grid();
    ca3.state_transition_function();
    ca3.print_grid();

    ca3.write_snap_shots_to_csv("./testing_write_snap_shots_to_csv.csv");

    return 0;
}