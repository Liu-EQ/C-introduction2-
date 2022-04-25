#include<iostream>
#include<iomanip>
using namespace std;

//ѭ������ṹ����
typedef struct CirList {
	int data;//������
	struct CirList* next;//ָ����
}CirList;

//ѭ������ͷ�ڵ�Ĵ�������
 struct CirList* CreateList() {
	//struct CirList* headNode = (struct CirList*)malloc(sizeof(struct CirList));
	 struct CirList * headNode = new CirList();
	headNode->next = headNode;//ָ����ָ������
	return headNode;
}

 //ѭ��������½ڵ㴴������
 struct CirList* CreateNode(int data) {
	// struct CirList* newNode = (struct CirList*)malloc(sizeof(struct CirList));
	 struct CirList *newNode = new struct CirList();
	 newNode->data = data;
	 newNode->next = NULL;
	 return newNode;
 }

 //ѭ����������ӽڵ㺯��
 //ͷ�巨
 void insertList(struct CirList *headNode, int data) {
	 struct CirList* newNode = CreateNode(data);//�����½ڵ㴴����������һ���½ڵ�
	 newNode->next = headNode->next;//ͷ�ڵ�֮���Ԫ�������½ڵ�֮��
	 headNode->next = newNode;//���½ڵ�����ͷ�ڵ�֮��
 }		

 //ѭ�������ɾ������
 void deleteList(struct CirList* headNode, int posdata) {
	 struct CirList* posNode = headNode->next;//ָ���һ���ڵ�
	 struct CirList* posNodefront = headNode;//ָ��ͷ�ڵ�
		//�˴���posNodeָ���ɾ���ڵ㣬posNodefrontָ���ɾ������ǰһ�����
	 if (posNode == headNode) {//����ͷ�ڵ�֮�⣬���������ڵ�
		 printf("error:NULL!");//����
		 return;
	 }
	 else {
		 while (posNode->data != posdata) {//���Ҵ�ɾ���Ľڵ㡪����ֵ����
			 posNodefront = posNode;//����ǰ���ڵ��ֵ
			 posNode = posNode->next;//����������
			 if (posNode == headNode) {//ѭ�������ѭ�����������Ե�posNode����ָ��ͷ�ڵ�ʱ���ʹ����Ѿ���������������������δ�ҵ���ɾ���ӽڵ�
							//��ʱ�����жϴ�ɾ���ڵ㲢�������ڸ�������
				 printf("error:null!");
				 return;
			 }
		 }
		 posNodefront->next = posNode->next;//���ҵ�����ֱ�Ӹ���ǰ�����ָ��
		 //free(posNode);
		 delete posNode;//�ͷŴ�ɾ����㼴��
	 }
 }

 //ѭ��������޸Ĳ���
 void amendList(struct CirList* headNode, int posdata, int data) {//poedata�Ǵ����ҽڵ��ԭʼֵ��data��Ҫ�޸ĵ���ֵ
	 struct CirList* posNode = headNode->next;//ָ��ָ���һ���ڵ�
	 if (posNode == headNode)//�����д�ʱֻ��ͷ�ڵ㣬���һ���ڵ����iͷ�ڵ�
		 printf("error!");//���в������ݣ��޷��޸�
	 else {
		 while (posNode->data != posdata) {//��ֵ����
			 posNode = posNode->next;//���Ⱦ�������
			 if (posNode == headNode) {//ͬ����Ҫ�Բ�����һ�鵥������������ע��
				 printf("error!");
				 return;
			 }
		 }
		 posNode->data = data;
	 }
 }

 //ѭ������Ĵ�ӡ����
 void printList(struct CirList *headNode) {
	 struct CirList* pMove = headNode->next;//ָ��ָ���һ���ڵ�
	 if (pMove == headNode) {//ͬ��Ҳ��Ҫ���������Ƿ�Ϊ�յ��ж�
		 printf("error:NULL!");
		 return;
	 }
	 else {
		 while (pMove != headNode) {//��ʱ�Ϳ��Խ�������һ��������Ϊ��ӡ���������
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
	CirList *H = new CirList();//����ͷ�ڵ�
	cout << "��Hѭ�����������һ���ڵ�ֵΪ5���½ڵ�:";
	insertList(H,5);//��Hѭ�����������һ���ڵ�ֵΪ5���½ڵ�
	printList(H);//��ӡ������
	cout << "��Hѭ�������н���ʼֵΪ5�Ľڵ�ֵ��Ϊ50��";
	amendList(H, 5, 50);//��Hѭ�������н���ʼֵΪ5�Ľڵ�ֵ��Ϊ50
	printList(H);
	cout << "��ѭ������H��ɾ��һ��ֵΪ50�Ľڵ㣺";
	deleteList(H,50);
	//printList(H);

	cout << endl;
	system("pause");
	return 0;
}