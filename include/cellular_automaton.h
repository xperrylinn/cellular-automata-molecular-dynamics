#include <iostream>
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
        std::string neighborhood;   // Von Neumann or Moore Neighborhood
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
        void state_transition_function(std::vector<int> previous_state);

        /* SNAP SHOT FUNCTION */
        /**
         * snap_shot
         *
         * TODO: fill in documentation here
         * 
         * @param state ???.
         * @return null.
         */
        void snap_shot(std::vector<int> state);

        /* RULES */

        /**
         * majority_rule
         *
         * TODO: fill in documentation here
         * 
         * @param  ???.
         * @return ???.
         */
        void majority_rule();

        /**
         * parity_rule
         *
         * TODO: fill in documentation here
         * 
         * @param  ???.
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
