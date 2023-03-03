#include <iostream>
#include "point.h"

using namespace std;

void display(Point p){
	cout << "Point " << p.getID() << " = " << p.getX() << ", " << p.getY() << endl;
}

Point minArray(Point points[], int size){
	int current = 0;
	int sum;
	int temp;

	for (int i = 0; i < size; ++i)
	{
		sum = points[i].getX() + points[i].getY();
		if (i > 0)
		{
			if (sum < temp)
			{
				current = i;
			}
		}
		temp = sum;
	}
	return points[current];
}

Point minArrayOfPointers(Point* points[], int size){
	
	int sum;
	int temp;
	Point curr;
	Point point;

	for (int i = 0; i < size; ++i)
	{	
		point = *points[i];
		cout << "ID: " << point.getID() << endl;
		sum = point.getX() + point.getY();
		cout << "Sum: " << sum << endl;
		if (i > 0)
		{
			if (sum < temp)
			{
				curr = point;
			}
		} else {curr = point;}
		temp = sum;
	}
	cout << "ID: " << curr.getID() << endl;
	return curr;
}


int main()
{
	//Step 8
	int size;
	cout << "Size: ";
	cin >> size;

	Point* pts;

	pts = new Point[size];

	for (int i = 0; i < size; ++i)
	{
		pts[i] = Point(i, 2*i, 3*i);
	}

	for (int i = 0; i < size; ++i)
	{
		display(pts[i]);
	}

	Point pMin;
	pMin = minArray(pts, size);
	cout << "Minimum" << endl;
	display(pMin);

	delete[] pts;
	//Step 9

	int sizeN; //pointers
	cout << "Size: ";
	cin >> sizeN;

	Point** ptsN;

	ptsN = new Point*[sizeN];

	for (int i = 0; i < sizeN; ++i)
	{
		ptsN[i] = new Point(i+2, 2*i, 3*i);
	}

	for (int i = 0; i < sizeN; ++i)
	{
		ptsN[i] -> display();
	}



	Point pMinN;
	pMinN = minArrayOfPointers(ptsN, sizeN);
	cout << "Minimum from pointers" << endl;
	display(pMinN);

	for (int i = 0; i < sizeN; ++i)
	{
		delete ptsN[i];
	}

	delete[] ptsN;

	return 0;
}