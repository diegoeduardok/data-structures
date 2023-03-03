#include <iostream>
#include <fstream>

using namespace std;

char* readAnswers(string s, int nbr);
int numberOfMissedQuestions(char* a, char* b, int nbr);
int* missedQuestions(char* a, char* b, int nbr, int missed);


int main()
{
	int numberOfQuestions = 25;
	char* correct = readAnswers("correct.txt", numberOfQuestions);
	char* student = readAnswers("student.txt", numberOfQuestions);
	int lost = numberOfMissedQuestions(correct, student, numberOfQuestions);
	int* listOfLost = missedQuestions(correct, student, numberOfQuestions, lost);

	cout << "Number of missed questions: " << lost << endl;
	cout << "Missed questions: ";
	for (int i = 0; i < lost; ++i)
	{
		cout << listOfLost[i] << ", ";
	}

	return 0;
}


char* readAnswers(string s, int nbr){
	ifstream inFile;
	char answers[nbr];
	char c;
	inFile.open(s);

	for (int i = 0; i < nbr; ++i)
	{
		inFile >> c;
		cout << c << endl;
		answers[i] = c;
	}
	inFile.close();

	return answers;
}

int numberOfMissedQuestions(char* a, char* b, int nbr){
	int result = 0;

	for (int i = 0; i < nbr; ++i)
	{
		if (a[i] != b[i])
		{
			++result;
		}
	}
	return result;
}

int* missedQuestions(char* a, char* b, int nbr, int missed){
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
	return misses;
}