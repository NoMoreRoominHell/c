#include <stdio.h>

void mergeSort(int data[], int first, int last) {
	int mid = 0;
	if (first < last) {
		mid = (first + last) / 2;
		mergeSort(data, first, mid);
		mergeSort(data, mid + 1, last);

	}
}

void merge(int data[], int low, int mid, int high) {
	int *temp = (int *) malloc((high - low + 1) * sizeof(int));
	int left_low = low;
	int left_high = mid;
	int right_low = mid + 1;
	int right_high = high;
	int i, k;
	for (k = 0; left_low <= left_high && right_low <= right_high; k++) {
		if (data[left_low] <= data[right_low]) {
			temp[k] = data[left_low++];
		} else {
			temp[k] = data[right_low++];
		}
	}
}

int mian() {
	int data[10] = { 5, 9, 3, 4, 1, 6, 7, 8, 2, 10 };
	return 0;
}
