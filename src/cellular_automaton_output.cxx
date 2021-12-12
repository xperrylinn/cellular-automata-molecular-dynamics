#include <cellular_automaton.h>
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>
#include <fstream>

using namespace std;

// n * j - 1 
void CellularAutomaton::print_grid() {
    for (int i = 0; i < this->n; i++) {
        for (int j = 0; j < this-> m; j++) {
            cout << this->get_last_snapshot()[i * this->n + j] << " ";
        }
        cout << endl;
    }
}

void CellularAutomaton::write_snap_shots_to_csv(std::string filename) {
    // Create an output filestream object
    std::ofstream csv(filename);
    
    // Set first row of the CSV as column names
    csv << "Time Step,";
    for (int i = 0; i < this->n * this->m - 1; i++) {
        csv << i << ",";
    }
    csv << (this->n * this->m - 1) << "\n";
    
    // Write each snap shot to a row of the CSV
    for(int i = 0; i < this->snap_shots.size(); i++) {
        csv << i << ",";
        std::vector<int> snap_shot = this->snap_shots[i];
        for (int j = 0; j < snap_shot.size() - 1; j++) {
            csv << snap_shot[j] << ",";
        }
        csv << snap_shot[snap_shot.size() - 1] << "\n";
    }
    
    // Close the CSV file
    csv.close();
}
