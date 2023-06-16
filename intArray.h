#ifndef INTARRAY_H_
#define INTARRAY_H_

class intArray {
private:
	//Array size is arbitray, needs to be at least 100. Larger to allow ints to add.
	#define ARRAY_SIZE 150
	int theArray[ARRAY_SIZE] = {0};
	int curIntCount;

public:

	//Default Constructor
	intArray();

	/*
	* Displays the information in the array to the console.
	* 10 ints per row. Does not display "empty" trailing 0's in array.
	*/
	void displayArray();

	/*
	* Reads data from a text file containing ints and puts it into an array
	*/
	void readFileData();

	/*
	* Returns the index of the first occurance the inputNum in the array.
	* Returns -1 if the number is not found.
	*/
	int indexLocationOfNum(int inputNum);

	/*
	* Attempts to modify the value at a given index.
	* Returns true if index is valid, false otherwise.
	*/
	bool modifyValue(int index);

	/*
	* Adds a new int at the end of the array.
	* Returns true if value was added, false if not(Array full)
	*/
	bool addNewInt(int newInt);

	/*
	* Removes the value at a given index in the array.
	* Shifts all procedding values in array one to the left.
	* Returns true if the index was valid and the number removed, false if not.
	*/
	bool removeValue(int index);
};

#endif // !INTARRAY_H_

