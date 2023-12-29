// Author: Parker Padgett
// Assignment: Vectors
// Description: Use vectors to read in information from an input file and output
//				the data to the screen and an output file. Output the highest number
//				of credit hours as well as highest gpa. 
// Date: 2/21/2022


#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
#include <cctype>
#include <fstream>
#include <vector>
#include <math.h>

using namespace std;

// Function Declaration
void fileCheck(ifstream& inFile);
int getData(ifstream& inFile, string temp, vector<string>& fName, vector<string> &lName, vector<string> &tNumber, vector<string> &major, vector<string>& advisorName, vector<string> &gpa, vector<string>& creditHours, vector<string>& expectedGradYear, vector<string>& hardestClass, vector<string> &easiestClass);
void output(ifstream& inFile, ofstream& outFile, vector<string>& fName, vector<string>& lName, vector<string>& tNumber, vector<string>& major, vector<string>& advisorName, vector<string>& gpa, vector<string>& creditHours, vector<string>& expectedGradYear, vector<string>& hardestClass, vector<string>& easiestClass);

int main()
{
	// Variable declaration
	ifstream inFile;
	ofstream outFile;

	vector<string> fName;
	vector<string> lName;
	vector<string> tNumber;
	vector<string> major;
	vector<string> advisorName;
	vector<string> gpa;
	vector<string> creditHours;
	vector<string> expectedGradYear;
	vector<string> hardestClass;
	vector<string> easiestClass;

	int counter = 0;
	string temp, tempCH;

	// Open input and output files
	inFile.open("input.txt");
	outFile.open("output.txt");

	// Check to see if input file was found
	fileCheck(inFile);

	// Read in data from input file
	counter = getData(inFile, temp, fName, lName, tNumber, major, advisorName, gpa, creditHours, expectedGradYear, hardestClass, easiestClass);

	// Output data to screen and output file
	output(inFile, outFile, fName, lName, tNumber, major, advisorName, gpa, creditHours, expectedGradYear, hardestClass, easiestClass);


	cout << "Highest Credit Hours: " << endl;
	cout << "Highest GPA: " << endl;


	// I couldn't figure out how to sort through the credit hours and gpa :/


	//for (int a = 0; a < counter; a++)
	//{
	//	if (creditHours[a] < creditHours[a + 1])
	//	{
	//		cout << creditHours[a] << endl;
	//	}
	//}

	//for (int a = 0; a < counter; a++)
		//{
		//	for (int b = 0; b < counter - 1; b++)
		//	{
		//		if (creditHours[b] < creditHours[b + 1])
		//		{
		//			tempCH = creditHours[b];
		//			creditHours[b] = creditHours[b + 1];
		//			creditHours[b + 1] = tempCH;
		//		}
		//	}
		//}

	//cout << counter;


	inFile.close();
	outFile.close();
	return 0;
}

void fileCheck(ifstream& inFile)
{
	if (!inFile.is_open())
	{
		cout << "Input file not found";
		exit(1);
	}
}

int getData(ifstream& inFile, string temp, vector<string>& fName, vector<string>& lName, vector<string>& tNumber, vector<string>& major, vector<string>& advisorName, vector<string>& gpa, vector<string>& creditHours, vector<string>& expectedGradYear, vector<string>& hardestClass, vector<string>& easiestClass)
{
	int counter = 0;
	while (!inFile.eof())
	{
		getline(inFile, temp);
		fName.push_back(temp);

		getline(inFile, temp);
		lName.push_back(temp);

		getline(inFile, temp);
		tNumber.push_back(temp);

		getline(inFile, temp);
		major.push_back(temp);

		getline(inFile, temp);
		advisorName.push_back(temp);

		getline(inFile, temp);
		gpa.push_back(temp);

		getline(inFile, temp);
		creditHours.push_back(temp);

		getline(inFile, temp);
		expectedGradYear.push_back(temp);

		getline(inFile, temp);
		hardestClass.push_back(temp);

		getline(inFile, temp);
		easiestClass.push_back(temp);

		counter++;
	}
	return counter;
}

void output(ifstream& inFile, ofstream& outFile, vector<string>& fName, vector<string>& lName, vector<string>& tNumber, vector<string>& major, vector<string>& advisorName, vector<string>& gpa, vector<string>& creditHours, vector<string>& expectedGradYear, vector<string>& hardestClass, vector<string>& easiestClass)
{
	for (int a = 0; a < fName.size(); a++)
	{
		cout << "Name: " << fName[a] << " " << lName[a] << endl;
		outFile << "Name: " << fName[a] << " " << lName[a] << endl;

		cout << "T-Number: " << tNumber[a] << endl;
		outFile << "T-Number: " << tNumber[a] << endl;

		cout << "Major: " << major[a] << endl;
		outFile << "Major: " << major[a] << endl;

		cout << "Advisor Name: " << advisorName[a] << endl;
		outFile << "Advisor Name: " << advisorName[a] << endl;

		cout << "GPA: " << gpa[a] << endl;
		outFile << "GPA: " << gpa[a] << endl;

		cout << "Credit Hours: " << creditHours[a] << endl;
		outFile << "Credit Hours: " << creditHours[a] << endl;

		cout << "Expected Graduaation Year: " << expectedGradYear[a] << endl;
		outFile << "Expected Graduaation Year: " << expectedGradYear[a] << endl;

		cout << "Hardest Class: " << hardestClass[a] << endl;
		outFile << "Hardest Class: " << hardestClass[a] << endl;

		cout << "Easiest Class: " << easiestClass[a] << endl << endl;
		outFile << "Easiest Class: " << easiestClass[a] << endl << endl;
	}
}