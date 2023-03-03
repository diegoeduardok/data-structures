#include "point.h"
#include <iostream>

using namespace std;

//Display a point

void display(Point pt){
	cout << pt.getX() << ", " << pt.getY() << "\n";
}

int MinPoint(Point a[], int size){
	int m = a[0].getX() + a[0].getY();

	for(int i = 1, i < size, i++){
		int v = a[i].getX() + a[i].getY();
		if (v < m){m = v;} 
	}
}


int main(){

	Point p1, p2(5,5);
	p1.display(); //display function defined in "point.cpp"
	display(p2); //display fucniton defined in "pointDriver.cpp"

	//static array of 5 points

	Point pts[5];
	pts[0] = p1;
	pts[1] = p2;
	pts[2] = Point(7,7);
	pts[3] = Point(15,15);
	pts[4] = Point(12,22);

	//dynamic array of points
	//user defined dimension
	do
	{
		int dimension;
	cin << dimension;
	Point* pts;
	pts = new Point[dimension];
	} while (dimension >= 5 || dimension <=10;);
	


	return 0;
}