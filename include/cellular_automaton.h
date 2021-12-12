#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <list>

using namespace std;

class CellularAutomaton {
    private:
        int n;  // Grid lenth
        int m;  // Grid width
        std::vector<int> current_state;
        std::vector<std::vector<int> > snap_shots;
        std::vector<std::string> boundary_condition_map;  // Vector defines boundary condition type for each side of the CA
        std::string rule;   // Possible rule
        std::string neighborhood;   // Von Neumann or Moore Neighborhood
        bool sequential;    // Sequential or parallel
        std::vector<int> initial_configuration;

        /* NEIGHBOR FUNCTIONS */

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

        /**
         * processing_neighbors
         *
         * converts the vector neighbors into a list, and removes all -1 from the list of neighbors.
         * 
         * @param  neighbors as a vector of integers.
         * @return neighbors as a list of integers.
         */
        list<int> processing_neighbors(vector<int>neighbors);

    public:
        /* CONSTRUCTORS */
        CellularAutomaton();    // Dummy for initial testing

        CellularAutomaton(
            int n,
            int m,
            vector<string> boundary_condition_map,
            std::string rule,
            std::string neighborhood,
            std::vector<int> initial_configuration,
            bool sequential=true
        );

        /* HELPER AND CONVINENCE FUNCTIONS */
        /**
         * print
         *
         * Appends to the list of snap shots.
         * 
         * @return std::vector<int>
         */
        void print_grid();

        /**
         * get_neighbors
         *
         * returns a vector of indices for locaions of neighboring cells using the specified neighborhood 
         * for a given index or cell location.
         * 
         * @param  int index
         * @return neighbors as a vector of integers.
         */
        list<int> get_neighbors(int index);

        /**
         * get_last_snapshot
         *
         * Returns the last grid snap shot.
         * 
         * @return std::vector<int>
         */
        std::vector<int> get_last_snapshot();

        /**
         * append_snapshot
         *
         * Appends to the list of snap shots.
         * 
         * @return std::vector<int>
         */
        void append_snapshot(std::vector<int> snap_shot);

        /* STATE TRANITION FUNCTION */

        /**
         * state_transition_function
         *
         * Applies the rule function to each cell of the current state grid.
         * 
         * @param previous_state previous state grid of type vector<int>.
         * @return null.
         */
        void state_transition_function();

        /* SNAP SHOT FUNCTION */
        /**
         * snap_shot
         *
         * TODO: fill in documentation here
         * 
         * @param state ???.
         * @return null.
         */
        void snap_shot(vector<int> state);

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
        void write_snap_shots_to_csv(std::string filename);

};
