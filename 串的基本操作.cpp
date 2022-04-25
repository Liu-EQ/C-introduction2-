#include <stdio.h>
#include <stdlib.h>
#define  MAX_NUM 100

//字符串的结构声明
typedef struct str {
	char ch[MAX_NUM + 1];//数值域
	int length;//长度

}*SString;
//字符串初始化
SString initSString()
{
	SString str = (SString)malloc(sizeof(struct str));//堆分配存储
	if (!str)
		printf("动态内存分配失败!\n");
	str->length = 0;
	// printf("串初始化成功!\n");
	return str;
}
//判断字符串是否为空
int isEmpty(SString str)
{
	if (str->length == 0)
	{
		return 1;//空真
	}
	return 0;
}
//字符串赋值
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
//打印字符串
void printSString(SString str)
{
	int i;


	for (i = 1; i <= str->length; i++)
		printf("%c", str->ch[i]);
	printf("\n");
}
//字符串复制
SString   strCopy(SString str1, SString str2)//将字符串2的值赋值给字符串1
{
	int i;
	for (i = 1; i <= str2->length; i++)
	{
		str1->ch[i] = str2->ch[i];
	}
	str1->length = str2->length;
	return str1;
}
SString strCat(SString str1, SString str2)//将字符串2的值再次添加到字符串1后面，组成字符串3，实现了对于字符串2的值的复制
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
//获取字符串的长度
int getStrLength(SString str)
{
	return str->length;
}
//在串str1的pos位置插入串str2
SString strInsert(SString str1, int pos, SString str2)
{
	if (pos<1 || pos>str1->length)//对插入位置进行判断（小于1或者大于字符串长度都视为违法情况）
	{
		printf("插入位置错误!\n");
		exit(0);
	}
	int i=0;//养成对变量初始化的好习惯
	for (i = pos; i <= str1->length; i++)
	{
		str1->ch[i + str2->length] = str1->ch[i];//先后移原字符串中的元素，为待插入的字符串1腾出空间
	}
	for (i = 1; i <= str2->length; i++)
	{
		str1->ch[i + pos - 1] = str2->ch[i];
	}
	str1->length = str2->length + str1->length;
	return str1;
	//上述的插入操作讨论的情况不够全面，没有考虑到原字符串的长度
		/*case1：maxsize>=Arr1.len+Arr2.len——直接插入，并无其他情况
		  case2：maxsize<Arr1.len+Arr2.len——此时还分为两种情况：
					case2.1：maxsize>=Arr1.len(pos1)+Arr2.len——此时需要舍弃待插入位置后面的部分元素
					case2.2：maxsize<Arr1.len(pos1)+Arr2.len——此时需要舍弃部分待插入的字符串中的元素
		基于此，所有的定长字符串插入情况就已经考虑完毕*/
}
//删除指定位置的字符串
SString strDelete(SString str, int pos, int len)
{
	if (pos<1 || pos>str->length || len + pos - 1 > str->length)//待删除位置合法性判断
	{
		printf("删除位置错误!\n");
		exit(0);
	}

	int i;
	for (i = pos + len; i <= str->length; i++)//利用覆盖实现删除，将待删除的字符串的后续字符全部前移就实现了对于该字符串的删除
	{

		str->ch[i - len] = str->ch[i];//前移操作
	}
	str->length = str->length - len;//更新长度
	return str;

}
//取子串
SString subString(SString str, int pos, int len)//从主串str的第pos个字符起，取出长度为len的子串
{
	if (pos<1 || pos>str->length || len + pos - 1 > str->length)
	{
		printf("输入位置错误!\n");
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
//求子串（串的模式匹配算法）
//串普通模式匹配算法的实现函数，其中 B是伪主串，A是伪子串
int mate(SString  B, SString A) {
	int  j = 0,cur=0,i=cur;//i遍历模式，j遍历子串，cur记录当前子串的起始位置
	while (i < B->length && j < A->length) {//i遍历主串，j遍历子串
		if (B->ch[i] == A->ch[j]) {//相等，则比较后续元素
			i++;
			j++;
		}
		else {//不等，则子串从头开始遍历，主串从当前遍历起点的下一个节点继续遍历
			i = cur + 1;
			cur = i;
			j = 0;
		}
	}
	//跳出循环有两种可能，i=strlen(B)说明已经遍历完主串，匹配失败；j=strlen(A),说明子串遍历完成，在主串中成功匹配
	if (j == A->length) {//j遍历完子串代表从主串中找到了与模式串相同的子串
		return cur+1;//返回当前匹配到的子串起始位置的下标
	}
	//运行到此，为i==strlen(B)的情况
	return 0;
}
//销毁字符串
void destorySString(SString str1)
{

	free(str1);
}
int main()
{
	SString str = initSString(), str2 = initSString();
	char s[100], s2[100], s3[100], s4[100];
	printf("请输入一个字符串str1:\n");
	scanf("%s", s);



	str = strAssign(str, s);
	printf("打印字符串str1:\n");
	printSString(str);

	printf("拷贝字符串str1到字符串str2\n");

	strCopy(str2, str);
	printf("打印字符串str2:\n");

	printSString(str2);

	/*SString str3=strCat(str,str2);
	printSString(str3);*/
	int insertLocation;

	printf("请输入插入位置、插入字符串str4:\n");


	scanf("%d", &insertLocation);
	scanf("%s", s4);
	SString str4 = initSString();
	str4 = strAssign(str4, s4);


	str = strInsert(str, insertLocation, str4);
	printf("打印插入str4后的字符串str1:");
	printSString(str);


	int delLocation, delLength;
	printf("请输入字符串str1删除字符的位置和长度:\n");
	scanf("%d %d", &delLocation, &delLength);

	strDelete(str, delLocation, delLength);
	printSString(str);

	int subLocation, subLength;
	printf("请输入字符串str1的子串位置和长度:\n");
	scanf("%d %d", &subLocation, &subLength);
	SString subStr = subString(str, subLocation, subLength);
	printSString(subStr);

	printf("销毁字符串st1:\n");
	destorySString(str);


	return 0;
}