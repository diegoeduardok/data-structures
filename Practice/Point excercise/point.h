#ifndef_H_POINT_ //avoid multiple inclusions statement
#define_H_POINT_ //avoid multiple inclusions

class Point{
	private:
		int x;
		int y;
	public:
		Point(){x = 0; y = 0; cout << "Default constructor. " << x << ", " << y;}
		Point(int xx, int yy){cout << "Alternative constructor. " << x << ", " << y;};
		
		//get
		int getX(){return x;}
		int getY(){return y;}

		//set
		void setX(int xx){x = xx;}
		void setY(int yy){y = yy;}

		//display
		void display();

		//destructor
		~Point(){cout << "Destructor. " << x << ", " << y;};

};
#endif