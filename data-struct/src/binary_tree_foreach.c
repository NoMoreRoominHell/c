/**
 * 二叉树
 *
 * 三种遍历方式的完整代码（递归实现）
 */
#include <stdio.h>
#include <string.h>
#include <malloc.h>

#define TElemType int

//构造结点的结构体
typedef struct BiTNode {
	TElemType data; //数据域
	struct BiTNode *lchild, *rchild; //左右孩子指针
} BiTNode, *BiTree;

//初始化树的函数
static void CreateBiTree(BiTree *T) {
	*T = (BiTNode*) malloc(sizeof(BiTNode));
	(*T)->data = 1;
	(*T)->lchild = (BiTNode*) malloc(sizeof(BiTNode));
	(*T)->rchild = (BiTNode*) malloc(sizeof(BiTNode));

	(*T)->lchild->data = 2;
	(*T)->lchild->lchild = (BiTNode*) malloc(sizeof(BiTNode));
	(*T)->lchild->rchild = (BiTNode*) malloc(sizeof(BiTNode));
	(*T)->lchild->rchild->data = 5;
	(*T)->lchild->rchild->lchild = NULL;
	(*T)->lchild->rchild->rchild = NULL;
	(*T)->rchild->data = 3;
	(*T)->rchild->lchild = (BiTNode*) malloc(sizeof(BiTNode));
	(*T)->rchild->lchild->data = 6;
	(*T)->rchild->lchild->lchild = NULL;
	(*T)->rchild->lchild->rchild = NULL;
	(*T)->rchild->rchild = (BiTNode*) malloc(sizeof(BiTNode));
	(*T)->rchild->rchild->data = 7;
	(*T)->rchild->rchild->lchild = NULL;
	(*T)->rchild->rchild->rchild = NULL;
	(*T)->lchild->lchild->data = 4;
	(*T)->lchild->lchild->lchild = NULL;
	(*T)->lchild->lchild->rchild = NULL;
}

//模拟操作结点元素的函数，输出结点本身的数值
static void displayElem(BiTNode* elem) {
	printf("%d ", elem->data);
}

//先序遍历
static void PreOrderTraverse(BiTree T) {
	if (T) {
		displayElem(T); //调用操作结点数据的函数方法
		PreOrderTraverse(T->lchild); //访问该结点的左孩子
		PreOrderTraverse(T->rchild); //访问该结点的右孩子
	}
	//如果结点为空，返回上一层
	return;
}

//中序遍历
void INOrderTraverse(BiTree T) {
	if (T) {
		INOrderTraverse(T->lchild); //遍历左孩子
		displayElem(T); //调用操作结点数据的函数方法
		INOrderTraverse(T->rchild); //遍历右孩子
	}
	//如果结点为空，返回上一层
	return;
}

//后序遍历
static void PostOrderTraverse(BiTree T) {
	if (T) {
		PostOrderTraverse(T->lchild); //遍历左孩子
		PostOrderTraverse(T->rchild); //遍历右孩子
		displayElem(T); //调用操作结点数据的函数方法
	}
	//如果结点为空，返回上一层
	return;
}

int main_binary_tree_foreach() {
	BiTree Tree;
	CreateBiTree(&Tree);
	printf("前序遍历: \n");
	PreOrderTraverse(Tree);
	printf("\n中序遍历算法: \n");
	INOrderTraverse(Tree);
	printf("\n后序遍历: \n");
	PostOrderTraverse(Tree);
	return 0;
}
