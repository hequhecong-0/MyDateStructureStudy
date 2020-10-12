// 不带头结点的单向链表的增删改查
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>		//引入bool类型头文件
typedef int ElemType;
typedef struct node
{
	ElemType element;		  // 节点的数据域
	struct node * link;		 // 节点的指针域
}Node;
typedef struct SingleList
{
	Node *first;
	int n;
}SingleList;
bool Init(SingleList *L)			//  初始化链表
{
	L->first = NULL;
	L->n = 0;
	return true;
}
bool Find(SingleList L, int i, ElemType* x)	// 查找i下标对应的元素值, 存入x内
{
	Node *p=NULL;
	if (i<0 || i>L.n - 1)				// 检查下标是否非法
		return false;
	p = L.first;
	for (int j = 0; j < i;j++)
		p = p->link;					//  定位到i坐标下的元素
	*x = p->element;				// 将i对应坐标的值存入x内
	return true;
}
bool Insert(SingleList *L,int i, ElemType x)		// 实现链表的插入操作,i是插入的位置,x是插入的元素值
{
	Node *p=NULL;
	p = L->first;
	if (i<0 || i>L->n)			// 检查下标是否非法	
		return 0;
	for (int j = 0; j < i-1; j++)			//	 定位到i-1坐标下的元素	
		p = p->link;
	Node *q= (Node*)malloc(sizeof(Node));	// 额外申请一个节点的空间, 用于存放插入的元素
	q->element = x;											
	if (i > 0)
	{
		q->link = p->link;			// 假如插入的位置不是在头节点处,那么将p节点的下一个节点的地址给q节点的指针域存储
												// 再把q 节点的地址存储在p节点的指针域中存储实现了节点插入
											
		p->link = q;
	}
	else                                // 假如插入的位置是头结点, 那么将first指针中记录的头结点给q节点的指针域存储
										  // 再将新的头结点q的地址用first存储
	{
		q->link = L->first;
		L->first = q;
	}
	L->n++;
	return true;
}
bool Delete(SingleList *L, int i)		//  删除i位置对应的元素
{
	Node *p=NULL;						   // 定义p,q两个节点指针用于删除的定位
	Node *q=NULL;
	if (!L->n)
		return false;
	if (i<0 || i>L->n - 1)			
		return false;
	p = L->first;
	q = L->first;
	for (int j = 0; j < i - 1; j++)		// q指向待插入位置的前一个	
		q = q->link;
	if (i ==0)								    // 如果删除的是位置0, 将头节点下一个节点的地址存入first指针中作为新的头结点
		L->first = L->first->link;		
	else 
	{
		p = q->link;					// 如果删除的不是头结点, p记录待删除的节点的地址
		q->link = p->link;		// 将待删除的节点的下一个节点的地址存入q节点的指针域
	}
	free(p);							// 释放删除节点的内存空间
	L->n--;							// 链表长度减1
	return false;
}
bool Output(SingleList *L)			// 遍历输出所有的元素
{
	Node *p=NULL;
	if (!L->n)
		return false;
	p = L->first;
	while (p)							// 只要p存的不是NULL, while就一直执行
	{
		printf("%d  ", p->element);
		p = p->link;					// p向后移动
	}
	printf("\n");
	return true;
}
void Destroy(SingleList *L)			// 撤销链表释放空间
{
	Node *p = L->first;			
	Node *q = NULL;
	while (p)
	{
		q = p->link;		// 用指针q记录p下一个节点的地址
		free(p);				// 释放p 的空间
		p = q;				// 将q中存的p的下一个节点的地址给p,实现p的向后移动
	}

}
int main()
{
	SingleList list1;
	Init(&list1);
	for (int i = 0; i < 9; i++)
		Insert(&list1, i, i+2);
	Output(&list1);
	ElemType *x;			// 定义x指针用于存储, 查找元素的值
	printf("\n请输入查找元素的位置p(p取0-%d):    \n",list1.n-1);
	int findALocation=0;
	scanf_s("%d",&findALocation );
	Find(list1, findALocation, &x);
	printf("对应下标的值为: %d\n", x);

	printf("\n请输入删除元素的位置p(p取0-%d):    \n", list1.n - 1);
	int deleteLocation = 0;
	scanf_s("%d", &deleteLocation);
	Delete(&list1, deleteLocation);
	printf("删除该元素后链表为: \n");
	Output(&list1);
	Destroy(&list1);
	return 0;
}