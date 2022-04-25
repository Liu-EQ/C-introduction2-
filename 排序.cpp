#include<iostream>
#include<string>
using namespace std;




//简单插入排序函数声明
void SimpleSort(int   a[],int length);//传入数组指针，确定排序操作会应用到原数组中


//冒泡排序的函数声明
void BubbleSort(int a[],int length);

int main() 
{
	int a[7] = {1,5,7,9,6,8,4};
	BubbleSort(a, 7);
	for (int i = 0; i < 7; i++)
	{
		cout << a[i] << "  ";
	}



	cout << endl;
	system("pause");
	return  0;
}

void SimpleSort(int a[],int length)
{
	//默认将第一个元素放入已经排好序的序列中，因此i初值为1
	for (int i = 1; i < length; i++)
	{
		int j = i - 1;//确定已经有序的序列的长度
		int temp = a[i];//存储待插入元素的值，为之后的插入做准备
		if (a[j] > a[i] && j != -1)
		{
			

			a[j + 1] = a[j];//为插入操作做准备
			j--;//应该先后移，再减一
		}
		
			//因为上述的后移过程中，是先后移，再减一（新的比较），那么当找到一个元素小于待插入元素时，就已经确定了后面的一个元素单元是空的
			//因此也就决定了插入位置：a[j+1]
			a[j + 1] = temp;//插入待插入元素
	}

}

void BubbleSort(int a[],int length)
{
	for (int i=0; i < length; i++)//总的大循环的次数
	{
		for (int j=1;j <length-i;j++)
		{
			if (a[j-1]>a[j])//前大后小，进行互换
			{
				int temp = a[j];
				a[j] = a[j-1];
				a[j - 1] = temp;
			}
		}
	}
}
