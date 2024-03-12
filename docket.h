#ifndef DOCKET
#define DOCKET

#include "menu.h"
#include "print.h"
#include <ctime> 

class Docket: public Print{
    private:
        int item_count = 0; // the num of dishes in a docket
        int size; // to set size of aggergation Dish* Docket
        int id = 0; // ID of current docket
        time_t time; 
        Dish** menu; // points to a menu menu with Dish objects added 

    public:
        Docket (); 
        Docket (int size, Dish** menu); 
        Dish* docket; // ptr which will hold Dish objects when add_dish() is called

        // Getters & Setters 
        time_t get_time(); 
        int get_item_count(); 

        void set_time(time_t newTime); 
        void set_id (int id); 


        // Functions
        void add_dish (int input);
        Dish* get_docket (); // returns ptr to docket 
        float get_total (); // return total balance of docket
        void print_info(); // print key information of docket

        virtual ~Docket(); 

};
#endif