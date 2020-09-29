// 不带头结点的单向链表的增删改查
// Adding, deleting, modifying and checking the
// singly linked list without a leading node
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>		//引入bool类型头文件   Introduce bool type header file
typedef int ElemType;
typedef struct node
{
	ElemType element;
	struct node * link;
}Node;
typedef struct SingleList
{
	Node *first;
	int n;
}SingleList;
bool Init(SingleList *L)			//  初始化链表		Initialize the linked list
{
	L->first = NULL;
	L->n = 0;
	return true;
}
bool Find(SingleList L, int i, ElemType* x)	// 查找i下标对应的元素值, 存入x内
//Find the value of the element corresponding to the i subscript and store it in x
{
	Node *p=NULL;
	if (i<0 || i>L.n - 1)				// 检查下标是否非法	 Check whether the subscript is illegal
		return false;
	p = L.first;
	for (int j = 0; j < i;j++)
		p = p->link;						 
	*x = p->element;
	return true;
}
bool Insert(SingleList *L,int i, ElemType x)		// 实现链表的插入操作,i是插入的位置
// Implement the insertion operation of the linked list, i is the position of the insertion
{
	Node *p=NULL;
	p = L->first;
	if (i<0 || i>L->n)
		return 0;
	for (int j = 0; j < i-1; j++)
		p = p->link;
	Node *q= (Node*)malloc(sizeof(Node));
	q->element = x;
	if (i > 0)
	{
		q->link = p->link;
		p->link = q;
	}
	else
	{
		q->link = L->first;
		L->first = q;
	}
	L->n++;
	return true;
}
bool Delete(SingleList *L, int i)		//  删除i位置对应的元素	Delete the element corresponding to position i
{
	Node *p=NULL;
	Node *q=NULL;
	if (!L->n)
		return false;
	if (i<0 || i>L->n - 1)
		return false;
	p = L->first;
	q = L->first;
	for (int j = 0; j < i - 1; j++)	// q指向待插入位置的前一个		q points to the previous one to be inserted
		q = q->link;
	if (i = 0)
		L->first = L->first->link;		
	else 
	{
		p = q->link;	
		q->link = p->link;
	}
	free(p);
	L->n--;
	return false;
}
bool Output(SingleList *L)			// 遍历输出所有的元素
{
	Node *p=NULL;
	if (!L->n)
		return false;
	p = L->first;
	while (p)
	{
		printf("%d  ", p->element);
		p = p->link;
	}
	return true;
}
void Destroy(SingleList *L)			// 撤销链表释放空间
{
	Node *p = L->first;
	Node *q = NULL;
	while (p)
	{
		q = p->link;
		free(p);
		p = q;
	}

}
int main()
{
	SingleList list1;
	Init(&list1);
	for (int i = 0; i < 9; i++)
		Insert(&list1, i, i);
	Output(&list1);
	ElemType *x=NULL;
	printf("\n请输入查找元素的位置p(p取0-%d):    \n",list1.n-1);
	int findALocation=0;
	scanf_s("%d",&findALocation );
	Find(list1, findALocation, &x);
	printf("%d", x);
	Destroy(&list1);
	return 0;
}