#include <iostream>
#include "point.h"

using namespace std;

Point::Point(int id){
	x = 0;
	y = 0;
	this -> id = id;
	cout << "Zero initializer, point " << id << endl;
}

Point::Point(int id, int x, int y){
	this -> x = x;
	this -> y = y;
	this -> id = id;
	cout << "Custom initializer, point " << id << endl;
}

void Point::display(){
	cout << "Point " << id << ": " << x << ", " << y << endl;
}

int Point::getX(){return x;}

int Point::getY(){return y;}

int Point::getID(){return id;}

Point::~Point(){
	cout << "Destructor called, point " << id << " (x, y): " << x << ", " << y << endl;
}

