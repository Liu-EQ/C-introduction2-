#include<iostream>
#include<string>
using  namespace std;




//7.0 ��Ԫ��Ȼ���һ��������������Է�����һ������˽�г�Ա��

////�ؼ��֣�friend
////����ʵ�֣�
////ȫ�ֺ�������Ԫ��
//
////class Building 
////{
////	friend void GoodGay(Building &Build1);//������GoodGay���ȫ�ֺ�����Building�ĺ����ѣ����Է�������˽�г�Ա
////			//��������Է������⴦
////	friend class GoodGay;//������GoodGay�������Building�ĺ����ѣ����Է�������˽�г�Ա
////public:
////	//friend void GoodGay(Building &Build1);//������GoodGay���ȫ�ֺ�����Building�ĺ����ѣ����Է�������˽�г�Ա
////	Building() 
////	{
////		M_SittingRoom = "����";
////		M_BedRoom = "����";
////	};
////public:
////	string M_SittingRoom;//����
////private:
////	//friend void GoodGay(Building &Build1);//������GoodGay���ȫ�ֺ�����Building�ĺ����ѣ����Է�������˽�г�Ա
////	string M_BedRoom;//����
////};
//////����һ��ȫ�ֺ�������������˽�г�Ա
////void GoodGay(Building &Build1) 
////{
////	cout << "�û�������"<<Build1.M_SittingRoom<<"��ˣ��"<<endl;
////	cout << "�û�������" << Build1.M_BedRoom << "��ˣ��" << endl;
////};
////
////void testB1() 
////{
////	Building BUidl;
////	GoodGay(BUidl);
////};
//
//////������Ԫ��
//
////class GoodGay 
////{
////public:
////	void visit() 
////	{
////		cout << "�û�������" << Buidl->M_SittingRoom << endl;
////		cout << "�û�������" << Buidl->M_BedRoom << endl;
////	};
////	Building * Buidl=new(Building);
////};
////void testB2() 
////{
////	Building Build2;
////	GoodGay G1;
////	G1.visit();
////};
//
////���г�Ա��������Ԫ
////��visi�����������Է���building�е�˽�г�Ա
//class Building;
//class GoodGay
//{
//public:
//	GoodGay();//���캯����Ŀ�ľ���Ϊ��Ա��������ֵ��
//	Building * Build01;//��ʱ��δ����Building�࣬���Բ���ֱ�ӿ��ٸ��ڴ�ռ�
//	void visit1();
//	void visit2();//��������
//};
//class Building 
//{
//	friend void GoodGay::visit1();
//public:
//	Building();//Ĭ�Ϲ��캯������
//	string M_SittingRoom;//����
//private:
//	
//	string M_BedRoom;//�»���
//};
//
////���ⶨ�庯��
//GoodGay::GoodGay()
//{
//	Build01 = new(Building);
//};
//Building::Building() 
//{
//	M_SittingRoom = "����";
//	M_BedRoom = "����";
//};
//void GoodGay::visit1() 
//{
//	cout << "�û���һ������" << Build01->M_SittingRoom<<"��ˣ"<<endl;
//	cout << "�û���һ������" << Build01->M_BedRoom << "��ˣ" << endl;//GoodGayҪ������Building֮ǰ��ԭ���в������
//};
//void GoodGay::visit2() 
//{
//	cout << "�û��Ѷ�������" << Build01->M_SittingRoom << "��ˣ" << endl;
//	//cout << "�û��Ѷ�������" << Build01->M_BedRoom << "��ˣ" << endl;
//};
//void T1() 
//{
//	GoodGay G1;
//	G1.visit1();
//	G1.visit2();
//};
////�ܽ᣺
//		//�г�Ա�����ʱ������������һ���ó�Ա�֮࣬���ڶԸó�Ա�������壨GoodGay�е�Buidling��
//		//��ĳһ����û�ж���֮ǰ���޷�ʹ��new�ؼ��ֿ���һ�������ڴ�ռ䣨Building Build01��
//		//�����ⶨ�庯���������ǳ�Ա������ֻ�о�̬��Ա�������������ⶨ�壩
//		//���еĳ�Ա������Ϊ��Ԫʱ��Ҫ��Ӹú�����������

//8.0 ��������أ�����������½��ж��壬������һ�ֹ��ܣ�����Ӧ��ͬ���������ͣ�

//8.1 ��+������

////ͨ����Ա�����������ء�+��
//class person
//{
//public:
//	int M_a;
//	int M_b;
//	int M_c;//����������Ա��������������ӽ��
//	//person operator + (person &p) 
//	//{
//	//		person temp;
//	//		temp.M_a = this->M_a + p.M_a;
//	//		temp.M_b = this->M_b + p.M_b;
//	//		temp.M_c = this->M_c + p.M_c;
//	//		return temp;//��ʱ���ص���һ��ֵ	
//	//};//��Ա��������
//						//ͨ���ó�Ա��������ʵ�������������ӣ��õ�һ���µĶ���
//							//��Ա�������ؾ��ǽ��ó�Ա�����������淶��(ͳһ����Ϊ��operator+�������������������)
//};
//void test01() 
//{
//	person P1,P2;
//	P1.M_a = 10; P1.M_b = 10; P1.M_c = 10;
//	P2.M_a = 10; P2.M_b = 10; P2.M_c = 10;//ʵ�����������󣬲��Ҷ����Ա�������и�ֵ���Լ���������������Ƿ���ȷ
//	person P3;
//	P3 = P1 + P2;
//					//��Ա�������ر��ʣ�person P3=P1.operator+��P2�������򻯳���������ʽ��
//	cout<< "P3.M_a=" << P3.M_a << endl
//		<< "P3.M_b=" << P3.M_b << endl
//		<< "P3.M_c=" << P3.M_c << endl;
//};
//ͨ��������ʽ��ʵ����ͨ����Ա�����������������

//ͨ��ȫ�ֺ��������ء�+��
//person operator+(person &P1,person &P2) //ȫ�ֺ����������������ʱ����Ҫ���������������
//						//ͬ��ȫ�ֺ����������������Ҳ��Ҫͳһ����
//							//�����ط�ʽֻ��ѡ��һ�֣��������ͬһ����������г�Ա�������أ�����ȫ�ֺ������أ��������ͻᱨ��
//{
//	person temp;//�����߼�����
//	temp.M_a = P1.M_a + P2.M_a;
//	temp.M_b = P1.M_b + P2.M_b;
//	temp.M_c = P1.M_c + P2.M_c;
//	return temp;//��ʱ���ص�Ҳ��һ��ֵ
//};
//void test02() 
//{
//	person P1, P2;
//	P1.M_a = 10; P1.M_b = 10; P1.M_c = 10;
//	P2.M_a = 10; P2.M_b = 10; P2.M_c = 10;
//	person P3;
//	P3 = P1 + P2;
//				//ȫ�ֺ������ر��ʣ�person P3=operator+��P1��P2����
//	cout <<"P3.M_a="<< P3.M_a<<endl
//		<<"P3.M_b="<<P3.M_b<<endl
//		<<"P3.M_c="<<P3.M_c<<endl;
//};
//ͨ��ȫ�ֺ����������������over
//person operator+(person &p1, int num)//��ʱ��Ҫ���βν��й涨������Ŀ���� 
//{
//	person temp;//�����߼�����
//	temp.M_a = p1.M_a + num;
//	temp.M_b = p1.M_b + num;
//	temp.M_c = p1.M_c + num;
//	return temp;//��ʱ���ص�Ҳ��һ��ֵ
//};
////���������Ҳ���Է�����������(�Ժ������ĸ���)
////��+�ĵ���������
////���������+���ٴ�����֮�󣬾Ͳ��ᱨ����
//void test03()
//{
//	person P11;
//	person P22;
//	P11.M_a = 10; P11.M_b = 10; P11.M_c = 10;
//	P22.M_a = 10; P22.M_b = 10; P22.M_c = 10;
//	P22 = P11 + 100;//��ʱ����ᱨ����Ϊ��һ��person+int���������Ͳ�ͬ��
//					//����������������������������Ҫ������������صķ�ʽ����+���е��������أ�ʹ�����ܹ��������ֲ�ͬ�������ݽ��в���
//
//	cout << "P22.M_a=" << P22.M_a << endl
//		 <<"P22.M_b="<<P22.M_b<<endl
//		 <<"P22.M_c="<<P22.M_c<<endl;
//
//};
//Tips:�������õ��������ͣ�int��char...���ǲ��ܷ�����������صģ���Ҫ�������������

//8.2 ���ƣ�<<�����������(��������Զ�����������)

//class Person2 
//{
//public:
//	int M_a;
//	int M_b;
//	//���ó�Ա��������<<
//	//Tips:������庯��ʱ����̫���Ӧ�÷���ʲô��������дvoid
//	//void operator<< (Person2 &P) {};
//		//�����޷�ʵ��ʹ�ó�Ա����������<<���أ���Ϊ�޷�ʵ��cout����࣬�Ҳ�֪���ô���ʲô������Ҳ��֪���÷���ʲô
//				//�������һ��������ô�ͳ���һ���������������������һ�Ҫ�ڴ��������P.operator(P)��������������ԭ���������
//			//��ˣ�һ�㲻���ó�Ա�����������������
//};
////ֻ������ȫ�ֺ�������<<�����
//ostream &operator<< (ostream &cout,Person2 &P)//���ʣ�operator<<(cout,P),�򻯣�cout<<P 
//			//������Ƕ��󣬽Կ���Ϊ������cout�Ǳ�׼�����������
//{
//	cout << "P.M_a=" << P.M_a << endl
//		 << "P.M_b=" << P.M_b << endl;
//	return cout;//�˴�Ҳ��ǿ�Ʊ�����cout����Ϊ�������������ã�������������������ã����Կ�������������
//};
//void test03() 
//{
//	Person2 P21;
//	P21.M_a = 10; P21.M_b = 20;
//	//cout << P21;//����
//	//ͨ������<<ʹ��cout��ֱ�����P21���������ڶԳ�Ա����������
//	cout << P21;//������<<����֮�󣬾Ͳ����ٱ���
//		//���Ǵ�ʱ���治��������κζ���
//	//cout << P21 << endl;��ʱ�����򱨴���Ϊ������<<ʱ�����ص�����������void
//			//�������Ҫ������ʽ���˼�룬����Ҫ�ѷ���ֵ���͸�Ϊcout���ͣ���������Ϳ������������
//				//���Դ�ʱ����ֵ������ostream &��Ϊʲô�����ã�Ŀǰ�ҽ��Ͳ��ˣ�
//	cout << P21 << "Hello World" << endl;
//};
//��������������ԣ�һ���ǽ����Ա��������Ϊ˽�л���ͨ�������ӿ����Գ�Ա���Խ��ж�д
	//��������������غ������ԣ�����ͨ����Ԫ�Ĳ�����ʹ��ֱ�ӷ������е�˽�г�Ա

//8.3 �����������++�����أ��ݼ����ƣ�

//�Զ�������
//class MyInteger 
//{
//	friend ostream & operator<< (ostream & cout, MyInteger & M1);
//public:
//	MyInteger()
//	{
//		M_Num = 0;
//	};//���캯��
//	//��Ա��������ǰ��++
//	MyInteger& operator++()//����Ҫ���������why��(�Ǹ������Ľ����ȷ���Ƿ���Ҫ����)
//		//ע�ⷵ��ֵҲ���������ͣ���Ϊ�Ƕ�ͬһ���������ͽ��еĲ���
//	{
//		//Ŀ������������������+1����
//		M_Num++;//��ʱĿ�Ĳ����Ѿ�ִ����ϣ����ǲ�û�з��أ�������Ҫ����voidΪint����M_Num����
//		return *this;
//	};
//
//	//��Ա�������غ���++
//	MyInteger operator++ (int) //int����ռλ��������������ǰ�úͺ���
//						//��Ϊ���ö���ʹ��һ����ʱ��������¼�����ڵ���ǰ��ֵ�����Բ��ܷ������ã�ֻ�ܷ���ֵ
//	{
//		//����++�߼����������ǰֵ���ڽ���+1����
//		MyInteger * temp = this;//��¼��ǰֵ
//		M_Num++;
//		return *temp;
//	};
//private:
//	int M_Num;
//};
////����<<�����
//ostream & operator<< (ostream& cout, MyInteger & Mm)//ע�⴫������ͷ���ֵ�����������ͣ���Ϊ��Ψһ�ģ�cout��Ψһ�ģ�<<Ҳ��Ψһ�ģ�
//								//���������صĲ����������ͣ����൱����������һ������ϵͳ�ͻ���Ϊ֮ǰ���Ѿ�����ʹ����
//{
//	cout << Mm.M_Num << endl;
//	return cout;
//};
//void test04()
//{
//	MyInteger M1;
//	cout << M1;
//	cout << ++M1;
//	//cout << M1++;
//	//Ϊʲô����ʹ��cout���M1++
//};
////��ʱ�Զ�����һ�������������ͣ����ǲ�����++���㣬��Ϊ������������ʶ�����Զ�����������
//		//�����Ҫ��++�����أ��Ծ��ǳ�Ա�������غ�ȫ�ֺ����������ַ�ʽ����++��Ϊǰ�úͺ������֣�
//
//void test05() 
//{
//	MyInteger myint;
//	cout << myint;
//	cout << ++myint;
//};
//ǰ�õ����������ã����õ�������ֵ

//8.4 ��ֵ��������أ�operator=�Ǳ�����Ĭ���ṩ�ĵ��ĸ�������

//class person007 
//{
//public:
//	person007(int age)
//	{
//		M_Age = new int(age);
//	};//�вι��캯��
//	~person007()
//	{
//		if (M_Age!=NULL)
//		{
//			delete M_Age;
//			M_Age = NULL;
//		}
//		
//	}
//	//���ظ�ֵ�����
//	person007& operator= (person007 &P) //Ӧ�÷�����������Ҫ����������
//	{
//		//�������ṩ����ǳ����������ֱ��ʹ��
//		//������ж��Ƿ��������ڶ�������������ǷŸɾ���Ȼ���ٽ������
//		if (M_Age!=NULL)
//		{
//			delete M_Age;
//			M_Age = NULL;
//		}
//		M_Age = new int(*P.M_Age);//��������¿���һ���ڴ棩
//
//		return *this;//����������ȷ���������޸�ֵ�����ȣ�
//		
//	};
//	int * M_Age;
//};
//void test07() 
//{
//	person007 PP7(18);//ʹ���вι��캯���ķ�ʽ���ɶ���
//	
//	person007 PP8(20);
//	person007 PP9(20);
//	PP9 = PP8=PP7;//��ֵ����
//	cout << *PP8.M_Age << endl;
//	cout << *PP7.M_Age << endl;//����˶����ڴ���ظ��ͷţ�����������������Ϊ�������ṩ�ĸ�ֵ�������ǳ������
//
//
//};

//8.5 ��ϵ���������

//class person008 
//{
//public:
//	person008(string  Name,int a) 
//	{
//		M_Name = Name;
//		M_Age = M_Age;
//	};//�вι��캯��
//	int M_Age;
//	string M_Name;
//	bool operator==(person008 &P) 
//	{
//		if (this->M_Age==P.M_Age&&this->M_Name==P.M_Name)
//		{
//			return true;
//		}
//		else
//		{
//			return false;
//		}
//	};
//	bool operator!= (person008 &P)
//	{
//		if (this->M_Age != P.M_Age || this->M_Name != P.M_Name)
//		{
//			return true;
//		}
//		else
//		{
//			return false;
//		}
//	};
//
//};
//
//
//void test008() 
//{
//	person008 PL1("��ľ",18);
//	person008 PL2("��ľ",18);
//	if (PL1==PL2)
//	{
//		cout << "������һ���ģ�����" << endl;
//	}
//	else
//	{
//		cout << "���ǲ���һ��������" << endl;
//	}
//	if (PL1 != PL2)
//	{
//		cout << "�����ǲ�һ���ģ�����" << endl;
//	}
//	else
//	{
//		cout << "������һ��������" << endl;
//	}
//};

//8.6 ����������������أ����������������()����()���غ��Ϊ�º�����

class MyPrint 
{
public:
	//���غ����������������()
	void operator() (string test)
	{
		cout << test << endl;
	};
};

void MyPrint02 (string test)
{
	cout << test << endl;
};
void testPr() 
{
	MyPrint myprint;
	myprint("Hello World!");//()������
	MyPrint02("Hello World!!!!");//��������
	//���ڶ���ʹ�������ǳ����ƣ���˳�()����Ϊ�º���
	//������������
	 MyPrint()("Bye!");

};
//�º����ǳ���û�й̶���д��
class MyAdd 
{
public:
	int operator()(int a,int b) 
	{
		return a + b;
	};
};
void testMa() 
{
	MyAdd myadd;
	myadd(10,20);
	int temp= myadd(10, 20);
	cout << temp << endl;

}
int main()
{
	//testB1();
	//testB2();
	//T1();
	//test008();
	//test01();//���ò��Ժ��������������صĽ��
	//test02();
	//test03();
	//test03();
	//test04();
	//test05();
	//test07();
	testPr();
	testMa();
	cout << endl;
	system("pause");
	return 0;
}



