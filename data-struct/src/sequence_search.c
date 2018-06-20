/**
 * 顺序查找
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

void Create(SSTable **st, int length) {
	(*st) = (SSTable*) malloc(sizeof(SSTable));
	(*st)->elem = (ElemType*) malloc(sizeof(ElemType) * (length + 1));
	(*st)->length = length;

	for (int i = 1; i <= length; i++) {
		scanf("%d", &((*st)->elem[i].key));
	}

}

int Search_seq(SSTable *st, keyType key) {
	st->elem[0].key = key;
	int i = st->length;
	while (st->elem[i].key != key) {
		i--;
	}
	return i;
}

int main_sequence_search() {
	int length = 6;

	SSTable *st = NULL;
	printf("输入数组\n");
	fflush(stdout);
	Create(&st, length);
	printf("输入的数组为:");
	for (int i = 1; i <= length; i++) {
		printf("%d ", st->elem[i].key);
	}

	int key;
	printf("\n输入查找key\n");
	fflush(stdout);
	scanf("%d", &key);
	int location = Search_seq(st, key);
	if (location == 0) {
		printf("查找失败");
	} else {
		printf("数据在查找表中的位置为：%d", location);
	}

	free(st->elem);
	free(st);

	return 0;
}
