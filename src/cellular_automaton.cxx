#include <cellular_automaton.h>
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>

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

list<int> CellularAutomaton::get_neighbors(int index)  {
    vector <int> neighbors;
    if (this->neighborhood == "VanNeumann") {   // VanNeumann neighborhood: (top, left, center, right, bottom)
        neighbors =  {index - this->m, index - 1, index, index + 1, index + this->m};
        if (boundary_conditions == "periodic")  {
            if (index < m)  {
                neighbors[0]+= n*m;
            }
            else if (index >= ((n-1)*m))  {
                neighbors[4]-= n*m;
            }
            if (index % m == 0)  {
                neighbors[1]+= m;
            }
            else if (index % m == m-1)  {
                neighbors[3]-= m;
            }
        }
        if (boundary_conditions == "cutoff" || boundary_conditions == "none")   {
            if (index < m)  {
                neighbors[0]=-1;
            }
            else if (index >= ((n-1)*m))  {
                neighbors[4]=-1;
            }
            if (index % m == 0)  {
                neighbors[1]=-1;
            }
            else if (index % m == m-1)  {
                neighbors[3]=-1;
            }
        }
    }
    if (this->neighborhood == "Moore") {    // Moore neighborhood: (top left, top, top right, left, center, right, bottom left, bottom , bottom right)
        neighbors =  {index - this->m - 1, index - this->m, index - this->m + 1, index - 1, index, index + 1, index + this->m - 1, index + this->m, index + this->m +1};
        if (boundary_conditions == "periodic")  {
            if (index < m)  {
                for (int i=0; i<3; i++) {
                    neighbors[i]+= n*m;
                }
            }
            else if (index >= ((n-1)*m))  {
                for (int i=6; i<9; i++) {
                    neighbors[i]-= n*m;
                }
            }
            if (index % m == 0)  {
                for (int i=0; i<3; i++) {
                    neighbors[3*i]+= m;
                }
            }
            else if (index % m == m-1)  {
                for (int i=0; i<3; i++) {
                    neighbors[3*i+2]-= m;
                }
            }
        }
        if (boundary_conditions == "cutoff" || boundary_conditions == "none")   {
            if (index < m)  {
                for (int i=0; i<3; i++) {
                    neighbors[i]= -1;
                }
            }
            else if (index >= ((n-1)*m))  {
                for (int i=6; i<9; i++) {
                    neighbors[i]= -1;
                }
            }
            if (index % m == 0)  {
                for (int i=0; i<3; i++) {
                    neighbors[3*i]= -1;
                }
            }
            else if (index % m == m-1)  {
                for (int i=0; i<3; i++) {
                    neighbors[3*i+2]= -1;
                }
            }
        }
    }
    // convert vector to list
    list<int> list_neighbors(neighbors.begin(), neighbors.end());
    list_neighbors.remove(-1);
    return list_neighbors;
}

void CellularAutomaton::majority_rule (int index) {
    vector<int> hashtable;
    vector<int> previous_state= this->snap_shots.back();
    list<int> neighbors = get_neighbors (index);
    for (int n:neighbors)   {
        int neighbor_value=previous_state[n];
        if (hashtable.size() < neighbor_value)   {
            hashtable.resize(neighbor_value+1);
        }
        hashtable[neighbor_value] += 1;
    }
    auto majority = max_element(hashtable.begin(), hashtable.end());
    current_state[index]=*majority;
}

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
