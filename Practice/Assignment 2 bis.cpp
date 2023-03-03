#include <iostream>
#include <cstdlib>

using namespace std;

class Matrix
{
public:

	Matrix();//Default constructor
	Matrix(int);//Random initialization
	Matrix(Matrix mat1, Matrix mat2); //Sum
	int getSize();
	int getTrace();
	int** getValues();
	~Matrix();

private:
	int size, **values;
};

Matrix::Matrix(int size){
	this -> size = size;
	int **mat;
	mat = new int*[size]; //Array of pointers to array of ints

	for (int i = 0; i < size; ++i)
	{
		mat[i] = new int[size]; //Array of ints
	}

	for (int i = 0; i < size; ++i) //Assign values to the matrix
	{
		for (int j = 0; j < size; ++j)
		{
			mat[i][j] = 100;
		}
	}
	this -> values = mat;
};

Matrix::Matrix(Matrix mat1, Matrix mat2){
	
	this -> size = mat1.getSize();

	int **mat;
	mat = new int*[size]; //Array of pointers to array of ints

	for (int i = 0; i < size; ++i)
	{
		mat[i] = new int[size]; //Array of ints
	}

	for (int i = 0; i < size; ++i) //Assign values to the matrix
	{
		for (int j = 0; j < size; ++j)
		{
			mat[i][j] = mat1.getValues()[i][j] + mat2.getValues()[i][j];
		}
	}
	this -> values = mat;
};

int Matrix::getSize(){
	return size;
};

int Matrix::getTrace(){
	int result;
	for (int i = 0; i < size; ++i) //Assign values to the matrix
	{
		result += values[i][i];
	}
	return result;
};

int** Matrix::getValues(){
	return values;
};

Matrix::~Matrix(){
	for (int i = 0; i < size; ++i)
	{
		delete[] values[i];
	}
	delete[] values;
	cout << "Matrix destroyed" << endl;
};

//End of class definitions

void display(Matrix mat){
	int size;
	size = mat.getSize();

	for (int i = 0; i < size; ++i)
	 {
	 	for (int j = 0; j < size; ++j)
	 	{
	 		cout << values[i][j] << " ";
	 	}
	 	cout << "\n";
	 } 
};

int main()
{
	cout << "Enter size: ";
	int s;
	cin >> s;
	cout << "\n";

	Matrix mat1(s), mat2(s), sum(mat1, mat2);

	cout << "Matrix 1\n";
	display(mat1);
	cout << "Matrix 2\n";
	display(mat2);
	cout << "Sum of matrices\n";
	display(sum);

	cout << "Matrix 1 trace\n";
	cout << mat1.getTrace();
	cout << "Matrix 2 trace\n";
	cout << mat2.getTrace();
	cout << "Sum of matrices trace\n";
	cout << sum.getTrace();


	return 0;
};