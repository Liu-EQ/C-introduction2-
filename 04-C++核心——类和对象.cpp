#include<iostream>
#include<string>
using namespace std; 


//4.0 ��Ͷ�����Ҫ��
//C++����������������Ϊ����װ���̳С���̬
//C++��Ϊ���������Ϊ���󣬵����Ƕ���ͻ��������Ժ���Ϊ

//4.1 ��װ

//��װ������һ�������Ժ���Ϊ��Ϊһ�����壬���������е����

//�﷨��class ����{����Ȩ�ޣ�����/��Ϊ}��
//����һ�����һ��Բ�࣬��԰���ܳ�
		//��������Բ���ܳ���1��֪����Բ�ܳ���ʽ��C=2��r����2����ȷ���漰���������壺��Ϊ���������ö��壬rΪԲ�İ뾶����ͬ��Բ��r��ͬ��
									                         //cҲ������ΪԲ��һ�����ԣ�
											//Tips���涨һ����������ǣ�Ҫ����ʵ����������ò���ĳЩ���ԣ����Բ���д
const double PI = 3.14159;//Բ����
//��ʼ���Բ�ࣺ��ʹ�ùؼ���class�����ࣩ  class ����
class Circle
{
public://����Ȩ�ޣ�����Ȩ��
	int radius;//����:Բ�İ뾶
	double circle_C()
	{
		return (2 * PI * radius);
	
	}//��Ϊ����ȡԲ���ܳ���ͨ����һ������������
};//һ��������Բ����Ѿ�������ϣ�ֻ�д���һ�������Բ֮�󣬲���˵������һ������

//�����������һ��ѧ���࣬������������ѧ�ţ����Ը�������ѧ�Ÿ�ֵ��������ʾ������ѧ��
class Student
{
public://Ȩ�ޣ�����
	//����
	int Stu_ID;//ѧ��
	string Stu_Name;//����
	//��Ϊ
	void ShowStu() 
	{
		cout << "��ѧ����ϢΪ��\nѧ�ţ�" << Stu_ID << "\t������" << Stu_Name << endl;
	}
	void SetName(string Name) { Stu_Name = Name; };
	void SetID(int ID) { Stu_ID = ID; };

};
//���е����Ե���Ϊͳһ��Ϊ��Ա
//���� Ҳ��Ϊ ��Ա���Ժͳ�Ա����
//��Ϊ Ҳ��Ϊ ��Ա�������Ա����

//��װ��������������Ժ���Ϊ����Ȩ�޿��ơ�

	//Tips���������ʱ�����Խ���ͬ�����Ժ���Ϊ���ڲ�ͬ��Ȩ���£����Կ���
		//Ȩ�����ͣ�����Ȩ�ޣ�public���������ں����ⶼ���Է���
				  //����Ȩ�ޣ�protected���������ڿ��Է��ʣ����ⲻ���Է��ʣ�����Ҳ���Է��ʸ����еı���Ȩ�ޣ�
				  //˽��Ȩ�ޣ�privated���������ڿ��Է��ʣ����ⲻ���Է��ʣ����Ӳ��ܷ��ʸ����е�˽��Ȩ�ޣ�

//4.1.2 struct��class������structĬ��Ȩ��Ϊ������classĬ��Ȩ��Ϊ˽�С�����������
class c1
{
	int m_A;//Ĭ��˽��Ȩ��
};
struct c2 
{
	int m_A;//Ĭ�Ϲ���Ȩ��
};

//4.1.3  ����Ա��������Ϊ˽��
		//�ŵ�һ����Ա��������Ϊ˽�п����Լ����ƶ���д��Ȩ��
		//�ŵ��������дȨ�ޣ����Լ�����ݵ���Ч��
//�������
class hunman 
{
public://���ýӿڶ����Խ��ж���д
	//������дȨ��
	void set_Name(string Name) 
	{
		P_Name = Name;//�����ǹ���Ȩ�ޣ����Կ��Խ��и�ֵ
	};
	//�����Ķ�Ȩ��
	string get_Name() 
	{
		return  P_Name;
	};
	//�Ա�Ķ�Ȩ��
	string get_Sex() 
	{
		return P_Sex;
	};
	//�ŵ������ʱ���������һ��д��Ȩ�ޣ���ô����ͨ������Ϊ�ڲ����е�������֤д�����ݵ���Ч��
	void set_Age(int age)
	{
		if (age > 0 && age < 150)
		{
			P_Age = age;
		}
		else
		{
			cout << "�������벻�Ϸ�" << endl;
			return;
		};
	}
	//����Ķ�Ȩ��
	int get_Age() 
	{
		return P_Age;
	};
	//��ַ�Ķ�Ȩ��
	void set_Add(string Address) 
	{
		P_Address = Address;
	};
private:
	string P_Name;//�������ɶ���д��
	string P_Sex="��";//�Ա�ֻ����
	int    P_Age=21;//���䣨ֻ����
	string P_Address; // ֻд
};





class person
{
	public://����Ȩ��
		string P_Name;
		void funName() 
		{
			P_Name = "��ľ";
			P_car = "������";
			password = 11223344;
		};
	protected://����Ȩ��
		string P_car;
	private://˽��Ȩ��
		long password;//���п�����

};

int main() 
{
	//ͨ��Բ��������һ������Ķ���
	//ʵ������ͨ��һ����������һ������Ĺ��̣�
	//Circle C1;
	//	//���ö�������Խ��и�ֵ����
	//C1.radius = 100;
	////Ҳ����ͨ����������ȡԲ���ܳ���Բ���ܳ�����Բ��������ֻ��˵������Ϊ��
	//cout << "�뾶Ϊ100��Բ���ܳ�Ϊ��" << C1.circle_C() << endl;//�����еģ�������ʡ��

	//Student Stu_1;//ѧ�����ʵ����
	//Stu_1.Stu_ID = 170902316;
	//Stu_1.Stu_Name = "��ľ���";//���Ը�ֵ����������һ
	////���Ը�ֵ����������
	//Stu_1.SetID(1111);
	//Stu_1.SetName("��ľ");//�Կɽ��и�ֵ������Ϊ˳�����⣬����������ĸ�ֵ

	//Stu_1.ShowStu();//???

	//person p1;
	//p1.P_Name = "��";
	////p1.password = 112233;Ȩ�޲�����
	//cout << p1.funName << endl;

	//c1 c1;//����һ��class����
	//c2 c2;//����һ��struct����
	////c1.m_A=10;//����Ȩ�޲�����
	//c2.m_A = 20;//��ȷ
	//cout << c2.m_A << endl;

	hunman pp1;
	pp1.set_Name("��ľ");
	cout << pp1.get_Name() << endl;
	cout << pp1.get_Sex() << endl;
	cout << pp1.get_Age() << endl;
	pp1.set_Add("��ľ��");
	//cout << pp1.P_Address << endl;
	pp1.set_Age(15);
	cout << pp1.get_Age() << endl;

	cout << endl;
	system("pause");
	return 0;
}