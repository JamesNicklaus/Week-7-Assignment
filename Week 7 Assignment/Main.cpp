//BCS340 - Intro to Algorithms
//Week 07 Group assignment
//James Nicklaus, David Ardeljan, Samantha Broda

#include <iostream>
#include <cstdlib>
#include <time.h>
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


void copyArray(int *copiedArray, int *originalArray) {

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

void heapify(int arr[], int size, int root) {

	int largest = root; 
	int left = 2 * root + 1; 
	int right = 2 * root + 2; 

	if (left < size && arr[left] > arr[largest]) {

		largest = left;
	}

	if (right < size && arr[right] > arr[largest]) {

		largest = right;
	}

	if (largest != root) {

		swapElements(&arr[root], &arr[largest]);
		heapify(arr, size, largest);
	}
}

void quickSort(int arr[], int low, int high) {

	if (low < high){

		int index = partition(arr, low, high);

		quickSort(arr, low, index - 1);
		quickSort(arr, index + 1, high);
	}

}

void bubbleSort(int arr[], int n)
{
	int i, j;
	bool isSwap;

	for (i = 0; i < n - 1; i++)
	{
		isSwap = false;
		for (j = 0; j < n - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				swapElements(&arr[j], &arr[j + 1]);
				isSwap = true;
			}
		}

		if (isSwap == false)
		{
			break;
		}
	}
}

void merge(int arr[], int const l, int const m, int const r)
{
	auto const n1 = m - l + 1;
	auto const n2 = r - m;

	auto *L = new int[n1], *R = new int[n2];

	for (auto i = 0; i < n1; i++)
	{
		L[i] = arr[l + i];
	}
	for (auto j = 0; j < n2; j++)
	{
		R[j] = arr[m + 1 + j];
	}

	auto i = 0, j = 0;
	int k = l;

	while (i < n1 && j < n2) 
	{
		if (L[i] <= R[j]) 
		{
			arr[k] = L[i];
			i++;
		}
		else 
		{
			arr[k] = R[j];
			j++;
		}
		k++;
	}

	while (i < n1) 
	{
		arr[k] = L[i];
		i++;
		k++;
	}

	while (j < n2) 
	{
		arr[k] = R[j];
		j++;
		k++;
	}

}

void mergeSort(int array[], int const l, int const r)
{
	if (l >= r)
	{
		return;
	}

	auto m = l + (r - l) / 2;

	mergeSort(array, l, m);

	mergeSort(array, m + 1, r);

	merge(array, l, m, r);
}

void selectionSort(int arr[], int size) {

	int min , outer, inner;
	for (outer = 0; outer < size - 1; outer++) {
		min = outer;
		for (inner = outer + 1; inner < size; inner++) {
			if (arr[inner] < arr[min]) {
				min = inner;
			}
		}
		swapElements(&arr[outer], &arr[min]);
	}
}

void insertionSort(int arr[], int size) {

	for (int i = 1; i < size; ++i) {
		int cElement = i;
		
		while (cElement > 0 && arr[cElement] < arr[cElement - 1])
		{
			swapElements(&arr[cElement], &arr[cElement - 1]);
			--cElement;
		}
	}
}

void heapSort(int arr[], int size) {

	for (int i = size / 2 - 1; i >= 0; i--) {

		heapify(arr, size, i);
	}

	for (int i = size - 1; i > 0; i--) {

		swap(arr[0], arr[i]);
		heapify(arr, i, 0);
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

		cout << "\nPlease select a sort from the menu below:" << endl;
		cout << "=========================================" << endl;
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
		case 1: //Selection Sort
		{
			
			copyArray(arrayCopy, array);

			const clock_t bc = clock();
			for (int i = 0; i < 100000000; i++);

			selectionSort(arrayCopy, 10000);

			cout << float(clock() - bc) / CLOCKS_PER_SEC << " sec" << endl;

			printArray(arrayCopy);

			break;
		}
		case 2: //Insertion Sort
		{
			
			copyArray(arrayCopy, array);

			const clock_t bc = clock();
			for (int i = 0; i < 100000000; i++);

			insertionSort(arrayCopy, 10000);

			cout << float(clock() - bc) / CLOCKS_PER_SEC << " sec" << endl;

			printArray(arrayCopy);

			break;
		}
		case 3: // Bubble Sort
		{

			copyArray(arrayCopy, array);

			const clock_t bc = clock();
			for (int i = 0; i < 100000000; i++);

			bubbleSort(arrayCopy, 10000);

			cout << float(clock() - bc) / CLOCKS_PER_SEC << " sec" << endl;

			printArray(arrayCopy);

			break;
		}
		case 4: // Merge Sort
		{

			copyArray(arrayCopy, array);

			const clock_t bc = clock();
			for (int i = 0; i < 100000000; i++);


			mergeSort(arrayCopy, 0, 10000 - 1);

			cout << float(clock() - bc) / CLOCKS_PER_SEC << " sec" << endl;

			printArray(arrayCopy);

			break;
        }
		case 5: { //Quick Sort

			copyArray(arrayCopy, array);

			const clock_t bc = clock();
			for (int i = 0; i < 100000000; i++);

			quickSort(arrayCopy, 0, 10000 - 1);

			cout << float(clock() - bc) / CLOCKS_PER_SEC << " sec" << endl;

			printArray(arrayCopy);

			break;
		}
		case 6: { // Heap Sort

			copyArray(arrayCopy, array);

			const clock_t bc = clock();
			for (int i = 0; i < 100000000; i++);

			heapSort(arrayCopy, 10000);

			cout << float(clock() - bc) / CLOCKS_PER_SEC << " sec" << endl;

			printArray(arrayCopy);

			break;
		}
		case 7:
			menu = false;
			break;
		default:
			cout << "That is not a valid choice, please try again." << endl;
		}
	}

	delete[] array;
	delete[] arrayCopy;

	return 0;
}