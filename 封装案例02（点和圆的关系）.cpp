#include<iostream>
#include<string>
#include"Circle.h"
#include"spot.h"//���ļ���д����Ҫ���������м�����Щͷ�ļ�
using namespace std;

//�����������Ե��Բ�Ĺ�ϵ�����жϣ�����Բ�⡢����Բ�ϡ�����Բ�У�
				//����������˼·����������㵽Բ�ĵľ�����뾶�Ĵ�С��ϵ
						//Tips���㵽Բ�ĵľ��룺����֮��ľ��빫ʽ��x~2+y~2�����ţ�����������ζ����ֵ���п����Ų�����
						//��˾���Ҫ�����������������߶�ƽ��֮�󣬾Ϳ���ʡ�Կ����Ų�����
				//��ˣ���Ӧ���������ࣺԲ��͵���
						//Բ�����ԣ�Բ�����꣬�뾶����
						//�������ԣ�����

						
//class spot
//{
//public:
//	//�����ӿڣ����ڶ�д�������
//	void set_spot(int x, int y) {
//		spot[0] = x;
//		spot[1] = y;
//	};//д��Բ������
//	int  get_spot_x() { return spot[0]; };//x
//	int  get_spot_y() { return spot[1]; };//y
//private:
//	int spot[1];//�������
//};//����
//class Circle 
//{
//public:
//	//��Ϊ���ӿڣ����ڶ�ȡ��д��Բ������Ͱ뾶���ȣ�
//	void set_center(spot point1) { center = point1; };//����Բ������
//	void set_r(int a) { r = a; };//����뾶����
//	int  get_center_x() { return center.get_spot_x(); };//x
//	int  get_center_y() { return center.get_spot_y(); };//y
//	int  get_r() { return r; };
//private:
//	spot center;//����һ�������������ڴ�Ÿ�Բ������
//				//��һ������Ϊ��һ����ĳ�Ա
//	int r;//�뾶
//
//
//};//Բ��


void Judge(Circle &CC1,spot &PP1);//�жϺ�������
									//�������Ϊһ��Բ�Ķ���һ����Ķ��󣬲������õķ�ʽ����


int main()
{
	//������������֮����Ҫͨ���ഴ������
	Circle CC1;//Բ���ʵ����
	spot C_P;//����Բ�Ķ���
	C_P.set_spot(10,10);
	spot   PP1;//�����ʵ����
	CC1.set_center(C_P);//����Բ�����꣨10,10��
	CC1.set_r(10);//����Բ�İ뾶����10
	PP1.set_spot(10,5);//���������꣨10,11��
	//��һ����Ҫ����һ���������ڶԱ����ߵľ����ϵ
	Judge(CC1,PP1);//���ñȽϺ���


	cout << endl;
	system("pause");
	return 0;
}

void Judge(Circle & CC1, spot & PP1)
{
	int x1 = CC1.get_center_x(); int x2 = PP1.get_spot_x();//��ȡ����x����
	int y1 = CC1.get_center_y(); int y2 = PP1.get_spot_y();//��ȡ����y����
	int temp = CC1.get_r();//��ȡԲ�İ뾶����
	if ((x1-x2)*(x1 - x2) +(y1-y2)*(y1 - y2)<temp*temp)
	{
		cout<< "�õ���Բ�ڣ�������\n" ;
	}
	else if ((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2) == temp*temp)
	{
		cout<< "�õ���Բ�ϣ�����\n";
	}
	else 
	{
		cout<< "�õ���԰�⣡����\n" ;
	}

}


//�ܽ᣺
	//������һ����������һ������Ϊ���ĳ�Ա
	//��ķ��ļ���д��Tips����ͷ�ļ���ֻ����������û�к���ʵ�ֹ��̣���Դ�ļ�����Ҫ�����Ӧ��ͷ�ļ����������õ�����������Ϊ��Աʱ��
								//��Ҫ�������������������������Ҫ������Ӧ��ͷ�ļ���