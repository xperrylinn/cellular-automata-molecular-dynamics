#include <cellular_automaton.h>
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <cassert>

using namespace std;

int main() {
    cout << "Hello World! From tests.cxx" << endl;
    
    /*SECTION 1
    *   TESTING INPUT SERVICES
    */

    // Testing dummy constructor which will be removed soon
    CellularAutomaton ca = CellularAutomaton();

    // Test 1: Constructor
    vector<int> indices = {
        0, 1, 2, 3,
        4, 5, 6, 7,
        8, 9, 10, 11,
        12, 13, 14, 15,
    };

    vector<string> periodic_bounds = {"periodic", "periodic", "periodic", "periodic"};

    cout<<"Test set 1: Constructing a Cellular Automaton and print_current()"<<endl;
    cout<<endl<<"Dimensions: 3x3"<<"Boundary Condition: Periodic"<<endl <<"Rule: Majority Rule"<<endl<<"Neighboorhood: Von Neumann"<<endl;

    CellularAutomaton ca2 = CellularAutomaton(
        4,
        4,
        periodic_bounds,
        "majority",
        "VonNeumann",
        indices,
        true
    );
    
    // Test get last snap shot
    cout<<endl<<"Initial configuration is stored as a vector<int> as first saved state. This can be called by get_last_snapshot()"<<endl;
    vector<int> lsn = ca2.get_last_snapshot();
    for (auto it:lsn)   {
        cout<<it<<" ";
    }

    // Test print_grid()
    cout<<endl<<endl<<"Vector<int> can be printed in formated rows by print_grid()"<<endl;
    ca2.print_grid(lsn);

    // Test print_current()
    cout<<endl<<endl<<"print_current() uses both get_last_snapshot() and print_grid() to print the current state:"<<endl;
    ca2.print_current();

    /*SECTION 2
    *   TESTING GET_NEIGHBORS
    */

   cout<<endl<<"Test set 2: Testing get_neighbors()"<<endl;

    // Test get_neighbors()
    cout<<endl<<"Neighbors to Cell 5:"<<endl;
    for (auto neighbor:ca2.get_neighbors(5))    {
        cout<<neighbor<<" ";
    }
    cout<<endl;
    // Test get_neighbors(), periodic
    cout<<"Testing for periodic bound"<<endl<<"Neighbors to Cell 4:"<<endl;
    for (auto neighbor:ca2.get_neighbors(4))    {
        cout<<neighbor<<" ";
    }
    cout<<endl<<"Neighbors to Cell 0:"<<endl;
    for (auto neighbor:ca2.get_neighbors(0))    {
        cout<<neighbor<<" ";
    }
    cout<<endl;
    // Test get_neighbors(), cutoff, fixed
    // Test set_boundary_condition
    cout<<"Changing boundary conditions: Cutoff for bottom, no bounds for other sides..."<<endl;
    vector<string> single_wall = {"none", "cutoff", "none", "none"};
    ca2.set_boundary_conditions(single_wall);
    cout<<endl<<"Testing for cutoff,no bounds. These bounds are interpreted the same in get_neighbors()"<<endl<<"Neighbors to Cell 1:"<<endl;
    for (auto neighbor:ca2.get_neighbors(1))    {
        cout<<neighbor<<" ";
    }
    cout<<endl<<endl<<"Neighbors to Cell 12:"<<endl;
    for (auto neighbor:ca2.get_neighbors(12))    {
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

    return 0;
}