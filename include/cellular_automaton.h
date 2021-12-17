#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <list>

using namespace std;

class CellularAutomaton {
    protected:
        int n;  // Grid lenth
        int m;  // Grid width
        vector<int> current_state;
        vector<vector<int> > snap_shots;          // Vector of states at timesteps as Cellular Automaton transitions.
        vector<string> boundary_condition_map;    // Vector defines boundary condition type for each side of the CA {top, bottom, left, right}
        string rule;   // Possible rule
        string neighborhood;   // Von Neumann or Moore Neighborhood
        bool sequential;    // Sequential or parallel
        vector<int> initial_configuration;

        /**
         * VonNeumann_neighbors
         *
         * returns a vector of indices for locations of neighboring cells using the Von Neumann neighborhood, 
         * then does pre-processing of the vector considering the boundary conditions.
         *      If the boundary is periodic, it adjusts the neighbor to the correct index.
         *      Otherwise for other boundary conditions, it changes the index to -1.
         * VonNeumann neighborhood: (top, left, center, right, bottom)
         * 
         * @param  int index
         * @return neighbors as a vector of integers.
         */
        vector<int> VonNeumann_neighbors(int index);

        /**
         * Moore_neighbors
         *
         * returns a vector of indices for locations of neighboring cells using the Moore neighborhood, 
         * then does pre-processing of the vector considering the boundary conditions.
         *      If the boundary is periodic, it adjusts the neighbor to the correct index.
         *      Otherwise for other boundary conditions, it changes the index to -1.
         * Moore neighborhood: (top left, top, top right, left, center, right, bottom left, bottom , bottom right)
         * 
         * @param  int index
         * @return neighbors as a vector of integers.
         */
        vector<int> Moore_neighbors(int index);

    public:
        /* INPUT SERVICES METHODS */
        
        /* CONSTRUCTORS */
        CellularAutomaton(
            int n,
            int m,
            vector<string> boundary_condition_map,
            string rule,
            string neighborhood,
            vector<int> initial_configuration,
            bool sequential=true
        );

        void vaidate_user_input(
            int n,
            int m,
            vector<string> boundary_condition_map,
            string neighborhood,
            vector<int> initial_configuration
        );

        /* HELPER AND CONVINENCE FUNCTIONS */
        /**
         * get_neighbors
         *
         * Returns a list of indices for locations of neighboring cells considering the specified neighborhood 
         * for a given index or cell location.
         * 
         * @param  int index
         * @return list<int> neighbors.
         */
        list<int> get_neighbors(int index);

        /**
         * append_snapshot
         *
         * Appends to the list of snap shots.
         * 
         * @return vector<int>
         */
        void append_snapshot(vector<int> snap_shot);

        /**
         * get_last_snapshot
         *
         * Returns the last state of the Cellular Automaton in snap_shots.
         * 
         * @return vector<int>
         */
        vector<int> get_last_snapshot();

        /*
        */
        void set_boundary_conditions(vector<string> boundary_condition_map);

        /*
        */
        void set_neighborhood(string neighborhood);

        /* PRINTING TO COUT */

        /**
         * print_grid
         *
         * Prints a state of the Cellular Automaton in snap_shots to std::cout.
         * 
         * @param vector<int>
         * @return void.
         * 
         */
        void print_grid(vector<int> state);

        /**
         * print_current
         *
         * Prints the last state of the Cellular Automaton in snap_shots to std::cout.
         * 
         * @param void.
         * @return void.
         * 
         */
        void print_current();

        /**
         * print_all_states
         *
         * Prints a state of the Cellular Automaton in snap_shots to std::cout.
         * 
         * @param void.
         * @return void.
         * 
         */
        void print_all_states();

        void print_neighbors(vector<int> neighbors);

        /* STATE TRANITION FUNCTION */

        /**
         * state_transition_function
         *
         * Applies the rule function to each cell of the current state grid.
         * 
         * @param none.
         * @return void.
         */
        void state_transition_function();

        /**
         * n_transitions()
         *
         * Applies state transition function for n iterations
         * 
         * @param int n interations
         * @return void.
         */
        void n_transitions(int n);

        /* RULES */

        /**
         * majority_rule
         *
         * updates the state of a cell at index in the current_state by majority rule.
         * 
         * @param  int index to be changed.
         * @return void.
         */
        void majority_rule(int index);

        /**
         * parity_rule
         *
         * updates the state of a cell at index in the current_state by parity rule. Used for Binary Cellular Automata
         * 
         * @param  int index to be changed.
         * @return void.
         */
        void parity_rule(int index);

        /* OUPUT SERVICES METHODS */

        /**
         * writes the snap shots to a CSV file where there is a column for the
         * the stamp and a column for each of the grid cells from a row major 
         * array
         *
         * @param  file name and path string
         * @return void.
         */
        void write_snap_shots_to_csv(string filename);

        void write_simulation_metadata_to_txt(std::string filename);

};
