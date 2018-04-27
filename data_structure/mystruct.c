#include <stdio.h>

#include "mystruct.h"

#define N 3

//求一个n阶方阵的所有元素之和
void matrix() {
	int a[N][N] = { { 1, 2, 3 }, { 4, 5, 6 }, { 8, 7, 9 } };
	int sum = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			sum += a[i][j];
		}
	}
	printf("the sum is %d\n", sum);
}

//输入3个任意整数，从小到大输出
void sort() {
	int a = 5, b = 8, c = 3, t = 0;
	if (a > b) {
		t = a;
		a = b;
		b = t;
	}
	if (a > c) {
		t = a;
		a = c;
		c = t;
	}
	if (b > c) {
		t = b;
		b = c;
		c = t;
	}
	printf("%d %d %d\n", a, b, c);
}

void maxmin() {
	//TODO
}

/**
 *	数据结构导论
 */
int main() {
	printf("start ...\n");

	//matrix();
	sort();

	printf("end ...\n");
	return 0;
}
