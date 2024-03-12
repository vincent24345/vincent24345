#include <iostream>
#include "menu.h"
#include "dish.h"
#include "docket.h"
#include "History.h"

void displayMainMenu() {
    std::cout << "\nPlease choose from the following" << std::endl; 
    std::cout << "'D' to access Dockets" << std::endl;
    std::cout << "'H' to access History" << std::endl;
    std::cout << "'I' to access Insights" << std::endl;
    std::cout << "'Q' to quit\n" << std::endl;
    std::cout << "Enter choice: "; 
}

int main() {
    int inventory_size = 15; //size of the array

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
    Main salad("Caesar Salad", 12.0, 1, 1);
    summer_menu.add_dish(&salad);

    // Desserts (Name, Price, Size)
    Dessert choco_cake("Chocolate Cake", 8.5, "Slice");
    summer_menu.add_dish(&choco_cake);
    Dessert ice_cream("Vanilla Ice Cream", 4.5, "Scoop");
    summer_menu.add_dish(&ice_cream);
    Dessert pie("Apple Pie", 6.5, "Slice");
    summer_menu.add_dish(&pie);
    Dessert pudding("Chocolate Pudding", 7.0, "Cup");
    summer_menu.add_dish(&pudding);

    // Get the menu with all dishes added
    Dish** summer_menu_array = summer_menu.get_menu();  

    // Implement Dockets functionality
    char choice;
    int docket_id = 1; 
    Docket* allDockets[100]; 
    int docketIndex = 0; // index to store docket in all dockets

    // Welcome message
    std::cout << "Hi, welcome to the POS restaurant system" << endl;

    char choice_menu; 
    while (true) {
    displayMainMenu();
    std::cin >> choice_menu;

    switch (choice_menu) {
        case 'D':
            // Access Dockets
            while (true) {
                // Display Dockets menu
                std::cout << "Dockets Section" << std::endl;

                while (true) {
                cout << "Create a new docket? (Y/N): ";
                cin >> choice;

                while (choice != 'Y' && choice != 'N') {
                    cout << "Invalid input. Please enter (Y/N): ";
                    cin >> choice;
                }

                if (choice == 'N') {
                    cout << "You have exited docket." << endl;
                    break;
                } else {
                    // Create a new Docket object for each order
                    Docket *docket = new Docket(30, summer_menu_array);
                    docket->set_id(docket_id);
                    docket_id++;


                    // Display the menu
                    for (int i = 0; i < inventory_size; i++) {
                        summer_menu_array[i]->print_info();
                    }

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
    } 
                    
                std::cout << "Press 'B' to go back to the main menu" << std::endl;
                std::cin >> choice_menu;
                if (choice_menu == 'B') {
                    break; // Go back to the main menu
                }
            }
            break;

        case 'H':
            // Access History
            while (true) {
                // History logic
                std::cout << "History Section" << std::endl;
                std:: cout << "Please enter 'V' to view docket history: "; 

                char choice; 
                cin >> choice; 
                
                while (choice != 'V') {
                    cout << "Invalid input. Please enter 'V' to view history: ";
                    cin >> choice;
                }

                if (choice == 'V') {
                    History history(allDockets, docketIndex);
                    history.print_history();
                }

                std::cout << "Press 'B' to go back to the main menu" << std::endl;
                std::cin >> choice_menu;
                while (choice_menu != 'B') {
                    std::cout << "Invalid input. Enter 'B' to go back to menu: " ;
                    cin >> choice_menu; 

                }
                if (choice_menu == 'B') {
                    break; // Go back to the main menu
                }
            }
            break;

        case 'I':
            while (true) {
                // Insights logic
                std::cout << "Insights Section" << std::endl;
                std::cout << "'TS' to export a .txt fle of statistics" << std::endl; 
                std::cout << "'TH' to export a .txt fle of history" << std::endl; 
                std::cout << "'P' to view dish performance" << std::endl; 
                std::cout << "'T' to view total sales" << std::endl; 
                std::cout << "'S' to view number of sales" << std::endl; 
                std::cout << "Please enter a follwing option: "; 

                string choice; 
                cin >> choice; 

                while (choice != "TS" && choice != "Q" && choice != "S" && choice != "T" && choice != "P" && choice != "TH")  {
                    cout << "Invalid input. Please try again: ";
                    cin >> choice;
                }

                if (choice == "TS") {
                    History history(allDockets, docketIndex);
                    history.txt_stats("Stats.txt");
                }

                if (choice == "P") {
                    History history(allDockets, docketIndex);
                    history.quantity_sold(); 
                }

                if (choice == "T") {
                    History history(allDockets, docketIndex);
                    cout << "Total: $" << history.get_total() << endl; 
                }                    
                
                if (choice == "S") {
                    History history(allDockets, docketIndex);
                    cout << "Num of sales: " << history.get_num_sales() << endl; 
                }      

                if (choice == "TH") {
                    History history(allDockets, docketIndex);
                    history.txt_history("History.txt"); 
                }              

                std::cout << "Press 'B' to go back to the main menu" << std::endl;
                std::cin >> choice_menu;
                while (choice_menu != 'B') {
                    std::cout << "Invalid input. Enter 'B' to go back to menu: " ;
                    cin >> choice_menu; 
                }
                if (choice_menu == 'B') {
                    break; // Go back to the main menu
                }
            }
            break;

        case 'Q':
            // Quit the program
            return 0;

        default:
            std::cout << "Invalid input. Please enter a valid option." << std::endl;
    }
}

for (int i = 0; i < docketIndex; i++) { // free memory  
    delete allDockets[i];
}

return 0;
}