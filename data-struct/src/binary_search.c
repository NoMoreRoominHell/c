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

int main() {
	SSTable *st;
	st = (SSTable*) malloc(sizeof(SSTable));
	st->length = 11;
	for (int i = 1; i <= 11; i++) {
		st->elem[i].key = i;
	}
	printf("%d", st->elem[1].key);
	return 0;
}
