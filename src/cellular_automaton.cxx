#include <cellular_automata.h>
#include <string>
#include <vector>

using namespace std;

/* CONSTRUCTORS */
CellularAutomaton::CellularAutomaton(
    int n,
    int m,
    std::string boundary_conditions,
    std::string rule,
    bool sequential=true,
    std::vector<int> initial_configuration;
) {
    std::cout << "Hello World! From CellularAutomaton constructor!" << std::endl;
}


