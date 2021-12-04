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
        "moore",
        v,
        true
    );
    
    return 0;
}