#include "intArray.h"
#include <iostream>
#include <fstream>
#include <string>
#include <array>
#include <iomanip>
#include <stdexcept>


intArray::intArray() : curIntCount(0) {
	//Intentionally left blank
}

void intArray::displayArray() {
	
	std::cout << std::endl << "The current array is: " << std::endl;
	for (int i = 0; i < curIntCount; i++) {
		//Width is set to 4 for readibility. Can change if dealing with larger numbers.
		std::cout << std::setw(4) << theArray[i] << " ";
		if ((i + 1) % 10 == 0) {
			std::cout << std::endl;
		}
	}
	std::cout << std::endl << std::endl;
}

void intArray::readFileData() {
	std::ifstream inputFile("ints.txt");
	if (inputFile.is_open()) {
		int i = 0;
		
		while (inputFile >> theArray[i]) {
			i++;
			curIntCount++;
		}
		inputFile.close();
	}
}

int intArray::indexLocationOfNum(int inputNum) {
	int indexLocation = -1;

	for (int i = 0; i < ARRAY_SIZE; i++) {
		if (theArray[i] == inputNum) {
			indexLocation = i;
			break;
		}
	}

	return indexLocation;
}

bool intArray::modifyValue(int index) {
	
	bool didModify = false;
	try {
		/*
		* I couldn't get an exception to be thrown when accessing out of bounds indexes.
		* So instead basic validation of the index is done and an exception is thrown manually.
		*/
		if (index >= 0 && index < ARRAY_SIZE) {
			std::cout << "The current value at index " << index
				<< " is: " << theArray[index] << std::endl;
			std::cout << "Enter a numerical value to add to that value." << std::endl;

			int modifyValue;
			std::cin >> modifyValue;
			theArray[index] += modifyValue;

			std::cout << "The current value at index " << index
				<< " after adding " << modifyValue << " to is: " << theArray[index]
				<< std::endl;

			didModify = true;
		}
		else {
			throw(index);
		}
	}
	catch (int badIndex) {
		std::cerr << "Out_of_range exception thrown for index "
			<< index << std::endl << std::endl;
	}

	return didModify;
}

bool intArray::addNewInt(int newInt) {
	bool didAdd = false;
	try {
		if (curIntCount + 1 < ARRAY_SIZE) {
			theArray[curIntCount] = newInt;
			curIntCount++;
			didAdd = true;
		}
		else {
			throw(newInt);
		}
	}
	catch (...) {
		std::cerr << "The array is full. Cannot add int."<< std::endl;
	}

	return didAdd;
}

bool intArray::removeValue(int index) {
	bool didRemove = false;
	
	if (index >= 0 && index < ARRAY_SIZE) {
		//Loop handles everything except the last element
		for (int i = index; i < ARRAY_SIZE - 1; i++) {
			theArray[i] = theArray[i + 1];
		}
		//The last element will always be 0 after removal
		theArray[ARRAY_SIZE - 1] = 0; 
		curIntCount--;

		didRemove = true;
	}
	
	return didRemove;
}