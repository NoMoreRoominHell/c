#include <stdio.h>

#include "mystruct.h"

#define N 3

int n = 5;

/**
 *	O(n^2)
 */
int fact1() {
	int i, j, temp, s;
	s = 0;
	for (i = 1; i <= n; i++) { //频度:n+1
		temp = 1;
		for (j = 1; j <= i; j++) { //频度:n*(n+1)
			temp = temp * j;
		}
		s = s + temp;
	}
	return s;
}

/**
 *	O(n)
 */
int fact2() {
	int i, temp, s;
	s = 0;
	temp = 1;
	for (i = 1; i <= n; i++) { //频度：n+1
		temp = temp * i;
		s = s + temp;
	}
	return s;
}


//int main() {
//	printf("start ...\n");
//
//	printf("end ...\n");
//	return 0;
//}
