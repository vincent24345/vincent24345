main: pos.cpp
	g++ -std=c++11 -Wall pos.cpp menu.cpp dish.cpp docket.cpp history.cpp print.cpp -o main

product: test.cpp 
	g++ -std=c++11 -Wall test.cpp menu.cpp dish.cpp -o test1

docket: test2.cpp 
	g++ -std=c++11 -Wall test2.cpp menu.cpp dish.cpp docket.cpp -o test2
	