//BCS340 - Intro to Algorithms
//Week 07 Group assignment
//James Nicklaus, David Ardeljan, Samantha Broda

#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;

void randomizeArray(int *arr) {

	for (int i = 0; i < 10000; i++) {
		arr[i] = rand() % 100 + 1;
	}
}

void printArray(int *arr) {

	for (int i = 0; i < 50; i++) {
		cout << arr[i] << ", ";
	}
}

int main() {

	//Initialize array on heap instead of stack
	int *array = new int[10000];
	bool menu = true;
	int selection = 0;

	randomizeArray(array);

	while (menu == true) {

		cout << "Please select a sort from the menu below:" << endl;
		cout << "1. Selection Sort" << endl;
		cout << "2. Insertion Sort" << endl;
		cout << "3. Bubble Sort" << endl;
		cout << "4. Merge Sort" << endl;
		cout << "5. Quick Sort" << endl;
		cout << "6. Heap Sort" << endl;
		cout << "7. Exit Menu\n" << endl;
		cout << "Selection (1-7): ";

		cin >> selection;

		switch (selection) {
		case 1:
			//Run Selection Sort
			break;
		case 2:
			//Run Insertion Sort
			break;
		case 3:
			//Run Bubble Sort
			break;
		case 4:
			//Run Merge Sort
			break;
		case 5:
			//Run Quick Sort
			break;
		case 6:
			//Run Heap Sort
			break;
		case 7:
			menu = false;
			break;
		default:
			cout << "That is not a valid choice, please try again.\n" << endl;
		}
	}

	//Insert sort functions here. Randomzie the array again in main after sorting.

	//printArray(array);

	delete[] array;

	return 0;
}