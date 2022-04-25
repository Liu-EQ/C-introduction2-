#include <stdio.h>
#include <stdlib.h>
#define  MAX_NUM 100

//�ַ����Ľṹ����
typedef struct str {
	char ch[MAX_NUM + 1];//��ֵ��
	int length;//����

}*SString;
//�ַ�����ʼ��
SString initSString()
{
	SString str = (SString)malloc(sizeof(struct str));//�ѷ���洢
	if (!str)
		printf("��̬�ڴ����ʧ��!\n");
	str->length = 0;
	// printf("����ʼ���ɹ�!\n");
	return str;
}
//�ж��ַ����Ƿ�Ϊ��
int isEmpty(SString str)
{
	if (str->length == 0)
	{
		return 1;//����
	}
	return 0;
}
//�ַ�����ֵ
SString strAssign(SString str, char s[])
{

	int i = 0;
	while (s[i])
	{
		str->ch[++str->length] = s[i];
		i++;
	}
	return str;
}
//��ӡ�ַ���
void printSString(SString str)
{
	int i;


	for (i = 1; i <= str->length; i++)
		printf("%c", str->ch[i]);
	printf("\n");
}
//�ַ�������
SString   strCopy(SString str1, SString str2)//���ַ���2��ֵ��ֵ���ַ���1
{
	int i;
	for (i = 1; i <= str2->length; i++)
	{
		str1->ch[i] = str2->ch[i];
	}
	str1->length = str2->length;
	return str1;
}
SString strCat(SString str1, SString str2)//���ַ���2��ֵ�ٴ���ӵ��ַ���1���棬����ַ���3��ʵ���˶����ַ���2��ֵ�ĸ���
{
	SString str3 = initSString();
	int i;
	for (i = 1; i <= str1->length; i++)
		str3->ch[i] = str1->ch[i];
	for (i = 1; i <= str2->length; i++)
		str3->ch[i + str1->length] = str2->ch[i];
	str3->length = str1->length + str2->length;
	return str3;

}
//��ȡ�ַ����ĳ���
int getStrLength(SString str)
{
	return str->length;
}
//�ڴ�str1��posλ�ò��봮str2
SString strInsert(SString str1, int pos, SString str2)
{
	if (pos<1 || pos>str1->length)//�Բ���λ�ý����жϣ�С��1���ߴ����ַ������ȶ���ΪΥ�������
	{
		printf("����λ�ô���!\n");
		exit(0);
	}
	int i=0;//���ɶԱ�����ʼ���ĺ�ϰ��
	for (i = pos; i <= str1->length; i++)
	{
		str1->ch[i + str2->length] = str1->ch[i];//�Ⱥ���ԭ�ַ����е�Ԫ�أ�Ϊ��������ַ���1�ڳ��ռ�
	}
	for (i = 1; i <= str2->length; i++)
	{
		str1->ch[i + pos - 1] = str2->ch[i];
	}
	str1->length = str2->length + str1->length;
	return str1;
	//�����Ĳ���������۵��������ȫ�棬û�п��ǵ�ԭ�ַ����ĳ���
		/*case1��maxsize>=Arr1.len+Arr2.len����ֱ�Ӳ��룬�����������
		  case2��maxsize<Arr1.len+Arr2.len������ʱ����Ϊ���������
					case2.1��maxsize>=Arr1.len(pos1)+Arr2.len������ʱ��Ҫ����������λ�ú���Ĳ���Ԫ��
					case2.2��maxsize<Arr1.len(pos1)+Arr2.len������ʱ��Ҫ�������ִ�������ַ����е�Ԫ��
		���ڴˣ����еĶ����ַ�������������Ѿ��������*/
}
//ɾ��ָ��λ�õ��ַ���
SString strDelete(SString str, int pos, int len)
{
	if (pos<1 || pos>str->length || len + pos - 1 > str->length)//��ɾ��λ�úϷ����ж�
	{
		printf("ɾ��λ�ô���!\n");
		exit(0);
	}

	int i;
	for (i = pos + len; i <= str->length; i++)//���ø���ʵ��ɾ��������ɾ�����ַ����ĺ����ַ�ȫ��ǰ�ƾ�ʵ���˶��ڸ��ַ�����ɾ��
	{

		str->ch[i - len] = str->ch[i];//ǰ�Ʋ���
	}
	str->length = str->length - len;//���³���
	return str;

}
//ȡ�Ӵ�
SString subString(SString str, int pos, int len)//������str�ĵ�pos���ַ���ȡ������Ϊlen���Ӵ�
{
	if (pos<1 || pos>str->length || len + pos - 1 > str->length)
	{
		printf("����λ�ô���!\n");
		exit(0);
	}
	int i;
	SString subStr = initSString();
	for (i = 1; i <= len; i++)
	{
		subStr->ch[i] = str->ch[i + pos - 1];
	}
	subStr->length = len;
	return subStr;
}
//���Ӵ�������ģʽƥ���㷨��
//����ͨģʽƥ���㷨��ʵ�ֺ��������� B��α������A��α�Ӵ�
int mate(SString  B, SString A) {
	int  j = 0,cur=0,i=cur;//i����ģʽ��j�����Ӵ���cur��¼��ǰ�Ӵ�����ʼλ��
	while (i < B->length && j < A->length) {//i����������j�����Ӵ�
		if (B->ch[i] == A->ch[j]) {//��ȣ���ȽϺ���Ԫ��
			i++;
			j++;
		}
		else {//���ȣ����Ӵ���ͷ��ʼ�����������ӵ�ǰ����������һ���ڵ��������
			i = cur + 1;
			cur = i;
			j = 0;
		}
	}
	//����ѭ�������ֿ��ܣ�i=strlen(B)˵���Ѿ�������������ƥ��ʧ�ܣ�j=strlen(A),˵���Ӵ�������ɣ��������гɹ�ƥ��
	if (j == A->length) {//j�������Ӵ�������������ҵ�����ģʽ����ͬ���Ӵ�
		return cur+1;//���ص�ǰƥ�䵽���Ӵ���ʼλ�õ��±�
	}
	//���е��ˣ�Ϊi==strlen(B)�����
	return 0;
}
//�����ַ���
void destorySString(SString str1)
{

	free(str1);
}
int main()
{
	SString str = initSString(), str2 = initSString();
	char s[100], s2[100], s3[100], s4[100];
	printf("������һ���ַ���str1:\n");
	scanf("%s", s);



	str = strAssign(str, s);
	printf("��ӡ�ַ���str1:\n");
	printSString(str);

	printf("�����ַ���str1���ַ���str2\n");

	strCopy(str2, str);
	printf("��ӡ�ַ���str2:\n");

	printSString(str2);

	/*SString str3=strCat(str,str2);
	printSString(str3);*/
	int insertLocation;

	printf("���������λ�á������ַ���str4:\n");


	scanf("%d", &insertLocation);
	scanf("%s", s4);
	SString str4 = initSString();
	str4 = strAssign(str4, s4);


	str = strInsert(str, insertLocation, str4);
	printf("��ӡ����str4����ַ���str1:");
	printSString(str);


	int delLocation, delLength;
	printf("�������ַ���str1ɾ���ַ���λ�úͳ���:\n");
	scanf("%d %d", &delLocation, &delLength);

	strDelete(str, delLocation, delLength);
	printSString(str);

	int subLocation, subLength;
	printf("�������ַ���str1���Ӵ�λ�úͳ���:\n");
	scanf("%d %d", &subLocation, &subLength);
	SString subStr = subString(str, subLocation, subLength);
	printSString(subStr);

	printf("�����ַ���st1:\n");
	destorySString(str);


	return 0;
}