#include <string>
#include <vector>

using namespace std;

class CellularAutomaton {
    private:
        int n;  // Grid lenth
        int m;  // Grid width
        vector<int> current_state;
        vector<vector<int> > snap_shots;
        string boundary_conditions;
        string rule; // Possible rule
        bool sequential;
        vector<int> initial_configuration;

    public:
        /* CONSTRUCTORS */
        CellularAutomaton();    // Dummy for initial testing

        CellularAutomaton(
            int n,
            int m,
            string boundary_conditions,
            string rule,
            vector<int> initial_configuration,
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
         * get_neighbors
         *
         * returns a vector of displacements from the current cell to the 
         * 
         * @param  none
         * @return neighbors as a vector of integers.
         */
        vector<int> get_neighbors();

        /**
         * majority_rule
         *
         * TODO: fill in documentation here
         * 
         * @param  neighbors(vector) vector of displacements pointing to neighboring cells.
         * @return void.
         */
        void majority_rule();

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
