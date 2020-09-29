#include <iostream>
using namespace std;
typedef  int Elemtype;
class Seqlist
{
public:
	int n;
	int maxLength;
	Elemtype *element;
	Seqlist(int mSize);						// 构造函数用于初始化
	bool Find(int i, Elemtype &x);		// 查找函数
	bool Insert(int i, Elemtype x);		// 插入函数
	bool Delete(int i);							// 删除元素
	bool Output();								// 输出元素
	~Seqlist();
};
Seqlist::Seqlist(int mSize)		// 构造函数
{
	n = 0;
	maxLength = mSize;
	element = new Elemtype[mSize];
}
bool  Seqlist::Find(int i,Elemtype &x)
{
	if (i<0 || i>n - 1)
		return false;
	x = element[i];
	return true;
}
bool Seqlist::Insert(int i, Elemtype x)		// 插入函数,i为指定的位置,x为待插入的值
{
	if (i<-1 || i>n - 1)
		return false;
	if (n == maxLength)
		return false;
	for (int j = n - 1; j > i; j--)
		element[j + 1] = element[j];
	element[i + 1] = x;
	n++;
	return true;
}
bool Seqlist::Delete(int i)			// 删除指定位置i 处的元素
{
	if (i<0 || i>n - 1)
		return false;
	if (!n)
		return false;
	for (int j = i + 1; j < n; j++)
		element[j - 1] = element[j];
	n--;
	return true;
}
bool Seqlist::Output()		// 输出顺序表的所有元素
{
	if (n == 0)
		return false;
	for (int i = 0; i <= n - 1; i++)
		cout << element[i];
	cout << endl;
	return true;
}
Seqlist::~Seqlist()		// 析构函数,回收空间
{
	n = 0;
	maxLength = 0;
	delete element;
}
int main()
{
	Seqlist list(10);			// 定义顺序表的对象,初始化空间容量为10
	for (int i = 0; i < 10; i++)
		list.Insert(i - 1, i);		// 依次插入对应元素
	list.Output();
	list.Delete(0);				// 删除位置0 处的元素
	list.Delete(4);				// 删除位置4处的元素
	list.Output();
	int x = 0;
	list.Find(4, x);		// 查找位置4的元素值
	cout << x<<endl;
	return 0;
}