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

	randomizeArray(array);

	//Insert sort functions here. Randomzie the array again in main after sorting.

	printArray(array);

	delete[] array;

	return 0;
}