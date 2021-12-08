#include <string>
#include <vector>

using namespace std;

class CellularAutomaton {
    private:
        int n;  // Grid lenth
        int m;  // Grid width
        std::vector<int> current_state;
        std::vector<std::vector<int> > snap_shots;
        std::string boundary_conditions;
        std::string rule;   // Possible rule
        //std::string neighborhood;   // Von Neumann or Moore Neighborhood
        vector<int> neighbors;
        bool sequential;    // Sequential or parallel
        std::vector<int> initial_configuration;

    public:
        /* CONSTRUCTORS */
        CellularAutomaton();    // Dummy for initial testing

        CellularAutomaton(
            int n,
            int m,
            std::string boundary_conditions,
            std::string rule,
            std::string neighborhood,
            std::vector<int> initial_configuration,
            bool sequential=true
        );

        /* STATE TRANITION FUNCTION */

        /**
         * state_transition_function
         *
         * Applies the rule function to each cell of the current state grid.
         * 
         * @param previous_state previous state grid of type vector<int>.
         * @return null.
         */
        void state_transition_function(vector<int> previous_state);

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
         * set_neighbors
         *
         * returns a vector of displacements from the current cell to its neighbors of the specified neighborhood.
         * 
         * @param  string neighborhood
         * @return neighbors as a vector of integers.
         */
        vector<int> set_neighbors(string neighborhood);

        /**
         * majority_rule
         *
         * updates the state of a cell at index i in the current_state
         * 
         * @param  neighbors(vector) vector of displacements pointing to neighboring cells.
         * @return void.
         */
        void majority_rule(int i);

        /**
         * parity_rule
         *
         * TODO: fill in documentation here
         * 
         * @param  neighbors(vector) vector of displacements pointing to neighboring cells.
         * @return ???.
         */
        void parity_rule();

        /**
         * dispersion_rule
         *
         * TODO: fill in documentation here
         * 
         * @param  ???.
         * @return ???.
         */
        void dispersion_rule();

};
