#include <stdio.h>

int n = 5;

/**
 *
 */
int fact1() {
	int i, j, temp, s;
	s = 0;
	for (i = 1; i <= n; i++) {
		temp = 1;
		for (j = 1; j <= i; j++)
			temp = temp * j;
		s = s + temp;
	}
	return s;
}

/**
 *
 */
int fact2() {
	int i, temp, s;
	s = 0;
	temp = 1;
	for (i = 1; i <= n; i++) {
		temp = temp * i;
		s = s + temp;
	}
	return s;
}

int main() {
	printf("fact1:%d\n", fact1());
	printf("fact2:%d\n", fact2());
	return 0;
}
