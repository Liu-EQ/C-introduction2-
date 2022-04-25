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
//ͷ�巨����������
//��ͷ��������ͷ�巨ʵ�ֺ���
link * creatLink(int * arc, int length) {
	int i;
	//���״̬�£�ͷָ�� H û���κν�㣬���ԣ������һ��Ԫ�أ����൱���Ǵ������ H
	//link * H = (link*)malloc(sizeof(link));
	link * H = new link();
	H->elem = arc[0];
	H->next = NULL;
	//�������ͷ�巨���볬�� 1 ��Ԫ�أ������ӵ���һ����� H ֮ǰ
	for (i = 1; i < length; i++) {
		//link * a = (link*)malloc(sizeof(link));
		link *a = new link();
		a->elem = arc[i];
		//����Ԫ��ʱ�����Ƚ�����λ�ú���������ӵ��½����
		a->next = H;
		//Ȼ��������ͷָ�� H
		H = a;
	}
	return H;
}
//��ͷ��������ͷ�巨ʵ�ֺ���
link * HcreatLink(int * arc, int length) {
	int i;
	//����ͷ��� H���������ͷָ��Ҳ�� H
	//link * H = (link*)malloc(sizeof(link));
	link * H = new  link();
	H->elem = 0;
	H->next = NULL;
	//����ͷ�巨��������
	for (i = 0; i < length; i++) {
		//link * a = (link*)malloc(sizeof(link));
		link *a = new link();
		a->elem = arc[i];
		//���Ƚ�����λ��֮����������ӵ��½�� a ��
		a->next = H->next;
		//���½�� a ���뵽ͷ���֮���λ��
		H->next = a;
	}
	return H;
}

//β�巨����������
//�˴�����˫��ָ�룬����Ϊ������Ҫ�޸�head��ֵ����head��һ��ָ��
//���·��޸ĵ�ʱ����Ȼʹ��(*head)Ҳ����һ��ָ��
/**
 * @param head ͷָ��ĵ�ַ
* @param n ������n����������
*/
void TcreatLink(link **head, int n) 
{
	    link *node=NULL, *tail=NULL;//nodeָ���¼�������Ľڵ㣬tail�㶨ָ��β�ڵ�
	    int data;
		while (n--)
		{
			//scanf("%d", &data);
			cin >> data;
			//node = (linkedList*)malloc(sizeof(linkedList));//��̬�����ڴ�
			node = new link();
			node->elem = data;
			node->next = NULL;
			if ((*head)->next == NULL)//ͷ�ڵ�֮���������ڵ�
				(*head)->next = node;
			else//ͷ�ڵ�֮���������ڵ�
				tail->next = node;
			tail = node;

		}
}

//���������ɾ�Ĳ�
//����������Ԫ��
//�������ʵ�������ǲ�����Ҫ�ı�ͷָ���ֵ�������൱�ڴ�������ʱ������ݹ���
void insertLink(link *head, int i, int data) 
{
	    link *node = head, *tail=NULL;//node��������Ҫ�����λ�ã��ӵ�һ���ڵ㿪ʼ����tail����ָ�������Ľڵ�
	    int j = 0;//Ĭ�������0��ʼ��������ͷ�ڵ�֮��ĵ�һ���ڵ����Ϊ0��
				//j�ĳ��Ը�ֵ�����˵�������ĸ����ֿ�ʼ��������ͷ�ڵ�֮��ĵ�һ���ڵ�����Ϊ���٣�
				//��Ϊ��һ��ʼ�ĸ�ֵ�У�nodeָ��ͷ�ڵ������Ϊ���0�����������j��ֵӦ�ú�node����ͬ��
							//����ʼj��ֵΪ-1�������ͷ�ڵ㲻����ڵ������У�ͷ�ڵ�֮��ĵ�һ���ڵ�ſ�ʼ�������Ҵ�0��ʼ
	    //ѭ���ж�i�Ƿ����������������ѭ����nodeָ���i-1����㣬��j == i-1
		    while (node->next != NULL && j < i - 1) 
				//��Ϊһ��ʼnodeָ��ͷ�ڵ㣬����node����϶���Ϊnull��ֱ���жϵ�һ�ڽڵ㼴��
			{
		        node = node->next;
		        j++;
		
	}
	    if (j != i - 1) {
		       // printf("����λ������");
			cout << "����λ������" << endl;
		        return;
		
	}
	    //��������ĵ�3��4��
		    //tail = (linkedList *)malloc(sizeof(linkedList));
		tail = new link();
	    tail->elem = data;
	    tail->next = node->next;//ԭ���ĵ�i���ڵ㼰�����Ľڵ㶼��������ڵ�֮��
	    node->next = tail;//tail��Ϊ�˵�i���ڵ�
	
}
//ɾ����i��Ԫ��,��ɾ����ֵ��data���أ����践��ֵ
//����˼·�Ͳ���Ԫ������
void deleteLink(link*head, int i, int* data) {//ɾ����i��λ�õ�Ԫ�أ���Ԫ��ֵ��ֵ��data
	    link *p = head, *s=NULL;//p���ڲ��Ҵ�ɾ��Ԫ�ص�λ�ã��ӵ�һ���㿪ʼ���ң���s����ָ���ɾ���ڵ㣨���з���ֵ������ǰ��Ԫ�ؽ������ӣ�
	    int j = -1;
	    while (p->next != NULL && p->next->next != NULL && j < i - 1) //�ж�ɾ��λ���Ƿ�Ϸ�
								//֮����Ҫ�ж�p->next,p->next->next����Ϊ��ǰһ��ָ���ɾ������ǰһ���ڵ㣬��һ��ָ���ɾ���ڵ�
		{
		        p = p->next;
		        j++;
		
		}
	    if (j != i - 1) 
		{
		        printf("ɾ��λ�ô���");
		        return;
		
		}
	    s = p->next;//s��ʱָ���ɾ��Ԫ��
	 * data = s->elem;//���ش�ɾ��Ԫ�ص�ֵ
	    p->next = p->next->next;//��һ��Ԫ������ǰһ��Ԫ�ص�ָ��
	   // free(s);
		delete s;//�ͷŴ�ɾ��Ԫ�ص��ڴ�
}
//������ĸ��ĺ���
void changeLink(link * head,int i,int data) 
{
	link *node = head;//ֻ��Ҫ����һ��ָ�룬���ڲ��Ҵ��޸Ľڵ㼴�ɣ�����Ҫ��һ���ڵ㸨��
	int j = -1;//Υ�������ж�
	if (node->next!=NULL&&j<i-1)
	{
		node = node->next;
		j++;
	}
	if (j!=i-1)
	{
		cout << "����ֵ���Ϸ���" << endl;
		return;
	}
	node->elem = data;
	return;
};
//������������
void display(link *p) {
	while (p) {
		//printf("%d ", p->elem);
		cout << p->elem << "  ";
		p = p->next;
	}
	//printf("\n");
	cout << endl;
}
//������Ĳ��Һ���
int selectElem(link * p, int elem) {//�������Ϊ�������ͷ�ڵ㣬��Ҫ���ҵ�Ԫ�ص�ֵ
	link * t = p;//����һ��ջ��������������ʱ����������
	int i = 1;//�������
	while (t->next) {//��Ϊ��ͷ�ڵ㣬���Դ�t��next��ʼ��������һ���ڵ㣬����бȽ�
		t = t->next;//ָ���һ���ڵ�
		if (t->elem == elem) {//����Ԫ��ֵ�Ա�
			return i;//����Ԫ���±꣨��Ϊ��1��ʼ�����Բ���Ҫ����+1��
		}
		i++;//���ȣ���ȽϺ���Ԫ��
	}
	return -1;//ȫ��������������δ�ҵ����򷵻ؼ�
}
//���㵥������
//�˴���Ϊhead��������ָ�룬���Դ���ָ�룬����Ҫ�ı�head��ֵ
int linkedListLength(link *head)
{
	   int length = 0;//��������
		    //ѭ������ж��ٸ����
		    while (head->next != NULL) //��ͷ��㣬���Դ�ͷ���ָ�����һ���ڵ㿪ʼ����
			{
		        length++;
		        head = head->next;
		
			}
	    //��������ĳ���
		 return length;
}


//�������ڴ�ռ���ͷ�
void freelink(link * head) 
{
	//��������ͷ�ֻ��һ���ڵ�һ���ڵ���ͷţ������Ҫ����һ���ͷź���
	link *p1 = head, *p2 = NULL;//p1ָ��ǰ��Ҫ�ͷŵĽڵ㣬p2ָ��ǰ���ͷŽڵ����һ���ڵ�
	while (p1!=NULL)//�����ǰ���ͷŽڵ㲻Ϊ��
	{
		p2=p1->next;//p2ָ����ͷŽڵ����һ���ڵ�
		delete p1;//�ͷŵ�ǰ�ڵ�
		p1 = p2;//p1����
	}
};
int main() {
	int a[3] = { 1,2,3 };
	//����ͷ�巨������ͷ�������
	link * H = creatLink(a, 3);
	cout << "ͷ�巨������ͷ�������-H��";
	display(H);
	//����ͷ�巨������ͷ�������
	link * head = HcreatLink(a, 3);
	cout << "ͷ�巨������ͷ�������-head��";
	display(head);
	//��������Ԫ�صĺ�������
	cout << "��head������ĵڶ���λ�ã�����һ����ֵΪ8�Ľڵ㣺";
	insertLink(head,2,8);//��H������ĵڶ���λ�ã�����һ����ֵΪ8�Ľڵ�
	display(head);
	//����ɾ��Ԫ�صĺ�������
	cout << "ɾ��head����ڶ���λ�õ�Ԫ�أ���m��������ֵ";
	int m;
	deleteLink(head,2,&m);//ɾ��H����ڶ���λ�õ�Ԫ�أ���m��������ֵ
	cout <<endl<< m<<endl;
	display(head);
	//�������Ԫ�صĺ�������
	cout << "����head�����һ��λ�õ�ֵ����Ϊ9��";
	changeLink(head,1,9);//����head�����һ��λ�õ�ֵ����Ϊ9
	display(head);
	//���Һ����ĵ���
	cout<<"���Һ����ĵ��ã�"<<selectElem(head, 2)<<endl;

	//free(H);
	//delete[] H;
	//freelink(H);
	free(head);
	freelink(H);
	//delete[] head;
	system("pause");
	return 0;
}