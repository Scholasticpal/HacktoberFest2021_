#include<iostream>
using namespace std;

void swap(int* x, int* y) {
	int temp = *x;
	*x = *y;
	*y = temp;
}

void bubble_sort(int arr[],int size) {
	int i, j;
	for (i = 0; i < size - 1; i++) {

		for (j = 0; j < size - i - 1; j++) {

			if (arr[j] > arr[j + 1]) {
				swap(&arr[j], &arr[j + 1]);
			}
		}
	}
}
int main() {
	int arr[] = { 4,76,3,45,12,67,0 };
	int n = sizeof(arr) / sizeof(arr[0]);
	
	bubble_sort(arr, n);

	cout << "arr[] = { 4,76,3,45,12,67,0 }\n";
	cout << "After selection sort : \n";
	for (int i = 0; i < n; i++) {
		cout<<arr[i]<<endl;
	}
}
