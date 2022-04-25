#include<iostream>
#include<iomanip>
using namespace std;

//循环链表结构声明
typedef struct CirList {
	int data;//数据域
	struct CirList* next;//指针域
}CirList;

//循环链表头节点的创建函数
 struct CirList* CreateList() {
	//struct CirList* headNode = (struct CirList*)malloc(sizeof(struct CirList));
	 struct CirList * headNode = new CirList();
	headNode->next = headNode;//指针域指向自身
	return headNode;
}

 //循环链表的新节点创建函数
 struct CirList* CreateNode(int data) {
	// struct CirList* newNode = (struct CirList*)malloc(sizeof(struct CirList));
	 struct CirList *newNode = new struct CirList();
	 newNode->data = data;
	 newNode->next = NULL;
	 return newNode;
 }

 //循环链表的增加节点函数
 //头插法
 void insertList(struct CirList *headNode, int data) {
	 struct CirList* newNode = CreateNode(data);//调用新节点创建函数创建一个新节点
	 newNode->next = headNode->next;//头节点之后的元素链到新节点之后
	 headNode->next = newNode;//将新节点链到头节点之后
 }		

 //循环链表的删除操作
 void deleteList(struct CirList* headNode, int posdata) {
	 struct CirList* posNode = headNode->next;//指向第一个节点
	 struct CirList* posNodefront = headNode;//指向头节点
		//此处的posNode指向待删除节点，posNodefront指向待删除结点的前一个结点
	 if (posNode == headNode) {//除了头节点之外，并无其他节点
		 printf("error:NULL!");//报错
		 return;
	 }
	 else {
		 while (posNode->data != posdata) {//查找待删除的节点——按值查找
			 posNodefront = posNode;//更改前驱节点的值
			 posNode = posNode->next;//向后继续遍历
			 if (posNode == headNode) {//循环链表会循环遍历，所以当posNode重新指回头节点时，就代表已经遍历完了整个链表，但仍未找到待删除接节点
							//此时可以判断待删除节点并不存在在该链表中
				 printf("error:null!");
				 return;
			 }
		 }
		 posNodefront->next = posNode->next;//若找到，则直接更改前驱结点指向
		 //free(posNode);
		 delete posNode;//释放待删除结点即可
	 }
 }

 //循环链表的修改操作
 void amendList(struct CirList* headNode, int posdata, int data) {//poedata是带查找节点的原始值，data是要修改的新值
	 struct CirList* posNode = headNode->next;//指针指向第一个节点
	 if (posNode == headNode)//若表中此时只有头节点，则第一个节点就是i头节点
		 printf("error!");//表中并无数据，无法修改
	 else {
		 while (posNode->data != posdata) {//按值查找
			 posNode = posNode->next;//不等就向后遍历
			 if (posNode == headNode) {//同理，需要对查找完一遍单链表的情况进行注意
				 printf("error!");
				 return;
			 }
		 }
		 posNode->data = data;
	 }
 }

 //循环链表的打印操作
 void printList(struct CirList *headNode) {
	 struct CirList* pMove = headNode->next;//指针指向第一个节点
	 if (pMove == headNode) {//同样也需要进行链表是否为空的判断
		 printf("error:NULL!");
		 return;
	 }
	 else {
		 while (pMove != headNode) {//此时就可以将遍历完一遍的情况作为打印结束的情况
			 //printf("%d\t", pMove->data);
			 cout << pMove->data<<"  ";
			 pMove = pMove->next;
		 }
	 }
	// putchar('\n');
	 cout << endl;
 }


int main()
{
	CirList *H = new CirList();//创建头节点
	cout << "在H循环链表中添加一个节点值为5的新节点:";
	insertList(H,5);//在H循环链表中添加一个节点值为5的新节点
	printList(H);//打印新链表
	cout << "在H循环链表中将初始值为5的节点值改为50：";
	amendList(H, 5, 50);//在H循环链表中将初始值为5的节点值改为50
	printList(H);
	cout << "在循环链表H中删除一个值为50的节点：";
	deleteList(H,50);
	//printList(H);

	cout << endl;
	system("pause");
	return 0;
}