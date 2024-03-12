#ifndef DISH
#define DISH

#include <iostream>
#include <string>
#include <iomanip>
#include "print.h"
using namespace std; 

class Dish: public Print {  // Inherit Print abstract class (A -> B)
    private:
        int id; // Number associated with dish
        string name; 
        float cost; 

    public: 
        Dish ();
        Dish (string name, float cost);

        // Getters & Setters 
        float get_cost (); 
        string get_name ();
        int get_id ();
  
        void set_cost (float cost); 
        void set_name(string name); 
        void set_id(int id); 
        virtual void print_info() {};  

}; 

class Drink: public Dish { // subclass of Dish and inherits Print abstract class (A -> B -> C)
    private:
        string size; // size of beverage
        bool alcoholic; // contains alcohol
    public: 
        Drink (string name, float cost, string size, bool aloholic); 
        Drink (); 
        
        // Getters & Setters
        string get_size(); 
        bool get_alcoholic(); 

        void set_size(string size); 
        void set_alcoholic(bool alcoholic);
        
        void print_info(); // implementation of pure virtual function
}; 


class Main: public Dish{ // subclass of Dish and inherits Print abstract class (A -> B)
    private:
        bool vege; // vegetarian option
        bool vegan; // vegan option 

    public: 
        Main (string name, float cost, bool vege, bool vegan); 
        Main (); 

        // Getters & Setters
        bool get_vege(); 
        bool get_vegan(); 

        void set_vege(bool vege); 
        void set_vegan(bool vegan); 

        void print_info(); // implementation of pure virtual function
}; 

class Dessert: public Dish{ // Subclass of Drink and inherits Print abstract class (A -> B -> C)
    private:
        string size; 
    public: 
        Dessert (string name, float cost, string size); 
        Dessert (); 
        
        // Getters & Setters
        string get_size(); 
        void set_size(string size); 
        
        void print_info(); // implementation of pure virtual function
}; 
#endif