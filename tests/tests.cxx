#include <cellular_automaton.h>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    std::cout << "Hello World! From tests.cxx" << std::endl;
    
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

    CellularAutomaton ca2 = CellularAutomaton(
        3,
        3,
        "periodic",
        "majority",
        "VanNeumann",
        v,
        true
    );
    
    // Test get last snap shot
    std::vector<int> lsn = ca2.get_last_snapshot();
    
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
    CellularAutomaton ca3 = CellularAutomaton(
        3,
        3,
        "cutoff",
        "parity",
        "VanNeumann",
        v,
        true
    );

    ca3.print_grid();
    ca3.state_transition_function();
    ca3.print_grid();

    return 0;
}