#include<cellular_automaton.h>
#include<algorithm>
#include<iostream>
#include<random>

class SoluteDispersion : public CellularAutomaton {
    private:
        int max_solutes_per_cell;

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
            int max_solutes_per_cell,
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
            this->max_solutes_per_cell = max_solutes_per_cell;
        };

        void print_hello_world() {
            std::cout << "Hello World! From solute_dipersion.cxx" << std::endl;
        }

        void state_transition_function()     {
            for (int i=0; i < this->n * this->m; i++)   {
                dipsersion_rule(i);
            }
            append_snapshot(current_state);
        };

        void dipsersion_rule(int index) {
            vector<int> previous_state = get_last_snapshot();
            list<int> neighbors = get_neighbors(index);
            if (neighbors.size() == 0) {
                std::cout << "hey neighbors size " << neighbors.size() << std::endl;
            }
            vector<int> neighbors_as_vector(neighbors.size());
            std::copy(neighbors.begin(), neighbors.end(), neighbors_as_vector.begin());
            int current_cell_value = previous_state[index];
            for (int i = current_cell_value; i > 0; i--) {
                this->current_state[index] -= 1;
                if (neighbors.size() == 0) {
                    std::cout << "hey neighbors size " << neighbors.size() << std::endl;
                }
                int random_neighbor = neighbors_as_vector[rand() % neighbors.size()];
                this->current_state[random_neighbor] += 1;
            }
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

    SoluteDispersion sa = SoluteDispersion(
        4,
        4,
        boundary_conds_map_for_ca3,
        "parity",
        "VonNeumann",
        v3,
        5,
        true
    );

    sa.print_grid();
    sa.state_transition_function();
    sa.print_grid();

    return 0;
}
