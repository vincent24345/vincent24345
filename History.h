#include "docket.h"
#include "menu.h"
#include <fstream>


class History {
private:
    int size;
    Docket** all_dockets;

public:
    History(Docket** all_dockets, int size);
    void print_history();

    // Insights printed in terminal 
    float get_total(); 
    int get_num_sales (); 
    void quantity_sold ();    

    // Insights exported to txt file
    void txt_history(string file_name); 
    void txt_stats(string file_name); 

    ~History(); // free memory 
};

