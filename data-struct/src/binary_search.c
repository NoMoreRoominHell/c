/**
 * 二分查找
 */

#include <stdio.h>
#include <stdlib.h>

#define keyType int

typedef struct {
	keyType key;
} ElemType;

typedef struct {
	ElemType *elem;
	int length;
} SSTable;

static void Create(SSTable **st, int length) {
	(*st) = (SSTable*) malloc(sizeof(SSTable));
	(*st)->elem = (ElemType*) malloc(sizeof(ElemType) * (length + 1));
	(*st)->length = length;

	printf("输入表中的数据元素：\n");
	fflush(stdout);
	for (int i = 1; i <= length; i++) {
		scanf("%d", &((*st)->elem[i].key));
	}

}

int Search_Bin(SSTable *ST, keyType key) {
	int low = 1; //初始状态 low 指针指向第一个关键字
	int high = ST->length; //high 指向最后一个关键字
	int mid;
	while (low <= high) {
		mid = (low + high) / 2; //int 本身为整形，所以，mid 每次为取整的整数
		if (ST->elem[mid].key == key) { //如果 mid 指向的同要查找的相等，返回 mid 所指向的位置
			return mid;
		} else if (ST->elem[mid].key > key) { //如果mid指向的关键字较大，则更新 high 指针的位置
			high = mid - 1;
		} else { //反之，则更新 low 指针的位置
			low = mid + 1;
		}
	}
	return 0;
}

int main() {
	int length = 11;
	SSTable *st = NULL;
	Create(&st, length);

	printf("输入的数组为:");
	for (int i = 1; i <= length; i++) {
		printf("%d ", st->elem[i].key);
	}

	printf("\n请输入查找数据的关键字：\n");
	fflush(stdout);
	int key;
	scanf("%d", &key);
	int location = Search_Bin(st, key);
	if (location == 0) {
		printf("查找表中无该元素");
	} else {
		printf("数据在查找表中的位置为：%d", location);
	}
	free(st->elem);
	free(st);
	return 0;
}
