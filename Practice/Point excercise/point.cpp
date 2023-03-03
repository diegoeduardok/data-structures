#include "point.h"
#include <iostream>

using namespace std;

Point::Point(int xx, int yy){
	x = xx;
	y = yy;
	//if we used x and y as name of variables, we would have
	// this -> x = x;
	// this -> y = y;
	//this is a pointer
}

void Point::display(){
	cout << x << ", " << y << "\n";
}