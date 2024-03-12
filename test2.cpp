#include <iostream>
#include "menu.h"
#include "dish.h"
#include "docket.h"
using namespace std; 

int main() {
    int inventory_size = 10; //size of the array

    // Create an empty menu
    Menu summer_menu(inventory_size);

    // Set dishes and add them to the menu
    // Drinks (Name, Price, Size, Alcoholic)
    Drink water("Water", 1.0, "Jug", 0);
    summer_menu.add_dish(&water);
    Drink coke("Coke", 3.5, "Small", 0);
    summer_menu.add_dish(&coke);
    Drink red_wine("Red Wine", 10.5, "Glass", 1);
    summer_menu.add_dish(&red_wine);
    Drink juice("Fruit Juice", 2.5, "Medium", 0);
    summer_menu.add_dish(&juice);
    Drink beer("Beer", 5.0, "Pint", 1);
    summer_menu.add_dish(&beer);

    // Mains (Name, Price, V, VG)
    Main steak("T-Bone", 24.0, 0, 0);
    summer_menu.add_dish(&steak);
    Main ravioli("Spinach Ravioli", 17.5, 1, 0);
    summer_menu.add_dish(&ravioli);
    Main burger("Impossible Burger", 18, 1, 1);
    summer_menu.add_dish(&burger);
    Main lasagna("Lasagna", 14.0, 1, 0);
    summer_menu.add_dish(&lasagna);
    Main chicken("Roasted Chicken", 19.0, 0, 0);
    summer_menu.add_dish(&chicken);

    // Get the menu with all dishes added
    Dish** summer_menu_array = summer_menu.get_menu();  

    // Display the menu
    for (int i = 0; i < inventory_size; i++) {
        summer_menu_array[i]->print_info();
    }

    // Implement Dockets functionality
    int docket_id = 1; 
    Docket* allDockets[100]; 
    int docketIndex = 0; // index to store docket in all dockets

    Docket *docket = new Docket(30, summer_menu_array);
    docket->set_id(docket_id);
    docket_id++;

    int input;
    while (true) {
        std::cout << "Please enter a number from the dishes above (or 0 to finish the docket): ";
        if (std::cin >> input) {
            if (input == 0) {
                break; // Finish this docket
            } else if (input >= 1 && input <= 15) {
                // Add the selected dish to the docket
                docket->add_dish(input); // Adjusted input for 0-based indexing
            } else {
                std::cout << "Invalid input. Please enter a valid item number." << std::endl;
            }
        } else {
            // Clear the input buffer and ignore non-numeric input
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter a valid item number." << std::endl;
        }
    }

    // Display the docket details for the current order
    docket->print_info();
    allDockets[docketIndex] = docket;
    docketIndex++;
}
