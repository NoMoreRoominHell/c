/**
 * 二叉链表
 *
 * 单支树
 */

#include <stdio.h>
#include <stdlib.h>

#define TElemType int

typedef struct BiTNode {
	TElemType data; //数据域
	struct BiTNode *lchild, *rchild; //左右孩子指针
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

int main_binary_tree_linked() {
	BiTree Tree;
	CreateBiTree(&Tree);
	printf("%d", Tree->lchild->lchild->data);
	return 0;
}
