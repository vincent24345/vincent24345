#include "menu.h"

//constructors 
Menu::Menu() {
    size = 0; 
}

Menu::Menu(int size) {
    this->size = size;
    menu = new Dish*[size]; // Allocate memory for an array of pointers
}

// functions 
bool Menu::add_dish(Dish* new_dish) {
    if (dish_count < size) {
        menu[dish_count] = new_dish;
        dish_count++;
        new_dish->set_id(dish_count); 
        return true;
    } else {
        return false;
    }
}

bool Menu::remove_dish(Dish* dish) {
    int index_to_remove = -1;

    for (int i = 0; i < dish_count; i++) { // find the index of the dish to remove
        if (menu[i]->get_name() == dish->get_name()) {
            index_to_remove = i;
            break;
        }
    }
    for (int i = index_to_remove; i < dish_count - 1; i++) { // shift elements in the array to fill the gap
        menu[i] = menu[i + 1];
    }
    dish_count--;

     if (index_to_remove == -1) {
        cout << dish->get_name()  << " was not found" << endl;
        return false;
    } else {

        cout << dish->get_name()  << " was removed" << endl;
        return true; 
    }

}

Dish ** Menu::get_menu() {
    return menu;
}

Menu:: ~Menu() {
    delete[] menu; 
}
