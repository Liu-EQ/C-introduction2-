#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<iostream>
#include<iomanip>
using namespace std;
typedef struct Link {
	int  elem;
	struct Link *next;
}link;
//头插法创建单链表
//无头结点链表的头插法实现函数
link * creatLink(int * arc, int length) {
	int i;
	//最初状态下，头指针 H 没有任何结点，所以，插入第一个元素，就相当于是创建结点 H
	//link * H = (link*)malloc(sizeof(link));
	link * H = new link();
	H->elem = arc[0];
	H->next = NULL;
	//如果采用头插法插入超过 1 个元素，则可添加到第一个结点 H 之前
	for (i = 1; i < length; i++) {
		//link * a = (link*)malloc(sizeof(link));
		link *a = new link();
		a->elem = arc[i];
		//插入元素时，首先将插入位置后的链表链接到新结点上
		a->next = H;
		//然后再链接头指针 H
		H = a;
	}
	return H;
}
//有头结点链表的头插法实现函数
link * HcreatLink(int * arc, int length) {
	int i;
	//创建头结点 H，其链表的头指针也是 H
	//link * H = (link*)malloc(sizeof(link));
	link * H = new  link();
	H->elem = 0;
	H->next = NULL;
	//采用头插法创建链表
	for (i = 0; i < length; i++) {
		//link * a = (link*)malloc(sizeof(link));
		link *a = new link();
		a->elem = arc[i];
		//首先将插入位置之后的链表链接到新结点 a 上
		a->next = H->next;
		//将新结点 a 插入到头结点之后的位置
		H->next = a;
	}
	return H;
}

//尾插法创建单链表
//此处传入双重指针，是因为我们需要修改head的值，而head是一重指针
//在下方修改的时候仍然使用(*head)也就是一重指针
/**
 * @param head 头指针的地址
* @param n 创建有n个结点的链表
*/
void TcreatLink(link **head, int n) 
{
	    link *node=NULL, *tail=NULL;//node指向新加入链表的节点，tail恒定指向尾节点
	    int data;
		while (n--)
		{
			//scanf("%d", &data);
			cin >> data;
			//node = (linkedList*)malloc(sizeof(linkedList));//动态分配内存
			node = new link();
			node->elem = data;
			node->next = NULL;
			if ((*head)->next == NULL)//头节点之后并无其他节点
				(*head)->next = node;
			else//头节点之后还有其他节点
				tail->next = node;
			tail = node;

		}
}

//单链表的增删改查
//单链表增加元素
//这个函数实际上我们并不需要改变头指针的值，而是相当于创建链表时添加数据过程
void insertLink(link *head, int i, int data) 
{
	    link *node = head, *tail=NULL;//node用来查找要插入的位置（从第一个节点开始），tail用于指向待插入的节点
	    int j = 0;//默认链表从0开始计数（即头节点之后的第一个节点序号为0）
				//j的初试赋值决定了单链表从哪个数字开始计数（即头节点之后的第一个节点的序号为多少）
				//因为在一开始的赋值中，node指向头节点可以视为序号0，所以最初的j赋值应该和node保持同步
							//若初始j赋值为-1，则代表头节点不计入节点序列中，头节点之后的第一个节点才开始计数，且从0开始
	    //循环判断i是否合理，若合理，则跳出循环后node指向第i-1个结点，且j == i-1
		    while (node->next != NULL && j < i - 1) 
				//因为一开始node指向头节点，所以node最初肯定不为null，直接判断第一节节点即可
			{
		        node = node->next;
		        j++;
		
	}
	    if (j != i - 1) {
		       // printf("插入位置有误！");
			cout << "插入位置有误！" << endl;
		        return;
		
	}
	    //上述步骤的第3，4步
		    //tail = (linkedList *)malloc(sizeof(linkedList));
		tail = new link();
	    tail->elem = data;
	    tail->next = node->next;//原本的第i个节点及其后面的节点都链到插入节点之后
	    node->next = tail;//tail称为了第i个节点
	
}
//删除第i个元素,被删除的值由data带回，无需返回值
//主体思路和插入元素类似
void deleteLink(link*head, int i, int* data) {//删除第i个位置的元素，将元素值赋值给data
	    link *p = head, *s=NULL;//p用于查找待删除元素的位置（从第一届结点开始查找），s用于指向待删除节点（进行返回值，并将前后元素进行连接）
	    int j = -1;
	    while (p->next != NULL && p->next->next != NULL && j < i - 1) //判断删除位置是否合法
								//之所以要判断p->next,p->next->next是因为，前一个指向待删除结点的前一个节点，后一个指向待删除节点
		{
		        p = p->next;
		        j++;
		
		}
	    if (j != i - 1) 
		{
		        printf("删除位置错误！");
		        return;
		
		}
	    s = p->next;//s此时指向待删除元素
	 * data = s->elem;//返回待删除元素的值
	    p->next = p->next->next;//后一个元素链到前一个元素的指针
	   // free(s);
		delete s;//释放带删除元素的内存
}
//单链表的更改函数
void changeLink(link * head,int i,int data) 
{
	link *node = head;//只需要定义一个指针，用于查找待修改节点即可，不需要另一个节点辅助
	int j = -1;//违法输入判断
	if (node->next!=NULL&&j<i-1)
	{
		node = node->next;
		j++;
	}
	if (j!=i-1)
	{
		cout << "输入值不合法！" << endl;
		return;
	}
	node->elem = data;
	return;
};
//链表的输出函数
void display(link *p) {
	while (p) {
		//printf("%d ", p->elem);
		cout << p->elem << "  ";
		p = p->next;
	}
	//printf("\n");
	cout << endl;
}
//单链表的查找函数
int selectElem(link * p, int elem) {//传入参数为单链表的头节点，所要查找的元素的值
	link * t = p;//定义一个栈区变量，用于临时遍历单链表
	int i = 1;//遍历序号
	while (t->next) {//因为由头节点，所以从t→next开始，若有下一个节点，则进行比较
		t = t->next;//指向第一个节点
		if (t->elem == elem) {//数据元素值对比
			return i;//返回元素下标（因为从1开始，所以不需要进行+1）
		}
		i++;//不等，则比较后续元素
	}
	return -1;//全部遍历结束，仍未找到，则返回假
}
//计算单链表长度
//此处因为head本来就是指针，所以传入指针，而非要改变head的值
int linkedListLength(link *head)
{
	   int length = 0;//计数变量
		    //循环检测有多少个结点
		    while (head->next != NULL) //带头结点，所以从头结点指向的下一个节点开始计数
			{
		        length++;
		        head = head->next;
		
			}
	    //返回链表的长度
		 return length;
}


//单链表内存空间的释放
void freelink(link * head) 
{
	//单链表的释放只能一个节点一个节点的释放，因此需要定义一个释放函数
	link *p1 = head, *p2 = NULL;//p1指向当前需要释放的节点，p2指向当前待释放节点的下一个节点
	while (p1!=NULL)//如果当前待释放节点不为空
	{
		p2=p1->next;//p2指向待释放节点的下一个节点
		delete p1;//释放当前节点
		p1 = p2;//p1后移
	}
};
int main() {
	int a[3] = { 1,2,3 };
	//采用头插法创建无头结点链表
	link * H = creatLink(a, 3);
	cout << "头插法创建无头结点链表-H：";
	display(H);
	//采用头插法创建有头结点链表
	link * head = HcreatLink(a, 3);
	cout << "头插法创建有头结点链表-head：";
	display(head);
	//链表增加元素的函数调用
	cout << "在head单链表的第二个位置，增加一个数值为8的节点：";
	insertLink(head,2,8);//在H单链表的第二个位置，增加一个数值为8的节点
	display(head);
	//链表删除元素的函数调用
	cout << "删除head链表第二个位置的元素，用m返回它的值";
	int m;
	deleteLink(head,2,&m);//删除H链表第二个位置的元素，用m返回它的值
	cout <<endl<< m<<endl;
	display(head);
	//链表更改元素的函数调用
	cout << "更改head链表第一个位置的值，改为9：";
	changeLink(head,1,9);//更改head链表第一个位置的值，改为9
	display(head);
	//查找函数的调用
	cout<<"查找函数的调用："<<selectElem(head, 2)<<endl;

	//free(H);
	//delete[] H;
	//freelink(H);
	free(head);
	freelink(H);
	//delete[] head;
	system("pause");
	return 0;
}