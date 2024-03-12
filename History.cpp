#include "History.h"

// Constructors
History::History(Docket** all_dockets, int size) {
    this->size = size;
    this->all_dockets = all_dockets;
}

void History::print_history() {
    cout << "History" << endl << "--------------------------------------" << endl;
    for (int i = 0; i < size; i++) {
        all_dockets[i]->print_info(); // loop through dockets and call print_info
        cout << endl;
    }
}

// Insight functions
float History :: get_total() {
        float total = 0; 
        for (int i = 0; i < size; i++) {
            total += all_dockets[i]->get_total(); 
        }
        return total; 
    }

int History :: get_num_sales() {
    return size; 
}

void History::quantity_sold() {
    unordered_map<string, int> itemCounts; // create map which holds dish names and item count

    cout << "Items and quantity sold" << endl << "--------------------------------------" << endl;
    for (int i = 0; i < size; i++) {
        Docket* docket = all_dockets[i];
        int itemCount = docket->get_item_count(); // acess the number of items in docket
        for (int j = 0; j < itemCount; j++) { 
            string itemName = docket->get_docket()[j].get_name(); // loop through docket items and retrieve name
            itemCounts[itemName] += 1; // update the item count for this dish
        }
    }

    for (const auto& pair : itemCounts) {
        std::cout << "Dish: " << pair.first << "\t Quantity Sold: " << pair.second << endl; // print dish an quantity
    }
    cout << endl; 
}

// .txt export functions
void History :: txt_history(string file_name) {
        ofstream outputFile(file_name); // create output file

        if (outputFile.is_open()) {
            outputFile << "History" << std::endl;
            outputFile << std::endl;  

            for (int i = 0; i < size; i++) {
                // arrange time in correct format
                time_t time = all_dockets[i] -> get_time(); 
                string timeString = ctime(&time); 
                timeString.pop_back();

                // format and call functions to print docket history 
                outputFile << "Docket " << i + 1 << "\t" << timeString << std::endl;
                outputFile << "--------------------------------------" << std::endl;

                int itemCount = all_dockets[i]->get_item_count();

                for (int j = 0; j < itemCount; j++) {
                    outputFile << all_dockets[i]->get_docket()[j].get_name() << "\t$" << all_dockets[i]->get_docket()[j].get_cost() << std::endl;
                }

                outputFile << "Total:\t$" << all_dockets[i]->get_total() << std::endl;
                outputFile << std::endl;  
            }
        outputFile.close();
        }
}

void History :: txt_stats(string file_name) {
        ofstream outputFile(file_name); 

        if (outputFile.is_open()) {
            outputFile << "Stats" << std::endl;
            outputFile << "Total sales balance: $" << get_total() << std::endl; 
            outputFile << "Number of dockets: " << get_num_sales() << std::endl; 

        outputFile.close();
        }
}

History::~History() {}