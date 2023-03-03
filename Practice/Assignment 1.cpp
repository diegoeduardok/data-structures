#include <iostream>
#include <cstdlib>

using namespace std;

int getNbRooms(); //prototype of function, asks number of rooms to the user
void inputPaintPrice(double&); //prototype, asks price of paint
int getWallSpace(int); // asks for wall surface area in square feet

int main(){
	
	int NbRooms = getNbRooms();
	int wallsSpace = getWallSpace(NbRooms);

	double pricePerGallon = 0;
	inputPaintPrice(pricePerGallon);

	const int squareFeet = 110;
	const int hrsLabor = 8;
	const int pricePerHour = 25;
	float gallonsReq = wallsSpace/squareFeet;
	float hrsLaborReq = hrsLabor*wallsSpace/squareFeet;
	float costPaint = gallonsReq*pricePerGallon;
	float costLabor = hrsLaborReq*pricePerHour;
	float totalCost = costLabor + costPaint;

	cout << "Gallons of paint required: " << gallonsReq << "\n";
	cout << "Hours of labor required: " << hrsLaborReq << "\n";
	cout << "Cost of paint: " << costPaint << "\n";
	cout << "Cost of labor: " << costLabor << "\n";
	cout << "Total cost: " << totalCost << "\n";

	return 0;
}

int getNbRooms(){
	
	int x = 0;
	while(x < 1){

		cout << "Enter number of rooms: ";
		cin >> x;
		if (x < 1)
		{
			cout << "Number less than 1 is not accepted, try again.\n";
		}
	}
	
	return x;
}

int getWallSpace(int a){
	int x = -1;
	while(x < 0){
		cout << "Enter square footage per room: ";
		cin >> x;
		if(x < 0){
			cout << "Number is not positive, try again.\n";
		}
	}
	return x*a;
}

void inputPaintPrice(double& a){
	while(a < 10){
		cout << "Enter price per gallon: ";
		cin >> a;
		if(a < 10){
			cout << "Value less than 10, try again.\n";
		}
	}
}