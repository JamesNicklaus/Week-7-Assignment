//BCS340 - Intro to Algorithms
//Week 07 Group assignment
//James Nicklaus, David Ardeljan, Samantha Broda

#include <iostream>
#include <cstdlib>
#include <chrono>
#include <algorithm>

using namespace std;

void randomizeArray(int *arr) {

	for (int i = 0; i < 10000; i++) {
		arr[i] = rand() % 100 + 1;
	}
}

void printArray(int *arr) {

	for (int i = 0; i < 49; i++) {
		cout << arr[i] << ", ";
	}
	cout << arr[50] << endl;
}

void copyArray(int* copiedArray, int* originalArray) {

	for (int i = 0; i < 10000; i++) {
		copiedArray[i] = originalArray[i];
	}
}

void swapElements(int *a, int *b) {

	int temp = *a;
	*a = *b;
	*b = temp;
}

int partition(int arr[], int low, int high) {

	int pivot = arr[high]; 
	int i = (low - 1); 

	for (int j = low; j <= high - 1; j++) {

		if (arr[j] < pivot) {

			i++; 
			swapElements(&arr[i], &arr[j]);
		}
	}
	swapElements(&arr[i + 1], &arr[high]);
	return (i + 1);
}

void quickSort(int arr[], int low, int high) {

	if (low < high){

		int index = partition(arr, low, high);

		quickSort(arr, low, index - 1);
		quickSort(arr, index + 1, high);
	}

}

int main() {

	//Initialize array on heap instead of stack
	int *array = new int[10000];
	int *arrayCopy = new int[10000];
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
		{

			copyArray(arrayCopy, array);

			auto start = chrono::high_resolution_clock::now();

			quickSort(arrayCopy, 0, 10000 - 1);

			auto stop = chrono::high_resolution_clock::now();
			auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);

			printArray(arrayCopy);
			//printArray(array);

			cout << "\nThe time to sort was " << duration.count() << " microseconds.\n" << endl;

			break;
		}
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

	

	delete[] array;
	delete[] arrayCopy;

	return 0;
}