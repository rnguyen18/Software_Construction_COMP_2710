//Ryan Nguyen
//rmn0010
//hw4_rmn0010.cpp
//This code takes two file input names puts the contents of each file into an array and combines the two arrays and then sorts the combination of the two array writing it to an output file.
//I used the website https://www.geeksforgeeks.org/insertion-sort/ to make my sorting algorithm!

#include<iostream>
#include<fstream>
#include<sstream>
#include<stdlib.h>

using namespace std;

// Convert String to Int
// Takes a String stringNumber as a parameter
// Returns an int created based on the string input
int convertStringToInt(string stringNumber);

// Gets the amount of lines that is found in a file
// fileName is taken in as a string input used to determine which file to count
// Returns an int representng the nunmber of tiels
int getFileSize(string fileName);

// Reads the file and extracts the numbers from every line and inputting it into inputArray[]
// The two parameters are inputArray which is the destination for the numbers from the input file and fileName which is the name of the file to be read
// Returns an integer which holds the size of the file
int readfile(int inputArray[],string fileName);

// Takes in two arrays, combines and sorts the two and places it into the outputArray
// Takes in 5 parameters inputArray1, inputArray1_size, inputArray2, inputArray2_size, and outputArray. The two inputarray parameters are used to provide the given data to put within outputarray. the array sizes are used in order to correctly look through the inputarrays, and the outputarray is the destination for the resulting array to be placed in.
// Returns the new array's size in an int
int sort(int inputArray1[], int inputArray1_size, int inputArray2[], int inputArray2_size, int outputArray[]);

//Takes an array and outputs it's contents into an output file
//Takes 2 parameters outputArray and outputArray_size. outputArray provides the data to be outputted and outputArray_size is used to loop through the outputArray
//Does not return a value
void writefile(int outputArray[], int outputArray_size);


int main()
{
	string input1;
	string input2;

	cout << "*** Welcome to Ryan Nguyen's sorting program ***" << endl;	
	cout << "Enter the first input file name: ";
	cin >> input1;
	int arr1[getFileSize(input1)];
	int arr1Size = readfile(arr1, input1);
	
	cout << "\nEnter the second input file name: ";
	cin >> input2;
	int arr2[getFileSize(input2)];
	int arr2Size = readfile(arr2, input2);
	
	int arr3[arr1Size + arr2Size];
	int arr3Size = sort(arr1, arr1Size, arr2, arr2Size, arr3);

	writefile(arr3, arr3Size);

	return 0;
}

int convertStringToInt(string stringNumber) {
	stringstream stream(stringNumber);
	int number;
	stream >> number;
	return number;
}

int getFileSize(string fileName) {
	ifstream inFile(fileName.c_str());
	//inFile.open(fileName.c_str());
	int size = 0;	

	if (inFile.fail()) {
		cout << "Input file opening failed!" << endl;
		exit(1);
	}

	if (inFile.is_open()) {
		string line;
		getline(inFile, line);
		while (!inFile.eof()) {
			size++;	
			getline(inFile, line);
		}
	}
	
	return size;
}

int readfile(int inputArray[], string fileName) {
	ifstream inFile(fileName.c_str());
	int size = 0;

	if (inFile.fail()) {
		cout << "Input file opening failed!" << endl;
		exit(1);
	}

	if (inFile.is_open()) {
		string line;
		getline(inFile, line);
		while (!inFile.eof()) {
			inputArray[size++] = convertStringToInt(line);
			
			getline(inFile, line);	
		}
	}
	cout << "The list of " << size << " numbers in file " << fileName << " is: " << endl;

	for (int i = 0; i < size; i++) {
		cout << inputArray[i] << endl;
	}
	
	return size;
}

int sort(int inputArray1[], int inputArray1_size, int inputArray2[], int inputArray2_size, int outputArray[]) {
	
	int outputArray_size = inputArray1_size + inputArray2_size;

	for (int arr1Count = 0; arr1Count < inputArray1_size; arr1Count++) {
		outputArray[arr1Count] = inputArray1[arr1Count];
	}	

	for (int arr2Count = 0; arr2Count < inputArray2_size; arr2Count++) {
		outputArray[inputArray1_size + arr2Count] = inputArray2[arr2Count];
	}

	for (int i = 0; i < outputArray_size; i++) {
		int temp = outputArray[i];
		int j = i;
		
		while (j > 0 && temp < outputArray[j-1]) {
			outputArray[j] = outputArray[j-1];
			j--;
		}
		
		outputArray[j] = temp;
	}

	cout << endl << "The sorted list of " << outputArray_size << " numbers is:";

	for (int v = 0; v < outputArray_size; v++) {
		cout << " " << outputArray[v];
	}

	cout << endl;

	return inputArray1_size + inputArray2_size;
}

void writefile(int outputArray[], int outputArray_size) {
	ofstream outFile("output.txt");
	for (int count = 0; count < outputArray_size; count++) {
		outFile << outputArray[count] << endl;
	}
	outFile.close();
}
