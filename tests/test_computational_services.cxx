/*
    Cellular Automaton: Tests for Computational Servicees
    ROOT/test/test_computational_services.cxx
    This file, test_computational_services.cxx, contains the test suite for the computational services of the Cellular Automaton.
*/

#include <cellular_automaton.h>
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <cassert>

using namespace std;

int main() {
    cout << "This is the test suite for the computation functions of the CellularAutomaton" << endl;

    // Test 1: Constructor
    vector<int> indices = {
        0, 1, 2, 3,
        4, 5, 6, 7,
        8, 9, 10, 11,
        12, 13, 14, 15,
    };

    vector<string> periodic_bounds = {"periodic", "periodic", "periodic", "periodic"};

    cout<<"Test set 1: Constructing a Cellular Automaton and print_current()"<<endl;
    cout<<endl<<"Dimensions: 4x4"<<endl<<"Boundary Condition: Periodic"<<endl <<"Neighboorhood: Von Neumann"<<endl;

    CellularAutomaton ca_index = CellularAutomaton(
        4,
        4,
        periodic_bounds,
        "majority",
        "VonNeumann",
        indices,
        true
    );
    
    // Test get last snap shot
    cout<<endl<<"Initial configuration is stored as a vector<int> as first saved state. This can be called by get_last_snapshot()."<<endl;
    vector<int> lsn = ca_index.get_last_snapshot();
    for (auto it:lsn)   {
        cout<<it<<" ";
    }

    // Test print_grid()
    cout<<endl<<endl<<"Vector<int> can be printed in formated rows by print_grid()."<<endl;
    ca_index.print_grid(lsn);

    // Test print_current()
    cout<<endl<<endl<<"print_current() uses both get_last_snapshot() and print_grid() to print the current state:"<<endl;
    ca_index.print_current();

    /*SECTION 2
    *   TESTING GET_NEIGHBORS
    */

   cout<<endl<<"Test set 2: Testing get_neighbors()"<<endl;

    // Test get_neighbors()

    cout<<endl<<"get_neighbors() returns a vector of ints as neighbors"<<endl<<"Using the matrix of indicies in the previous test, testing calls to get_neighbors()"<<endl;
    cout<<endl<<"Neighbors to Cell 5:"<<endl;
    for (auto neighbor:ca_index.get_neighbors(5))    {
        cout<<neighbor<<" ";
    }
    cout<<endl;
    // Test get_neighbors(), periodic
    cout<<endl<<"Testing for periodic bound"<<endl<<"Neighbors to Cell 4:"<<endl;
    for (auto neighbor:ca_index.get_neighbors(4))    {
        cout<<neighbor<<" ";
    }
    cout<<endl<<"Neighbors to Cell 0:"<<endl;
    for (auto neighbor:ca_index.get_neighbors(0))    {
        cout<<neighbor<<" ";
    }
    cout<<endl;
    
    // Test set_boundary_condition
    cout<<endl<<"Changing boundary conditions: Cutoff for bottom, no bounds for other sides..."<<endl;
    vector<string> single_wall = {"none", "cutoff", "none", "none"};
    ca_index.set_boundary_conditions(single_wall);

    // Test get_neighbors(), cutoff, fixed
    cout<<endl<<"Testing for cutoff,no bounds. These bounds are interpreted the same in get_neighbors()"<<endl<<"Neighbors to Cell 1:"<<endl;
    for (auto neighbor:ca_index.get_neighbors(1))    {
        cout<<neighbor<<" ";
    }
    cout<<endl<<"Neighbors to Cell 12:"<<endl;
    for (auto neighbor:ca_index.get_neighbors(12))    {
        cout<<neighbor<<" ";
    }
    cout<<endl;

    // Test set_neighborhood()
    cout<<endl<<"Changing neighborhood consideration: Moore"<<endl;
    ca_index.set_neighborhood("Moore");

    cout<<"Changing boundary conditions: Cutoff for bottom, periodic on left and right sides..."<<endl;
    vector<string> periodic_wall = {"none", "cutoff", "periodic", "periodic"};
    ca_index.set_boundary_conditions(periodic_wall);

    cout<<endl<<"Neighbors to Cell 0:"<<endl;
    for (auto neighbor:ca_index.get_neighbors(0))    {
        cout<<neighbor<<" ";
    }
    cout<<endl<<"Neighbors to Cell 7:"<<endl;
    for (auto neighbor:ca_index.get_neighbors(7))    {
        cout<<neighbor<<" ";
    }
    cout<<endl<<"Neighbors to Cell 15:"<<endl;
    for (auto neighbor:ca_index.get_neighbors(15))    {
        cout<<neighbor<<" ";
    }
    cout<<endl;

    /*SECTION 3
    *   TESTING RULES AND STATE TRANSITION FUNCTIONS
    */

    cout<<endl<<"Test set 3: Testing majority_rule() and parity rule() and state transition functions"<<endl;
    cout<<"Constructing a Cellular Automaton..."<<endl;
    cout<<endl<<"Dimensions: 4x4"<<"Boundary Condition: Periodic"<<endl <<"Rule: Majority Rule"<<endl<<"Neighboorhood: Von Neumann"<<endl;

    vector<int> binary = {
        1, 1, 1, 0,
        1, 1, 0, 0,
        0, 1, 1, 0,
        0, 0, 1, 0,
    };

    CellularAutomaton ca_majority = CellularAutomaton(
        4,
        4,
        periodic_bounds,
        "majority",
        "VonNeumann",
        binary,
        true
    );
    ca_majority.print_current();
    cout<<"Performing Majority Rule at cell 6 using majority_rule()..."<<endl;
    // Test Majority Rule()
    ca_majority.majority_rule(6);
    ca_majority.print_current();

    cout<<"Performing State Transition function using majority rule using state_transition_function()..."<<endl;
    // Test state_transition_function()
    ca_majority.state_transition_function();
    ca_majority.print_current();

    cout<<endl<<"Constructing a Cellular Automaton..."<<endl;
    cout<<endl<<"Dimensions: 4x4"<<"Boundary Condition: Periodic"<<endl <<"Rule: Parity Rule"<<endl<<"Neighboorhood: Von Neumann"<<endl;

    CellularAutomaton ca_parity = CellularAutomaton(
        4,
        4,
        periodic_bounds,
        "parity",
        "VonNeumann",
        binary,
        true
    );
    ca_parity.print_current();

    // Test parity_rule()
    cout<<"Performing Parity Rule at cell 6 using parity rule()..."<<endl;
    ca_parity.parity_rule(6);
    ca_parity.print_current();

    cout<<"Performing State Transition function using parity rule..."<<endl;
    ca_parity.state_transition_function();
    ca_parity.print_current();

    // Testing n_transitions() and print_all_states()
    cout<<"Performing State Transition function using parity rule for 20 steps using n_transitions()..."<<endl;
    ca_parity.n_transitions(20);
    cout<<"print_all_states() prints out all past states"<<endl;
    ca_parity.print_all_states();

    cout<<"End of test suite. All Functions perform as expected."<<endl;

    return 0;
}