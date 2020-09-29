// 顺序表的实现
#include<stdio.h>
#include <stdlib.h>
#define ERROR 0
#define  OK 1
typedef int Status;

typedef int ElemType;		
typedef struct seqList
{
	int n;						// 顺序表的元素个数
	int maxLength;		// 顺序表的最大容量
	ElemType *element;	// 取整型作为顺序表存储的数据类型
} SeqList;

Status Init(SeqList *L, int mSize)
{
	L->maxLength = mSize;			// 初始化空间容量
	L->n = 0;									// 初始化值的个数	
	L->element = (ElemType *)malloc(sizeof(ElemType)*mSize);		// 动态生成一维数组
	if (!L->element)
		return ERROR;			// 动态数组创建失败,则返回0
	return OK;					// 创建成功则返回1
}
Status Find(SeqList L, int i, ElemType *x)		// 链表的查找
{
	if (i<0 || i>L.n - 1)
		return ERROR;
	*x = L.element[i];									// 通过指针参数取出i下标对应的值
	return OK;
}
Status Insert(SeqList *L, int i, ElemType x)	// 链表的插入
{
	int j;
	if (i < -1 || i>L->n - 1)
		return ERROR;
	if (L->n == L->maxLength)
		return ERROR;
	for (j = L->n - 1; j > i; j--)
		L->element[j + 1] = L->element[j];		
	L->element[i + 1] = x;
	L->n = L->n + 1;
	return OK;
}

Status Delete(SeqList *L, int i)		// 链表的删除
{
	int j;
	if (i<0 || i>L->n - 1)
		return ERROR;
	if (!L->n)				// 判断是否为空, 空则返回0
		return ERROR;
	for (j = i + 1; j < L->n; j++)
		L->element[j - 1] = L->element[j];
	L->n--;					// 删除完, 元素个数减1
	return OK;
}
Status Output(SeqList *L)	// 顺序表的输出
{
	int i;
	if (L->n == 0)
		return ERROR;
	for (i = 0; i <= L->n - 1; i++)
		printf("%d", L->element[i]);
	printf("\n");
	return OK;
}
void Destory(SeqList *L)			// 空间的回收释放
{
	L->n = 0;
	L->maxLength = 0;
	free(L->element);
}
int main()
{	
	int i;
	SeqList list;
	ElemType *x;		// 方便查找取出值
	Init(&list, 10);
	for (i = 0; i < 10; i++)
		Insert(&list, i - 1, i);
	Output(&list);
	Delete(&list, 0);
	Delete(&list, 4);
	Output(&list);
	Find(list, 4, &x);
	printf("%d", x);	
	Destory(&list);
	return 0;
}