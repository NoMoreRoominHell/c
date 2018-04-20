/**
 * T(n):语句频度或者时间频度
 *
 * f(n):辅助函数,当n趋近于无穷大时，T(n)/f(n)的极限值为不等于零的常数，则称f(n)是T(n)的同数量级函数.记作T(n)=O(f(n))
 *
 * O(f(n))为算法的渐进时间复杂度，简称时间复杂度
 *
 * "O"表示量级 (order)
 *
 * 常见的时间复杂度:常数阶O(1)<对数阶O(log2n)<线性阶O(n),<线性对数阶O(nlog2n)<平方阶O(n^2)<方阶O(n3)<k次方阶O(n^k)<指数阶O(2^n)<O(n!)<O(n^n)
 */

#include <stdio.h>

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

int main1() {
	printf("fact1:%d\n", fact1());
	printf("fact2:%d\n", fact2());
	return 0;
}
