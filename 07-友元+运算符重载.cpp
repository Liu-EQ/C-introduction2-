#include<iostream>
#include<string>
using  namespace std;




//7.0 友元（然后给一个函数或者类可以访问另一个类中私有成员）

////关键字：friend
////三种实现：
////全局函数做友元；
//
////class Building 
////{
////	friend void GoodGay(Building &Build1);//声明了GoodGay这个全局函数是Building的好朋友，可以访问他的私有成员
////			//这句代码可以放在任意处
////	friend class GoodGay;//声明了GoodGay这个类是Building的好朋友，可以访问他的私有成员
////public:
////	//friend void GoodGay(Building &Build1);//声明了GoodGay这个全局函数是Building的好朋友，可以访问他的私有成员
////	Building() 
////	{
////		M_SittingRoom = "客厅";
////		M_BedRoom = "卧室";
////	};
////public:
////	string M_SittingRoom;//客厅
////private:
////	//friend void GoodGay(Building &Build1);//声明了GoodGay这个全局函数是Building的好朋友，可以访问他的私有成员
////	string M_BedRoom;//卧室
////};
//////定义一个全局函数，访问类中私有成员
////void GoodGay(Building &Build1) 
////{
////	cout << "好基友正在"<<Build1.M_SittingRoom<<"玩耍！"<<endl;
////	cout << "好基友正在" << Build1.M_BedRoom << "玩耍！" << endl;
////};
////
////void testB1() 
////{
////	Building BUidl;
////	GoodGay(BUidl);
////};
//
//////类做友元；
//
////class GoodGay 
////{
////public:
////	void visit() 
////	{
////		cout << "好基友正在" << Buidl->M_SittingRoom << endl;
////		cout << "好基友正在" << Buidl->M_BedRoom << endl;
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
////类中成员函数做友元
////让visi（）函数可以访问building中的私有成员
//class Building;
//class GoodGay
//{
//public:
//	GoodGay();//构造函数（目的就是为成员变量赋初值）
//	Building * Build01;//此时尚未定义Building类，所以不能直接开辟该内存空间
//	void visit1();
//	void visit2();//函数声明
//};
//class Building 
//{
//	friend void GoodGay::visit1();
//public:
//	Building();//默认构造函数声明
//	string M_SittingRoom;//客厅
//private:
//	
//	string M_BedRoom;//下划线
//};
//
////类外定义函数
//GoodGay::GoodGay()
//{
//	Build01 = new(Building);
//};
//Building::Building() 
//{
//	M_SittingRoom = "客厅";
//	M_BedRoom = "卧室";
//};
//void GoodGay::visit1() 
//{
//	cout << "好基友一号正在" << Build01->M_SittingRoom<<"玩耍"<<endl;
//	cout << "好基友一号正在" << Build01->M_BedRoom << "玩耍" << endl;//GoodGay要定义在Building之前（原因尚不清楚）
//};
//void GoodGay::visit2() 
//{
//	cout << "好基友二号正在" << Build01->M_SittingRoom << "玩耍" << endl;
//	//cout << "好基友二号正在" << Build01->M_BedRoom << "玩耍" << endl;
//};
//void T1() 
//{
//	GoodGay G1;
//	G1.visit1();
//	G1.visit2();
//};
////总结：
//		//有成员类存在时，可以先声明一个该成员类，之后在对该成员类做定义（GoodGay中的Buidling）
//		//在某一个类没有定义之前，无法使用new关键字开辟一块该类的内存空间（Building Build01）
//		//在类外定义函数，而不是成员变量（只有静态成员变量才能在类外定义）
//		//类中的成员函数作为友元时，要添加该函数的作用域

//8.0 运算符重载（给运算符重新进行定义，赋予另一种功能，以适应不同的数据类型）

//8.1 ‘+’重载

////通过成员函数进行重载‘+’
//class person
//{
//public:
//	int M_a;
//	int M_b;
//	int M_c;//定义三个成员变量，检测对象相加结果
//	//person operator + (person &p) 
//	//{
//	//		person temp;
//	//		temp.M_a = this->M_a + p.M_a;
//	//		temp.M_b = this->M_b + p.M_b;
//	//		temp.M_c = this->M_c + p.M_c;
//	//		return temp;//此时返回的是一个值	
//	//};//成员函数声明
//						//通过该成员函数就能实现两个对象的相加，得到一个新的对象
//							//成员函数重载就是将该成员函数的命名规范化(统一命名为：operator+（可以是其他运算符）)
//};
//void test01() 
//{
//	person P1,P2;
//	P1.M_a = 10; P1.M_b = 10; P1.M_c = 10;
//	P2.M_a = 10; P2.M_b = 10; P2.M_c = 10;//实例化两个对象，并且对其成员变量进行赋值。以检验最后的相加运算是否正确
//	person P3;
//	P3 = P1 + P2;
//					//成员函数重载本质：person P3=P1.operator+（P2）；（简化成了上述形式）
//	cout<< "P3.M_a=" << P3.M_a << endl
//		<< "P3.M_b=" << P3.M_b << endl
//		<< "P3.M_c=" << P3.M_c << endl;
//};
//通过上述方式就实现了通过成员函数进行运算符重载

//通过全局函数来重载‘+’
//person operator+(person &P1,person &P2) //全局函数进行运算符重载时，需要传入的是两个对象
//						//同样全局函数进行运算符重载也需要统一命名
//							//但重载方式只能选择一种，如果对于同一个运算符既有成员函数重载，又有全局函数重载，编译器就会报错
//{
//	person temp;//整体逻辑相似
//	temp.M_a = P1.M_a + P2.M_a;
//	temp.M_b = P1.M_b + P2.M_b;
//	temp.M_c = P1.M_c + P2.M_c;
//	return temp;//此时返回的也是一个值
//};
//void test02() 
//{
//	person P1, P2;
//	P1.M_a = 10; P1.M_b = 10; P1.M_c = 10;
//	P2.M_a = 10; P2.M_b = 10; P2.M_c = 10;
//	person P3;
//	P3 = P1 + P2;
//				//全局函数重载本质：person P3=operator+（P1，P2）；
//	cout <<"P3.M_a="<< P3.M_a<<endl
//		<<"P3.M_b="<<P3.M_b<<endl
//		<<"P3.M_c="<<P3.M_c<<endl;
//};
//通过全局函数重载运算符——over
//person operator+(person &p1, int num)//此时需要对形参进行规定，以满目需求 
//{
//	person temp;//整体逻辑相似
//	temp.M_a = p1.M_a + num;
//	temp.M_b = p1.M_b + num;
//	temp.M_c = p1.M_c + num;
//	return temp;//此时返回的也是一个值
//};
////运算符重载也可以发生函数重载(对函数名的复用)
////对+的第三次重载
////有了上面的+的再次重载之后，就不会报错了
//void test03()
//{
//	person P11;
//	person P22;
//	P11.M_a = 10; P11.M_b = 10; P11.M_c = 10;
//	P22.M_a = 10; P22.M_b = 10; P22.M_c = 10;
//	P22 = P11 + 100;//此时程序会报错，因为是一个person+int（数据类型不同）
//					//而如果向正常运行这类操作，就需要仿照运算符重载的方式：对+进行第三次重载，使得它能过够对两种不同类型数据进行操作
//
//	cout << "P22.M_a=" << P22.M_a << endl
//		 <<"P22.M_b="<<P22.M_b<<endl
//		 <<"P22.M_c="<<P22.M_c<<endl;
//
//};
//Tips:对于内置的数据类型（int，char...）是不能发生运算符重载的；不要滥用运算符重载

//8.2 左移（<<）运算符重载(可以输出自定义数据类型)

//class Person2 
//{
//public:
//	int M_a;
//	int M_b;
//	//利用成员函数重载<<
//	//Tips:如果定义函数时，不太清楚应该返回什么，可以先写void
//	//void operator<< (Person2 &P) {};
//		//发现无法实现使用成员函数来进行<<重载，因为无法实现cout在左侧，且不知道该传入什么参数，也不知道该返回什么
//				//如果传入一个对象，那么就成了一个对象调用这个函数，而且还要在传入对象本身（P.operator(P)——不能这样（原因不清楚））
//			//因此，一般不适用成员函数进行运算符重载
//};
////只能利用全局函数重载<<运算符
//ostream &operator<< (ostream &cout,Person2 &P)//本质：operator<<(cout,P),简化：cout<<P 
//			//万物皆是对象，皆可作为参数（cout是标准的输出流对象）
//{
//	cout << "P.M_a=" << P.M_a << endl
//		 << "P.M_b=" << P.M_b << endl;
//	return cout;//此处也不强制必须是cout，因为返回类型是引用，而引用是起别名的作用，所以可以是任意名字
//};
//void test03() 
//{
//	Person2 P21;
//	P21.M_a = 10; P21.M_b = 20;
//	//cout << P21;//报错
//	//通过重载<<使得cout能直接输出P21，而不用在对成员变量逐个输出
//	cout << P21;//进行了<<重载之后，就不会再报错
//		//但是此时后面不能再添加任何东西
//	//cout << P21 << endl;此时，程序报错：因为在重载<<时，返回的数据类型是void
//			//所以如果要满足链式编程思想，就需要把返回值类型改为cout类型，这样后面就可以无限输出了
//				//所以此时返回值类型是ostream &（为什么是引用，目前我解释不了）
//	cout << P21 << "Hello World" << endl;
//};
//其他：对于类而言，一般是将其成员属性设置为私有化，通过公共接口来对成员属性进行读写
	//而对于运算符重载函数而言，可以通过友元的操作，使其直接访问类中的私有成员

//8.3 递增运算符（++）重载（递减相似）

//自定义整型
//class MyInteger 
//{
//	friend ostream & operator<< (ostream & cout, MyInteger & M1);
//public:
//	MyInteger()
//	{
//		M_Num = 0;
//	};//构造函数
//	//成员函数重载前置++
//	MyInteger& operator++()//不需要传入参数（why）(是根据最后的结果来确定是否需要传参)
//		//注意返回值也是引用类型，因为是对同一个数据类型进行的操作
//	{
//		//目的是想让整形数据做+1操作
//		M_Num++;//此时目的操作已经执行完毕，但是并没有返回，所以需要更改void为int，将M_Num返回
//		return *this;
//	};
//
//	//成员函数重载后置++
//	MyInteger operator++ (int) //int代表占位参数，用以区分前置和后置
//						//因为后置对象使用一个临时变量来记录变量在递增前的值，所以不能返回引用，只能返回值
//	{
//		//后置++逻辑：先输出当前值，在进行+1操作
//		MyInteger * temp = this;//记录当前值
//		M_Num++;
//		return *temp;
//	};
//private:
//	int M_Num;
//};
////重载<<运算符
//ostream & operator<< (ostream& cout, MyInteger & Mm)//注意传入变量和返回值都是引用类型，因为是唯一的（cout是唯一的，<<也是唯一的）
//								//因此如果返回的不是引用类型，就相当于生成了另一个它，系统就会认为之前的已经不能使用了
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
//	//为什么不能使用cout输出M1++
//};
////此时自定义了一个整型数据类型，但是不能做++运算，因为编译器并不认识这种自定义数据类型
//		//因此需要对++做重载（仍旧是成员函数重载和全局函数重载两种方式）（++分为前置和后置两种）
//
//void test05() 
//{
//	MyInteger myint;
//	cout << myint;
//	cout << ++myint;
//};
//前置递增返回引用，后置递增返回值

//8.4 赋值运算符重载（operator=是编译器默认提供的第四个函数）

//class person007 
//{
//public:
//	person007(int age)
//	{
//		M_Age = new int(age);
//	};//有参构造函数
//	~person007()
//	{
//		if (M_Age!=NULL)
//		{
//			delete M_Age;
//			M_Age = NULL;
//		}
//		
//	}
//	//重载赋值运算符
//	person007& operator= (person007 &P) //应该返回自身，所以要是引用类型
//	{
//		//编译器提供的是浅拷贝，不能直接使用
//		//因该先判断是否有属性在堆区，如果有先是放干净，然后再进行深拷贝
//		if (M_Age!=NULL)
//		{
//			delete M_Age;
//			M_Age = NULL;
//		}
//		M_Age = new int(*P.M_Age);//深拷贝（重新开辟一块内存）
//
//		return *this;//返回自身，以确保可以无限赋值（连等）
//		
//	};
//	int * M_Age;
//};
//void test07() 
//{
//	person007 PP7(18);//使用有参构造函数的方式生成对象
//	
//	person007 PP8(20);
//	person007 PP9(20);
//	PP9 = PP8=PP7;//赋值操作
//	cout << *PP8.M_Age << endl;
//	cout << *PP7.M_Age << endl;//造成了堆区内存的重复释放，编译器报错（就是因为编译器提供的赋值运算符是浅拷贝）
//
//
//};

//8.5 关系运算符重载

//class person008 
//{
//public:
//	person008(string  Name,int a) 
//	{
//		M_Name = Name;
//		M_Age = M_Age;
//	};//有参构造函数
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
//	person008 PL1("青木",18);
//	person008 PL2("青木",18);
//	if (PL1==PL2)
//	{
//		cout << "他们是一样的！！！" << endl;
//	}
//	else
//	{
//		cout << "他们并不一样！！！" << endl;
//	}
//	if (PL1 != PL2)
//	{
//		cout << "他们是不一样的！！！" << endl;
//	}
//	else
//	{
//		cout << "他们是一样！！！" << endl;
//	}
//};

//8.6 函数调用运算符重载（函数调用运算符是()）（()重载后称为仿函数）

class MyPrint 
{
public:
	//重载函数调用运算符——()
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
	myprint("Hello World!");//()的重载
	MyPrint02("Hello World!!!!");//函数调用
	//由于二者使用起来非常相似，因此称()——为仿函数
	//匿名函数对象
	 MyPrint()("Bye!");

};
//仿函数非常灵活，没有固定的写法
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
	//test01();//调用测试函数检测运算符重载的结果
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



