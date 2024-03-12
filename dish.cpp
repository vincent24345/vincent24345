#include "dish.h"

/*  Dish Class 
--------------------------------------------------------------------------------------------------------------------*/ 
// Constructors  
Dish :: Dish(string name, float cost){
    this->name = name;
    this-> cost = cost; 
}
Dish ::Dish() : Dish("", 0.0) {}  // default constructor

// Getters & Setters 
float Dish :: get_cost () { return cost;}
string Dish::get_name() {return name;}
int Dish :: get_id() {return id;}

void Dish :: set_cost (float cost) { this->cost = cost;}
void Dish::set_name(string name) { this->name = name; }
void Dish :: set_id(int id) {this->id = id;}

/*  Drink Class (Subclass of Dish A -> B)
--------------------------------------------------------------------------------------------------------------------*/ 
// Constructors
Drink :: Drink (string name, float cost, string size_, bool alco) : Dish (name, cost), size (size_), alcoholic(alco) {}
Drink :: Drink () : Drink ("", 0.0, "", 0) {} // default constructor 

// Getters & Setters
string Drink :: get_size() {return size;}
bool Drink::get_alcoholic() { return alcoholic;}

void Drink :: set_size(string size) {this-> size = size;}
void Drink::set_alcoholic(bool alcoholic) {this->alcoholic = alcoholic;}

void Drink::print_info() {
    string alcoholic = (get_alcoholic()) ? "Alcohol" : ""; // checks for alcohol 
    if (get_alcoholic() == 0) {
        // formating
        cout << left << setw(1) << get_id() << ". "; 
        cout << left << setw(20) << get_name();
        cout << "(" << get_size() << ")"; 
        cout << right << setw(30-(alcoholic.length() + get_size().length())) << "$" << fixed << setprecision(2) << get_cost() << endl;

    } else {
        cout << left << setw(1) << get_id() << ". "; 
        cout << left << setw(20) << get_name();
        cout << "(" << get_size() << "," << alcoholic << ")"; 
        cout << right << setw(29-(alcoholic.length() + get_size().length())) << "$" << fixed << setprecision(2) << get_cost() << endl;
    }
}

/*  Mains Class (Subclass of Dish A -> B)
--------------------------------------------------------------------------------------------------------------------*/ 
// Constructors 
Main::Main (string name, float cost, bool vege_, bool vegan_) : Dish (name, cost), vege(vege_), vegan(vegan_){}; 
Main:: Main () : Main("",0.0,0,0) {}; 


// Getters & Setters
bool Main::get_vege() { return vege; }
bool Main::get_vegan() { return vegan; }

void Main::set_vege(bool vege) { this->vege = vege; }
void Main::set_vegan(bool vegan) { this->vegan = vegan; }

void Main::print_info() {
    string vege = get_vege() ? "V" : "";
    string vegan = get_vegan() ? "VG" : "";
    string label = vege + (vegan.empty() ? "" : "/") + vegan;

    // adjusting axis
    if (label.empty()) {
        label = "Meat";
    }

    int indent_1 = 20;

    if (get_id() >= 10) {
        indent_1 = 19;
    }

    cout << left << setw(1) << get_id() << ". "; 
    cout << left << setw(indent_1) << get_name();
    cout << "(" << label << ")";
    cout << right << setw(30 - label.length()) << "$" << fixed << setprecision(2) << get_cost() << endl;
}

/*  Desserts Class (Subclass of Mains A -> B -> C)
--------------------------------------------------------------------------------------------------------------------*/ 
// constructors 
Dessert::Dessert(string name, float cost, string size) : Dish(name, cost), size(size) {}

Dessert::Dessert() : Dish(), size("") {}

string Dessert::get_size() {
    return size;
}

void Dessert::set_size(string size) {
    this->size = size;
}

void Dessert::print_info() { //
    cout << left << setw(1) << get_id() << ". "; 
    cout << left << setw(19) << get_name();
    cout << "(" << get_size() << ")";
    cout << right << setw(30 - get_size().length()) << "$" << fixed << setprecision(2) << get_cost() << endl;
}