#ifndef _POINT_
#define _POINT_

class Point
{
public:
	Point(){x = y = 0;}
	Point(int id);
	Point(int id, int x, int y);

	void display();
	int getX();
	int getY();
	int getID();

	~Point();

private:
	int x, y, id;
	
};

#endif