#include <stdio.h>
#include <string.h>

#define MAX(x,y) ((x)>(y)?(x):(y))
#define IS_EVEN(n) ((n)%2==0)

//检测字符c是否在'a'与'z'之间，在：返回对应的大写，不在：原值返回
#define TOUPPER(c) ('a'<=(c)&&(c)<='z'?(c)-'a'+'A':(c))

#define PRINT_INT(n) printf(#n " = %d\n",n)

#define MK_ID(n) i##n

int fact(int n) {
	if (n <= 1)
		return 1;
	else
		return n * fact(n - 1);
}

int main() {
	char *s = "hello";
	return 0;
}
