/**
 * 数据结构导论 苏光奎 李春葆 编著
 */

#include <stdio.h>

#define N 3

//习题1
//1.数据的逻辑结构、数据的存储结构、数据的运算
//逻辑结构：指数据的逻辑关系
//存储结构：数据结构到计算机存储的映射
//数据的运输:运算指对数据元素进行加工和处理

//2.
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

//对于输入的任意n个整数，输出其中的最大和最小元素
void maxmin(int a[], int n, int *max, int *min) {
	*max = *min = a[0];
	for (int i = 0; i < n; i++) {
		if (a[i] > *max)
			*max = a[i];
		if (a[i] < *min)
			*min = a[i];
	}
}

int main123() {
	int a[] = { 1, 2, 3, 4, 5 };
	int max = 0;
	int min = 0;
	int n = 5;
	maxmin(a, n, &max, &min);
	printf("%d %d", max, min);
	return 0;
}
