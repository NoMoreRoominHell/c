/**
 * 二叉链表
 */

#include <stdio.h>
#include <stdlib.h>

#define TElemType int

typedef struct BiTNode {
	TElemType data; //数据域
	struct BiTNode *lchild; //左子
	struct BiTNode *rchild; //右子
} BiTNode, *BiTree;

static void CreateBiTree(BiTree *T) {
	*T = (BiTNode*) malloc(sizeof(BiTNode));
	(*T)->data = 1;
	(*T)->lchild = (BiTNode*) malloc(sizeof(BiTNode));
	(*T)->rchild = NULL;
	(*T)->lchild->data = 2;
	(*T)->lchild->lchild = (BiTNode*) malloc(sizeof(BiTNode));
	(*T)->lchild->rchild = NULL;
	(*T)->lchild->lchild->data = 3;
	(*T)->lchild->lchild->lchild = NULL;
	(*T)->lchild->lchild->rchild = NULL;
}

//main_binary_tree_linked
int main_binary_tree_linked() {
	BiTree Tree;
	CreateBiTree(&Tree);
	printf("%d", Tree->data);
	printf("%d", Tree->lchild->data);
	printf("%d", Tree->lchild->lchild->data);
	free(Tree->lchild->lchild);
	free(Tree->lchild);
	free(Tree);
	return 0;
}
