#include <cellular_automaton.h>
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;


vector<int> CellularAutomaton::VonNeumann_neighbors(int index)  {
    vector <int> neighbors =  {index - this->m, index - 1, index, index + 1, index + this->m};
    if (index < m)  {
        if (boundary_condition_map[0] == "periodic")  {
            neighbors[0]+= n*m;
        }
        else {
            neighbors[0]=-1;
        }
    }
    
    else if (index >= ((n-1)*m))  {
        if (boundary_condition_map[1] == "periodic")  {
            neighbors[4]-= n*m;
        }
        else    {
            neighbors[4]=-1;
        }
    }

    if (index % m == 0)  {
        if (boundary_condition_map[2] == "periodic")  {
            neighbors[1]+= m;
        }
        else    {
            neighbors[1]=-1;
        }
    }

    else if (index % m == m-1)  {
        if (boundary_condition_map[3] == "periodic")  {
            neighbors[3]-= m;
        }
        else    {
            neighbors[3]=-1;
        }
    }
    return neighbors;
}

vector<int> CellularAutomaton::Moore_neighbors(int index)  {
    vector <int> neighbors =  {index - this->m - 1, index - this->m, index - this->m + 1, index - 1, index, index + 1, index + this->m - 1, index + this->m, index + this->m +1};        
    if (index < m)  {
        for (int i=0; i<3; i++) {
            if (boundary_condition_map[0] == "periodic")  {
                neighbors[i]+= n*m;
            }
            else    {
                neighbors[i]= -1;
            }
        }
    }
    else if (index >= ((n-1)*m))  {
        for (int i=6; i<9; i++) {
            if (boundary_condition_map[1] == "periodic")  {
                neighbors[i]-= n*m;
            }
            else    {
                neighbors[i]= -1;
            }
        }
    }
    if (index % m == m-1)  {
        for (int i=0; i<3; i++) {
            if (boundary_condition_map[2] == "periodic")  {
                neighbors[3*i]+= m;
            }
            else    {
                neighbors[3*i]= -1;
            }
        }
    }
    else if (index % m == m-1)  {
        for (int i=0; i<3; i++) {
            if (boundary_condition_map[3] == "periodic")  {
                neighbors[3*i+2]-= m;
            }
            else    {
                neighbors[3*i+2]-= m;
            }
        }
    }
    return neighbors;
}

list<int> processing_neighbors(vector<int> neighbors)    {
    list<int> list_neighbors(neighbors.begin(), neighbors.end());
    list_neighbors.remove(-1);
    return list_neighbors;
}

list<int> CellularAutomaton::get_neighbors(int index)  {
    vector <int> neighbors;
    if (this->neighborhood == "VonNeumann") { 
        neighbors =  VonNeumann_neighbors(index);
    }
    if (this->neighborhood == "Moore") {  
        neighbors =  Moore_neighbors(index);
    }
    list<int> list_neighbors(neighbors.begin(), neighbors.end());
    list_neighbors.remove(-1);
    return list_neighbors;
}

void CellularAutomaton::majority_rule (int index) {
    vector<int> hashtable = {0};
    vector<int> previous_state = get_last_snapshot();
    list<int> neighbors = get_neighbors (index);
    for (int n:neighbors)   {
        int neighbor_value = previous_state[n];
        if (hashtable.size() < neighbor_value)   {
            hashtable.resize(neighbor_value+1);
        }
        hashtable[neighbor_value] += 1;
    }
    int majority = distance(hashtable.begin(), max_element(hashtable.begin(), hashtable.end()));
    this->current_state[index]=majority;
}

void CellularAutomaton::parity_rule (int index) {
    vector<int> previous_state= get_last_snapshot();
    list<int> neighbors = get_neighbors (index);
    int parity_sum=0;
    for (int n:neighbors)   {
        int neighbor_value = previous_state[n]; 
            if (neighbor_value!=0 && neighbor_value!=1)   {
                cout<<"non-binary state detected. converting to 1 state."<<endl;
                neighbor_value=1;
        }
        parity_sum += neighbor_value;
    }
    int parity = parity_sum % 2;
    this->current_state[index]=parity;
}

std::vector<int> CellularAutomaton::get_last_snapshot() {
    return this->snap_shots.back();
}

void CellularAutomaton::append_snapshot(std::vector<int> snap_shot) {
    this->snap_shots.push_back(snap_shot);
}

void CellularAutomaton::state_transition_function()     {
    for (int i=0; i<n*m; i++)   {
        if (rule=="majority")   {
            majority_rule(i);
        }
        if (rule=="parity")   {
            parity_rule(i);
        }
    }
    append_snapshot(current_state);
};


// ostream& operator<<(ostream& os, const CellularAutomaton& ca) {
//     cout << "Hello World! From operator<< of CellularAutomaton" << endl;
//     return os;
// }
