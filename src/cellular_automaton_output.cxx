#include <cellular_automaton.h>
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>
#include <fstream>

using namespace std;

// n * j - 1 
void CellularAutomaton::print_grid(vector<int> state) {
    for (int i = 0; i < this->n; i++) {
        for (int j = 0; j < this-> m; j++) {
            cout << state[i * this->n + j] << "\t";
        }
        cout << endl;
    }
}

void CellularAutomaton::print_current() {
    print_grid(get_last_snapshot());
}

void CellularAutomaton::print_all_states() {
    for (vector<int> snapshot:snap_shots)   {
        print_grid(snapshot);
        cout<<endl;
    }
}

void CellularAutomaton::print_neighbors(vector<int> neighbors) {
    for (auto it:neighbors) {
        cout << it << " ";
    }
    cout << endl;
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

void CellularAutomaton::write_simulation_metadata_to_json(std::string filename) {
    // Create an output filestream object
    std::ofstream text_file(filename);
    
    // Write meta data to file
    text_file << "{"<<endl;
    text_file << "\"n, number of rows\": \"" << this->n << "\","<< std::endl;
    text_file << "\"m, number of columns\": \"" << this->m << "\","<< std::endl;
    text_file << "\"number of snapshots\": \"" << this->snap_shots.size() << "\","<< std::endl;
    text_file << "\"max number of states\": \"" << this->max << "\""<< std::endl<< "}"<<endl;

    // Close the txt file
    text_file.close();
}
