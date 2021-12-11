#include <cellular_automaton.h>
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <cassert>

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

    std::map<int, std::string> boundary_conds_map_for_ca2 = {
        {0, "periodic"}, 
        {1, "periodic"}, 
        {2, "periodic"},
        {3, "periodic"}, 
        {5, "periodic"},
        {6, "periodic"}, 
        {7, "periodic"}, 
        {8, "periodic"},
    };

    CellularAutomaton ca2 = CellularAutomaton(
        3,
        3,
        "periodic",
        boundary_conds_map_for_ca2,
        "majority",
        "VanNeumann",
        v,
        true
    );
    
    // Test get last snap shot
    std::vector<int> lsn = ca2.get_last_snapshot();
    
    // Test get_cell_boundary_condition
    std::string top_left_boundary_cond = ca2.get_cell_boundary_condition(0);
    std::string top_right_boundary_cond = ca2.get_cell_boundary_condition(2);
    std::string bottom_right_boundary_cond = ca2.get_cell_boundary_condition(6);
    std::string bottom_left_boundary_cond = ca2.get_cell_boundary_condition(8);

    assert(("top_left_boundary_cond == periodic", top_left_boundary_cond == "periodic"));
    assert(("top_right_boundary_cond == periodic", top_right_boundary_cond == "periodic"));
    assert(("bottom_right_boundary_cond == periodic", bottom_right_boundary_cond == "periodic"));
    assert(("bottom_left_boundary_cond == periodic", bottom_left_boundary_cond == "periodic"));

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

    std::map<int, std::string> boundary_conds_map_for_ca3 = {
        {0, "periodic"}, 
        {1, "periodic"}, 
        {2, "periodic"},
        {3, "periodic"}, 
        {4, "periodic"},
        {7, "periodic"}, 
        {8, "periodic"}, 
        {11, "cutoff"},
        {12, "cutoff"},
        {13, "cutoff"},
        {14, "cutoff"},
        {15, "cutoff"},
    };

    CellularAutomaton ca3 = CellularAutomaton(
        3,
        3,
        "cutoff",
        boundary_conds_map_for_ca3,
        "parity",
        "VanNeumann",
        v,
        true
    );

    top_left_boundary_cond = ca3.get_cell_boundary_condition(0);
    top_right_boundary_cond = ca3.get_cell_boundary_condition(4);
    bottom_right_boundary_cond = ca3.get_cell_boundary_condition(12);
    bottom_left_boundary_cond = ca3.get_cell_boundary_condition(15);

    std::cout << top_left_boundary_cond << std::endl;
    std::cout << top_right_boundary_cond << std::endl;
    std::cout << bottom_right_boundary_cond << std::endl;
    std::cout << bottom_left_boundary_cond << std::endl;

    assert((" top_left_boundary_cond == periodic", top_left_boundary_cond == "periodic"));
    assert((" top_right_boundary_cond == periodic", top_right_boundary_cond == "periodic"));
    assert(("bottom_right_boundary_cond == cutoff", bottom_right_boundary_cond == "cutoff"));
    assert(("bottom_left_boundary_cond == cutoff", bottom_left_boundary_cond == "cutoff"));

    ca3.print_grid();
    ca3.state_transition_function();
    ca3.print_grid();

    return 0;
}