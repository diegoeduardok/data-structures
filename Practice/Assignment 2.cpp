#include <iostream>
#include <cstdlib>

using namespace std;

class Matrix
{
public:
	Matrix();

	Matrix(int); 							//First constructor, random initialization
	
	Matrix(int**);

	int** getArray();

	int getTrace();

	int getSize();

	//~Matrix(); 			//Destructor

private:
	 int **values, size;
};

Matrix::Matrix(int s){
	this -> size = s;
	int **mat;
	mat = new int*[s]; //Array of pointers to array of ints

	for (int i = 0; i < s; ++i)
	{
		mat[i] = new int[s]; //Array of ints
	}

	for (int i = 0; i < s; ++i) //Assign values to the matrix
	{
		for (int j = 0; j < s; ++j)
		{
			mat[i][j] = 100;
		}
	}
	this -> values = mat;
};

Matrix::Matrix(int** a){values = a;};

int** Matrix::getArray(){return values;};

int Matrix::getTrace(){
	int result;
	for (int i = 0; i < size; ++i)
	{
		result += values[i][i];
	}
	return result;
};

int Matrix::getSize(){return this -> size;};

Matrix Sum(Matrix a, Matrix b){

	int** sums;
	int size = a.getSize();

	
	sums = new int*[size]; //Array of pointers to array of ints

	for (int i = 0; i < size; ++i)
	{
		sums[i] = new int[size]; //Array of ints
	}

	for (int i = 0; i < size; ++i) //Assign values to the matrix
	{
		for (int j = 0; j < size; ++j)
		{
			sums[i][j] = a.getArray()[i][j] + b.getArray()[i][j];
		}
	}
	Matrix sum(sums);

	return sum;
};

/*Matrix::~Matrix(){
	for (int i = 0; i < size; ++i)
	{
		delete[] values[i];
	}
	delete[] values;
	cout << "Matrix destroyed" << endl;
};*/

void display(Matrix mat){
	
	int **array_d = mat.getArray();
	int size = mat.getSize();

	for (int i = 0; i < size; ++i)
	 {
	 	for (int j = 0; j < size; ++j)
	 	{
	 		cout << array_d[i][j] << " ";
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

	Matrix mat1(s), mat2(s);
	Matrix sum = Sum(mat1, mat2);

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

