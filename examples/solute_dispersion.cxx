#include<cellular_automaton.h>
#include<iostream>


class SoluteDispersion : public CellularAutomaton {
    public:

        SoluteDispersion() {
            std::cout << "Hello World! From SolutionDispersion() constructor" << std::endl;
        };

        SoluteDispersion(
            int n,
            int m,
            vector<string> boundary_condition_map,
            std::string rule,
            std::string neighborhood,
            std::vector<int> initial_configuration,
            bool sequential=true
        ): CellularAutomaton(
            n, 
            m, 
            boundary_condition_map, 
            rule, 
            neighborhood, 
            initial_configuration, 
            sequential
            ) 
        {
            std::cout << "Hello World! From SolutionDispersion(with args) constructor" << std::endl;
        };

        void print_hello_world() {
            std::cout << "Hello World! From solute_dipersion.cxx" << std::endl;
        }

        void state_transition_function()     {
            for (int i=0; i < this->n * this->m; i++)   {
                std::cout << "Hello World! From SoluteDispersion.state_transition_function" << std::endl;
                // Todo: add code here to call dispersion rule
            }
            append_snapshot(current_state);
        };

        void dipsersion_rule(int index) {
            vector<int> hashtable = {0};
            vector<int> previous_state = get_last_snapshot();
            list<int> neighbors = get_neighbors (index);
            for (int n:neighbors)   {
                int neighbor_value = previous_state[n];
                int current_cell_value = previous_state[index];
                if (neighbor_value < current_cell_value) {
                    std::cout << "hi" << std::endl;
                }
            }
            this->current_state[index]=1;
        }

};

int main() {
    std::cout << "Hello World! solute_dispersion.cxx" << std::endl;

    vector<int> v3 = {
        0, 0, 0, 0,
        0, 1, 1, 0,
        0, 1, 1, 0,
        0, 0, 0, 0,
    };

    vector<string> boundary_conds_map_for_ca3 = {"cutoff","cutoff", "periodic", "periodic"};

    SoluteDispersion(
        4,
        4,
        boundary_conds_map_for_ca3,
        "parity",
        "VanNeumann",
        v3,
        true
    );

    return 0;
}
