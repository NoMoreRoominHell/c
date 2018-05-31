#include <stdio.h>
#include <stdlib.h>

void selectionSort(int arr[], int n) {
	int i, j;
	for (i = 0; i < n - 1; i++) {
		int min = i;
		for (j = i + 1; j < n; j++) {
			if (arr[j] < arr[min]) {
				min = j;
			}
		}

		int tem = arr[i];
		arr[i] = arr[min];
		arr[min] = tem;
	}
}

void arrPrintf(int arr[], int n) {
	int i;
	for (i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
}

int main(void) {
	int arr[] = { 9, 8, 5, 17, 1, 2, 3 };
	int size = sizeof(arr) / sizeof(arr[0]);
	selectionSort(arr, size);
	arrPrintf(arr, size);
	return EXIT_SUCCESS;
}
