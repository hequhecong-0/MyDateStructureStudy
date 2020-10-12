// 带头结点的单链表增删改查
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>		//引入bool类型头文件
typedef int ElemType;
typedef struct node
{
	ElemType element;	  // 节点的数据域
	struct node *link;		 // 节点的指针域
}Node;
typedef struct headerList
{
	Node *first;
	int n;				// n用于记录链表的长度
}HeaderList;
bool Init(HeaderList *h)
{
	h->first = (Node *)malloc(sizeof(Node));	// 申请头结点,并用头指针存储
	if (!h->first)
		return false;
	h->first->link = NULL;							//头结点的指针域指向0
	h->n = 0;													// 头结点的数据域存0
	return true;
}
bool Insert(HeaderList *h, int i, ElemType x) // 实现链表的插入操作,i是插入的位置,x是插入的元素值
{
	Node *p=NULL;
	if (i<0 || i>h->n)					// 检查下标是否非法	
		return false;
	p = h->first;
	for (int j=0;j<=i-1;j++)		//  定位到i-1坐标下的元素	
		p = p->link;
	Node *q = (Node *)malloc(sizeof(Node));		// 创建q节点用于存储插入的数据
	q->element = x;		 //q节点数据域存储插入的数据x	
	q->link = p->link;	 // 将p节点的下一个节点的地址给q节点的指针域存储
	p->link= q;				// 再把q 节点的地址存储在p节点的指针域中存储实现了节点插入
	h->n++;					// 链表的长度加1
}
bool Delete(HeaderList *h, int i)		// 删除i位置对应的元素
{
	Node *p = NULL;						 // 定义p,q两个节点指针用于删除的定位
	Node *q = NULL;
	if (!h->n)
		return false;
	if (i<0 || i>h->n - 1)
		return false;
	q = h->first;
	for (int j = 0; j <= i - 1; j++)		// q指向待插入位置的前一个	
		q = q->link;								
	p = q->link;							// p记录待删除的节点的地址
	q->link = p->link;				// 将待删除的节点的下一个节点的地址存入q节点的指针域
	free(p);									// 释放删除节点的内存空间
	h->n--;									// 链表长度减1
	return true;
}
bool Find(HeaderList h, int i, ElemType *x)		// 查找i下标对应的元素值, 存入x内
{
	Node *p = NULL;
	if (i<0 || i>h.n - 1)				// 检查下标是否非法
		return false;
	p = h.first;
	for (int j = 0; j <= i; j++)
		p = p->link;					//  定位到i坐标下的元素
	*x = p->element;				// 将i对应坐标的值存入x内
	return true;
}
bool Output(HeaderList h)		// 遍历输出所有的元素
{
	Node *p = NULL;
	if (!h.first)
		return false;
	p = h.first->link;
	while (p)							// 只要p存的不是NULL, while就一直执行
	{
		printf("%d  ", p->element);
		p = p->link;					// p向后移动
	}
	printf("\n");
	return true;
}
void Destroy(HeaderList *h)			// 撤销链表释放空间
{
	Node *p = h->first;			
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
		HeaderList list1;
		Init(&list1);
		for (int i = 0; i < 9; i++)
			Insert(&list1, i, i+2);
		Output(list1);
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
		Output(list1);
		Destroy(&list1);


	return 0;
}