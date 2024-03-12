#ifndef MENU
#define MENU
#include "dish.h"

class Menu {
    private:
        int size; 
        int dish_count = 0; 

    public:
        Dish **menu; // ptr to array of Dish objects 
        Menu (int size); // sets size of menu to allocate appropriate memory  
        Menu (); 

        bool add_dish (Dish* new_dish);
        bool remove_dish(Dish* dish); 

        Dish** get_menu(); 
        ~Menu(); 
}; 

#endif

