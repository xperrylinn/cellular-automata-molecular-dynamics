#include <cellular_automaton.h>
#include <iostream>
#include <string>
#include <vector>

using namespace std;


/* CONSTRUCTORS */
CellularAutomaton::CellularAutomaton() {

}

CellularAutomaton::CellularAutomaton(
    int n,
    int m,
    std::string boundary_conditions,
    std::string rule,
    std::string neighborhood,
    std::vector<int> initial_configuration,
    bool sequential) 
{
    std::cout << "Hello World! From CellularAutomaton constructor!" << std::endl;
    this->n = n;
    this->m = m;
    this->boundary_conditions = boundary_conditions;
    this->rule = rule;
    this->neighborhood = neighborhood;
    this->sequential = sequential;
    
    append_snapshot(initial_configuration);

}
// n * j - 1 
void CellularAutomaton::print_grid() {
    for (int i = 0; i < this->n; i++) {
        for (int j = 0; j < this-> m; j++) {
            cout << this->get_last_snapshot()[i * this->n + j] << " ";
        }
        cout << endl;
    }
}

vector<int> CellularAutomaton::set_neighbors(string neighborhood)  {
    vector<int> neighbors {this->m * -1, -1, 1, this->m};
    if (neighborhood == "Moore") {
        vector<int> corners {(this->m + 1)* -1, (this->m - 1)* -1, this->m - 1, this->m +1};
        for (int n:corners) {
            neighbors.push_back(n);
        }
    }
    return neighbors;
}

void CellularAutomaton::majority_rule (int i) {}

std::vector<int> CellularAutomaton::get_last_snapshot() {
    return this->snap_shots.back();
}

void CellularAutomaton::append_snapshot(std::vector<int> snap_shot) {
    this->snap_shots.push_back(snap_shot);
}

// ostream& operator<<(ostream& os, const CellularAutomaton& ca) {
//     cout << "Hello World! From operator<< of CellularAutomaton" << endl;
//     return os;
// }
