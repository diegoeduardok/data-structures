#include <iostream>

using namespace std;

class Thing {
	int x;
	int* y ;
  public:
  //Default constructor
  Thing(){cout<<"In the default constructor, We Construct too\n" ;}
  // Constructor
  Thing(int a, int b) {
	x=a ;
	y= new int;
	*y= b ;
	cout<<"In the constructor, We Construct\n" ;
   }
   //Copy constructor
   Thing(const Thing &t){
   	this -> x = t.x; 
   	y = new int; 
   	*y =  *t.y;
   }
  //Assingment operator
  Thing& operator=(const Thing& other){
  	this -> x = other.x;
  	y = new int;
  	*y = *other.y;
  	return *this;
  }
  void display(){
  	cout << "Thing(x,y): " << x << ", " << *y << endl;
  }
  //Destructor
  ~Thing() { delete y ;}
};

void what(Thing ob) {cout<<"In what(), it sounds strange"<<endl ;}

Thing why() {
	Thing o(10, 9) ;
	cout<<"In why(), we return an instance of Thing"<<endl ; return(o) ;
}

int main() {
	Thing a(2,5), b(10,12), c(6,9);
	a.display(); b.display(); c.display(); 
	Thing d = a ;
	d.display(); a.display();
	Thing e = Thing(b) ;
	e.display(); b.display();
	Thing f(c) ;
	f.display(); c.display();
	what(a) ;
	a.display();
	Thing g = why() ;
	g.display();

	Thing titi;
	titi = b;
	titi.display(); b.display();
	
	return 0;
}