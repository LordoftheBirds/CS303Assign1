#include "intArray.h"
#include <string>
#include <fstream>
#include <iostream>

int main() {

	intArray arrayA;

	std::ofstream intFile("ints.txt");

	//Fills a text file with ints 1 to 100
	for (int i = 1; i <= 10; i++) {
		for (int j = 1; j <= 10; j++) {
			intFile << j + ((i - 1) * 10) << " ";
		}
		intFile << std::endl;
	}

	arrayA.readFileData();
	arrayA.displayArray();

	//indexLocationOfNum Check
	std::cout << "Enter a number to where it appears in the array." << std::endl;
	int numToCheck;
	std::cin >> numToCheck;

	std::cout << "The index of the number " << numToCheck << " is: "
		<< arrayA.indexLocationOfNum(numToCheck)
		<< ". (-1 means the number is not in the array)"
		<< std::endl << std::endl;

	//modifyValue Check
	int indexToModify;
	
	//modifyValue can throw an exception for index values outside the ones in the array.
	//This will force the user to try again until a good index value is passed in.
	do {
		std::cout << "Enter an index to modify the int at that location "
			<< "in the array." << std::endl;
		std::cin >> indexToModify;
	} while (arrayA.modifyValue(indexToModify) == false);

	arrayA.displayArray();

	//addNewInt Check
	std::cout << "Enter a number to add to the end of the array." << std::endl;
	int numToAdd;
	std::cin >> numToAdd;

	arrayA.addNewInt(numToAdd);
	arrayA.displayArray();

	//removeValue Check
	std::cout << "Enter an index to remove the int at that location "
		<< "from the array." << std::endl;

	int indexToRemove;
	std::cin >> indexToRemove;

	bool success = arrayA.removeValue(indexToRemove);
	if (success == false) {
		std::cout << "The integer at index " << indexToRemove << " was not removed."
			<< std::endl;
	}
	arrayA.displayArray();

	return 0;
}