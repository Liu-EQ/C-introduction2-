#include<iostream>
#include<string>
using namespace std;



//�������������һ���������ࣨCube��
			//Ҫ�����������������������ֱ�ʹ��ȫ�ֺ����ͳ�Ա�����ж������������Ƿ����
				//�������������ࡪ�����ԣ�����ߣ����ڼ�������������������
									//Tips�������������ʽ��V=����*��*�ߣ��������ʽ������*��+��*��+��*�ߣ�*2=S
				//�������������ࡪ����Ϊ�����������������Ƚ������������Ƿ���ȣ��������߶���ȣ�
class Cube
{
public:

	//��Ϊ
	//���
	int  S_Cube() 
	{
		return (H*L+ L*W+ W*H) * 2;
	};
	//���
	int  V_Cube() 
	{
		return L*W*H;
	
	};
	//����Ҫ��һ����Ա�������Ƚ������������Ƿ����
	string Compare(Cube CC2) //��һ����Ա������������ֻ��Ҫ����һ����������
	{
		if (H==CC2.H&&W == CC2.W&&L == CC2.L)
		{
			return "����������������ͬ�ģ�������";
		}
		else
		{
			return "�����������岢����ͬ��������";
		}

	};
	//�����ӿڣ���������������ĳ���ߣ�
	void set_L(int a) { L = a; };
	void set_W(int a) { W = a; };
	void set_H(int a) { H = a; };
	//�����ӿڣ����ڻ�ȡ�����峤��ߣ�
	int get_L() { return L; };
	int get_W() { return W; };
	int get_H() { return H; };
private:
	//����
	int L = 5;//length
	int W = 7;//Wideth
	int H = 9;//Hight
};


string Compare1(Cube &CC1, Cube &CC2)//���ݴ���򵥡���ʹ������
{
	if (CC1.get_L() == CC2.get_L()&&CC1.get_W() == CC2.get_W()&&CC1.get_H() == CC2.get_H())//�����ģ���������
	{
		return "����������������ͬ�ģ�������";
	}
	else
	{
		return "�����������岢����ͬ��������";
	}

};//ȫ�ֺ���

int main() 
{
	Cube V1, V2;
	V1.set_L(10); V1.set_W(10); V1.set_H(10);
	V2.set_L(10); V2.set_W(10); V2.set_H(10);
	cout << "������V1�����Ϊ��" << V1.S_Cube()<<endl;
	cout << "������V2�����Ϊ��" << V2.S_Cube() << endl;
	cout << "������V1�����Ϊ��" << V1.V_Cube() << endl;
	cout << "������V2�����Ϊ��" << V2.V_Cube() << endl;
	cout<<V1.Compare(V2)<<endl;//���ó�Ա�����ж�
	cout << Compare1(V1,V2) << endl;//����ȫ�ֺ���
	//ȫ�ֺ����ͳ�Ա�������бȽϲ�������������ǲ�ͬ��



	cout << endl;
	system("pause");
	return 0;

}