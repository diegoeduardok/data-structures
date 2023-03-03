#include <iostream>
#include <fstream>

using namespace std;

void readAnswers(string s, int nbr, char (&arr)[25]);
int numberOfMissedQuestions(char* a, char* b, int nbr);
//void missedQuestions(char* a, char* b, int nbr, int* &arr);


int main()
{
	const int numberOfQuestions = 25;
	char correct[numberOfQuestions];
	readAnswers("correct.txt", numberOfQuestions, correct);
	char student[numberOfQuestions];
	readAnswers("student.txt", numberOfQuestions, student);
	int lost = numberOfMissedQuestions(correct, student, numberOfQuestions);
	

	cout << "Number of missed questions: " << lost << endl;
	
}


void readAnswers(string s, int nbr, char (&arr)[25]){
	ifstream inFile;
	char c;
	inFile.open(s);

	for (int i = 0; i < nbr; ++i)
	{
		inFile >> c;
		cout << c << endl;
		arr[i] = c;
	}
	inFile.close();
}

int numberOfMissedQuestions(char* a, char* b, int nbr){
	int result = 0;
	cout << "Missed questions: ";
	for (int i = 0; i < nbr; ++i)
	{
		if (a[i] != b[i])
		{
			++result;
			cout << i+1 << ", ";
		}
	}
	cout << endl;
	return result;
}

/*void missedQuestions(char* a, char* b, int nbr, int*){
	int misses[missed];
	int count = 0;
	for (int i = 0; i < nbr; ++i)
	{
		if (a[i] != b[i])
		{
			misses[count] = i+1;
			++count;
		}
	}
}*/