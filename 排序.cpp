#include<iostream>
#include<string>
using namespace std;




//�򵥲�������������
void SimpleSort(int   a[],int length);//��������ָ�룬ȷ�����������Ӧ�õ�ԭ������


//ð������ĺ�������
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
	//Ĭ�Ͻ���һ��Ԫ�ط����Ѿ��ź���������У����i��ֵΪ1
	for (int i = 1; i < length; i++)
	{
		int j = i - 1;//ȷ���Ѿ���������еĳ���
		int temp = a[i];//�洢������Ԫ�ص�ֵ��Ϊ֮��Ĳ�����׼��
		if (a[j] > a[i] && j != -1)
		{
			

			a[j + 1] = a[j];//Ϊ���������׼��
			j--;//Ӧ���Ⱥ��ƣ��ټ�һ
		}
		
			//��Ϊ�����ĺ��ƹ����У����Ⱥ��ƣ��ټ�һ���µıȽϣ�����ô���ҵ�һ��Ԫ��С�ڴ�����Ԫ��ʱ�����Ѿ�ȷ���˺����һ��Ԫ�ص�Ԫ�ǿյ�
			//���Ҳ�;����˲���λ�ã�a[j+1]
			a[j + 1] = temp;//���������Ԫ��
	}

}

void BubbleSort(int a[],int length)
{
	for (int i=0; i < length; i++)//�ܵĴ�ѭ���Ĵ���
	{
		for (int j=1;j <length-i;j++)
		{
			if (a[j-1]>a[j])//ǰ���С�����л���
			{
				int temp = a[j];
				a[j] = a[j-1];
				a[j - 1] = temp;
			}
		}
	}
}
