#include "docket.h"

// Constructors 
Docket::Docket() {
    size = 0; 
}

Docket::Docket(int size, Dish** menu) {
    this->size = size;
    this->menu = menu; // Initialize the menu member
    docket = new Dish[size];
   
    time_t currentTime = std::time(nullptr);
    time = currentTime;
}

// Getters & Setters
time_t Docket::get_time() { return time; }
int Docket::get_item_count() { return item_count;}

void Docket::set_time(time_t newTime) { time = newTime; }
void Docket::set_id(int id) {this->id = id;}

// Functions
void Docket::add_dish(int input) {
    if (item_count < size) { // ensures no excessive amount of items are added
        if (input >= 1 && input <= 15) { // input validation 
            int menuIndex = input - 1; // adjusts menu index 
            docket[item_count] = *menu[menuIndex]; // add dish to docket
            item_count++;

            cout << "Added " << menu[menuIndex]->get_name() << " to the docket.\n" << endl;
        } else {
            cout << "Invalid input. Please enter a valid item number." << endl;
        }
    } else {
        cout << "Docket is full. Cannot add more items." << endl;
    }
}

Dish* Docket:: get_docket () {
    return docket; 
}

float Docket::get_total() {
    float total = 0.0;

    for (int i = 0; i < item_count; i++) {
        total += docket[i].get_cost(); // loop through docket to sum costs
    }
    return total;
}

void Docket::print_info() {
    string timeString = ctime(&time);
    timeString.pop_back();


    cout<< "Docket " << id << "      " << timeString << endl << "--------------------------------------" << endl; 
    const int nameWidth = 20;
    cout << setw(nameWidth) << left << "Item Name";
    cout << "Cost" << endl;

    for (int i = 0; i < get_item_count(); i++) {
        cout << setw(nameWidth) << left << docket[i].get_name(); // output the item name and cost with proper formatting
        cout << "$" << fixed << setprecision(2) << docket[i].get_cost() << endl;
    }

    cout << "\n"<< setw(nameWidth) << left << "Total: ";
    cout << "$" << fixed << setprecision(2) << get_total() << endl;
}


Docket::~Docket() {
    delete[] docket;
}
