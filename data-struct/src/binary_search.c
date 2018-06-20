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

int main_binary_search() {
	SSTable *st;
	st = (SSTable*) malloc(sizeof(SSTable));
	st->elem = (ElemType*) malloc(sizeof(ElemType) * 7);
	st->length = 6;

	for (int i = 1; i <= 6; i++) {
		st->elem[i].key = i;
	}
	for (int i = 1; i <= 6; i++) {
		printf("%d\n", st->elem[i].key);
	}

	free(st->elem);
	free(st);
	return 0;
}
