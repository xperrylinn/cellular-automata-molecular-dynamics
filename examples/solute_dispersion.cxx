#include<cellular_automaton.h>
#include<algorithm>
#include<iostream>
#include<random>

class SoluteDispersion : public CellularAutomaton {
    public:
        SoluteDispersion(
            int n,
            int m,
            vector<string> boundary_condition_map,
            std::string neighborhood,
            std::vector<int> initial_configuration,
            bool sequential=true
        ): CellularAutomaton(
            n, 
            m, 
            boundary_condition_map, 
            "dispersion_rule",  // Place holder; not actually used 
            neighborhood, 
            initial_configuration, 
            sequential
            ) 
        {
            std::cout << "Hello World! From SolutionDispersion(with args) constructor" << std::endl;
        };

        void state_transition_function()     {
            for (int i=0; i < this->n * this->m; i++)   {
                dipsersion_rule(i);
            }
            fixed_bounds();
            append_snapshot(current_state);
        };

        void fixed_bounds() {
            if (boundary_condition_map[0] == "fixed") {
                for (int i=0; i<m; i++)  {
                    current_state[i]=get_last_snapshot()[i];
                }
            }
            else if (boundary_condition_map[1] == "fixed") {
                for (int i=0; i<m; i++)  {
                    current_state[(n-1)*m+i]=get_last_snapshot()[(n-1)*m+i];
                }
            }
            if (boundary_condition_map[2] == "fixed") {
                for (int i=0; i<n; i++)  {
                    current_state[m*i]=get_last_snapshot()[m*i];
                }
            }
            else if (boundary_condition_map[3] == "fixed") {
                for (int i=0; i<n; i++)  {
                    current_state[m*(i+1)-1]=get_last_snapshot()[m*(i+1)-1];
                }
            }
        }

        int count_no_borders(int index)   {
            int cutoffs = 0;
            if (index < m && boundary_condition_map[0] == "none") {
                cutoffs +=1;
            }
            else if (index >= ((n-1)*m) && boundary_condition_map[1] == "none") {
                cutoffs +=1;
            }
            if (index % m == 0 && boundary_condition_map[2] == "none") {
                cutoffs +=1;
            }
            else if (index % m == m-1 && boundary_condition_map[3] == "none") {
                cutoffs +=1;
            }
            return cutoffs;
        }

        void add_neighbors(int index, vector<int> & neighbors)   {
            int cutoffs = count_no_borders (index);
            if (this->neighborhood == "VonNeumann")    {
                for (int i=0; i<cutoffs; i++)   {
                    neighbors.push_back(-1);
                }
            }
            if (this->neighborhood == "Moore")  {
                for (int i=0; i <cutoffs; i++)  {
                    for (int i=0; i <neighbors.size()/2; i++)  {
                        neighbors.push_back(-1);
                    }
                }
            }
        }
    
        void dipsersion_rule(int index) {
            vector<int> previous_state = get_last_snapshot();
            list<int> neighbors = get_neighbors(index);
            vector<int> neighbors_as_vector(neighbors.begin(),neighbors.end());
            add_neighbors(index, neighbors_as_vector);
            int current_cell_value = previous_state[index];
            for (int i = current_cell_value; i > 0; i--) {
                this->current_state[index] -= 1;
                int random_neighbor = neighbors_as_vector[rand() % neighbors_as_vector.size()];
                if (random_neighbor != -1)  {
                    this->current_state[random_neighbor] += 1;
                }
            }
        }

        void n_transitions(int n)     {
            for (int i=0; i<n; i++)   {
                state_transition_function();
        }
    };
};

int main() {
    std::cout << "Hello World! solute_dispersion.cxx" << std::endl;

    int n = 30;
    int m = 20;
    
    vector<int> v(n * m, 0);

    // Place solutes all along the top row
    int initial_solutes_count_per_cell = 100;
    for (int i = 0; i < m; i++) {
        v[i] = initial_solutes_count_per_cell;
    }

    vector<string> boundary_conds_map_for_sa = {"cutoff", "cutoff", "periodic", "periodic"};

    SoluteDispersion sa = SoluteDispersion(
        n,
        m,
        boundary_conds_map_for_sa,
        "VonNeumann",
        v,
        true
    );

    sa.state_transition_function();
    //sa.print_current();
    sa.n_transitions(10000);
    //sa.print_all_states();

    sa.write_snap_shots_to_csv("./solute_dispersion.csv");
    sa.write_simulation_metadata_to_json("./solute_dispersion_simulation_metadata.json");

    vector<string> contain = {"cutoff", "cutoff", "cutoff", "cutoff"};

    vector<int> v2(625, 0);
    v2[313]=200;
    SoluteDispersion sa2 = SoluteDispersion(
        25,
        25,
        contain,
        "VonNeumann",
        v2,
        true
    );
    sa2.n_transitions(10000);
    sa2.write_snap_shots_to_csv("./solute_dispersion2.csv");
    sa2.write_simulation_metadata_to_json("./solute_dispersion_simulation_metadata2.json");


    return 0;
}
