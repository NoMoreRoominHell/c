#ifndef MYSTRUCT_H
#define MYSTRUCT_H

struct teacher {
	int no;
	char name[8];
	int age;
};

//共用体
union tag {
	int no1;
	char no2[2];
};

#endif
