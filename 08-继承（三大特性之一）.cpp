#include<iostream>
#include<string>
using namespace std;

//8.0 继承 （下级成员有上级成员的共性）

//8.1 继承初实现

//普通实现一个网课页面（Java、Python、C++）
//Java
//class Java 
//{
//public:
//	void Head()
//	{
//		cout << "这是网页的头部！！！" << endl;
//	};
//	void Foot() 
//	{
//		cout << "这是网页的底部！！！" << endl;
//	};
//	void Left() 
//	{
//		cout << "这是网页的侧边导航栏！！！" << endl;
//	};
//	void content()
//	{
//		cout << "这是Java的学科内容！！！" << endl;
//	};
//};
//void testJ() 
//{
//	Java J;
//	cout << "这是Java精品课的内容！！！"<<endl;
//	J.Head();
//	J.Foot();
//	J.Left();
//	J.content();
//};
////Python
//class Python
//{
//public:
//	void Head()
//	{
//		cout << "这是网页的头部！！！" << endl;
//	};
//	void Foot()
//	{
//		cout << "这是网页的底部！！！" << endl;
//	};
//	void Left()
//	{
//		cout << "这是网页的侧边导航栏！！！" << endl;
//	};
//	void content()
//	{
//		cout << "这是Python的学科内容！！！" << endl;
//	};
//};
//void testP()
//{
//	Python P;
//	cout << "这是Python精品课的内容！！！" << endl;
//	P.Head();
//	P.Foot();
//	P.Left();
//	P.content();
//};
////C++
//class Cpp
//{
//public:
//	void Head()
//	{
//		cout << "这是网页的头部！！！" << endl;
//	};
//	void Foot()
//	{
//		cout << "这是网页的底部！！！" << endl;
//	};
//	void Left()
//	{
//		cout << "这是网页的侧边导航栏！！！" << endl;
//	};
//	void content()
//	{
//		cout << "这是C++的学科内容！！！" << endl;
//	};
//};
//void testC()
//{
//	Cpp Cp;
//	cout << "这是C++精品课的内容！！！" << endl;
//	Cp.Head();
//	Cp.Foot();
//	Cp.Left();
//	Cp.content();
//};

//继承实现一个页面
 //公共页面类
//class BasePage 
//{
//public:
//	void Head()
//	{
//		cout << "这是网页的头部！！！" << endl;
//	};
//	void Foot() 
//	{
//		cout << "这是网页的底部！！！" << endl;
//	};
//	void Left() 
//	{
//		cout << "这是网页的侧边导航栏！！！" << endl;
//	};
//};
// //Java页面类
//class Java2 :public BasePage //继承语法
//{
//public:
//	void Contest()
//	{
//		cout << "这是Java的学科内容！！！" << endl;
//	};
//};
//void testJ2()
//{
//	Java2 J2;
//	cout << "这是Java精品课的内容！！！"<<endl;
//	J2.Head();
//	J2.Foot();
//	J2.Left();
//	J2.Contest();
//};
////Python页面类
//class Python :public BasePage //继承语法
//{
//public:
//	void Contest()
//	{
//		cout << "这是Python的学科内容！！！" << endl;
//	};
//};
//void testP2()
//{
//	Python P2;
//	cout << "这是Python精品课的内容！！！" << endl;
//	P2.Head();
//	P2.Foot();
//	P2.Left();
//	P2.Contest();
//};
////C++页面类
//class Cpp :public BasePage //继承语法
//{
//public:
//	void Contest()
//	{
//		cout << "这是C++的学科内容！！！" << endl;
//	};
//};
//void testC2()
//{
//	Cpp Cp2;
//	cout << "这是++精品课的内容！！！" << endl;
//	Cp2.Head();
//	Cp2.Foot();
//	Cp2.Left();
//	Cp2.Contest();
//};
//class Java:public BasePage{}（继承语法：class 子类类名:public（继承方式，不仅仅有public） 父类类名）
			//子类——派生类；父类——基类
//继承可以减少重复代码；派生类包含两大部分——从父类中继承的和自己中特有的

//8.2 继承方式（公共继承（public）、保护继承(protected)、私有继承(private)、）

////规则：
//	//1、不论采用那种继承方式，都无法访问到父类中的私有成员；
//	//2、采用公共继承方式，父类中的非私有成员的权限并不发生变化（即公共权限仍为公共权限、保护权限仍为保护权限）；
//	//3、采用保护继承方式，父类中的非私有成员的权限全部变为保护权限（即公共权限变为保护权限，保护权限仍为保护权限）；
//	//4、才有私有继承方式，父类中的非私有成员的权限全部变为私有权限（即公共权限变为私有权限，保护权限变为私有权限）
//			//此时如果再有孙子类继承子类中内容，会什么也无法从子类中得到继承（因为此时子类中的所有内容都成为了私有权限）
////保护权限和私有权限的内容，在类外是无法访问的；继承中，子类是可以访问父类中保护权限的内容，但是不能访问私有权限的内容
////示例：
////公共继承
//class Pub
//{
//public:
//	int M_a;
//protected:
//	int M_b;
//private:
//	int M_c;
//};//父类
//class Pubson : public Pub//公共继承方式继承父类
//{
//	//所继承到的属性会保持原有权限
//	void func() 
//	{
//		M_a = 100;
//		M_b = 100;//父类中的公共权限属性和保护权限属性，子类都是可以正常访问的
//				//为什么不能直接赋值，需要另有一个成员函数进行赋值
//		//M_c = 100;//父类中的四有权限属性在子类中是不可以访问的
//	};
//};
//void testPub() 
//{
//	Pubson son1;
//	son1.M_a = 100;//公共权限的属性在类内类外都可以访问
//	//son1.M_b = 100;//采用公共继承后父类中保护权限属性仍未保护权限，类外不可访问
//
//};
////保护继承
//class Father
//{
//public:
//	int M_a;
//protected:
//	int M_b;
//private:
//	int M_c;
//};//父类
//class ProSon:protected Father 
//{
//	void func2() 
//	{
//		M_a = 10;
//		M_b = 10;
//		//M_c = 10;//无论哪种继承方式都无妨访问父类中的私有属性
//	};
//};
//void testPro()
//{
//	ProSon P1;
//	//P1.M_a = 10;//保护继承方式从父类中继承到的所有属性都是保护权限，类外不可访问
//	//P1.M__b = 20;//同上
//	//P1.M_c = 10;//同上
//};
////私有继承
//class PriSon : private Father
//{
//	void func3() 
//	{
//		M_a = 10;
//		M_b = 10;
//		//M_c = 10;//无论哪种继承方式都无妨访问父类中的私有成员
//	};
//};
//void testPri() 
//{
//	PriSon PP1;
//	//PP1.M_a = 10;//私有继承方式从父类中继承的属性都是私有权限，类外不可访问
//	//PP1.M_b = 10;//同上
//	//PP1.M_c = 10;//同上
//};

//8.3 继承中的对象模型

//父类中所有成员都被子类给继承过去了（包括私有成员），只是有些被编译器隐藏了，我们访问不到
//class father 
//{
//public:
//	int M_a;
//protected:
//	int M_b;
//private:
//	int M_c;
//};//父类
//class son :public father
//{
//public:
//	int M_d;
//};
//void testS1() 
//{
//	son SS1;
//	cout << "新建子类SS1所占内存空间为：" <<sizeof(SS1)<< endl;
//};

//8.4 继承中构造和析构的顺序

//继承中构造顺序：先构造父类，再构造子类；析构时：先析构子类，后析构父类
//class father 
//{
//public:
//	father() 
//	{
//		cout << "father中的默认构造函数！！！" << endl;
//	};
//	~father()
//	{
//		cout << "father中的析构函数！！！" << endl;
//	}
//
//};
//class son :public father
//{
//public:
//	son() 
//	{
//		cout << "son中的默认构造函数！！！" << endl;
//	};
//	~son()
//	{
//		cout << "son中的析构函数！！！" << endl;
//	}
//
//};
//void test001() 
//{
//	son aa1;
//};

//8.5 继承中同名成员处理方式（解决子类父类中出现同名成员的问题）

//子类中的同名成员——直接访问；父类中的同名成员——添加作用域
//class father 
//{
//public:
//	int M_a;
//	father() 
//	{
//		M_a = 20;
//	};
//	void func1() 
//	{
//		cout << "父类中的func函数！！！" << endl;
//	};
//	void func1(int a)
//	{
//		cout << "父类中的func(int a)函数！！！" << endl;
//	};
//};
//class son :public father
//{
//public:
//	int M_a;
//	son() 
//	{
//		M_a = 10;
//	};
//	void func1() 
//	{
//		cout << "子类中的func函数！！！" << endl;
//	};
//};
//
//void test85() 
//{
//	son S85;
//	cout << "son中M_a的值为：" <<S85.M_a<< endl;
//	cout << "father中M_a的值为：" <<S85.father::M_a<< endl;
//	S85.func1();
//	S85.father::func1();
//	S85.father::func1(100);
//};
//子类中的同名成员函数会隐藏掉父类中的所有同名成员函数（包括函数重载），如果想要访问父类中的同名成员函数，需要添加作用域

//8.6 继承中静态同名成员处理方式(与非静态同名成员处理方式完全一致)

//静态成员变量特点：所有对象共享同一份数据；编译阶段就分配内存；类内声明，类外初始化；
//静态成员函数特点：静态成员函数只能访问静态成员变量；所有对象共享同一份函数实例
//同非静态成员一样，子类中的所有同名成员函数也会隐藏掉所有父类中的同名成员函数，如果想要访问也是要添加作用域
//class father
//{
//public:
//	static int M_a;
//	static void func()
//	{
//		cout << "父类中的func函数！！！！" << endl;
//	};
//	static void func(int a)
//	{
//		cout << "父类中的func（int a）函数！！！" << endl;
//	};
//};
//int father::M_a = 2000;//静态成员变量类内声明，类外初始化
//
//class son :public father
//	{
//	public:
//		static int M_a;
//		static void func() 
//		{
//			cout << "子类中func函数！！！" << endl;
//		};
//		
//	};
//int son::M_a = 10;
//void test86() 
//{
//	//访问静态成员有两种方式
//	//通过对象进行访问
//	son S1;
//	cout << "S1.M_a=" << S1.M_a << endl;
//	cout << "father.M_a=" << S1.father::M_a << endl;
//	S1.func();
//	S1.father::func();
//	S1.father::func(100);
//	//通过类名进行访问
//	cout << "子类中静态成员变量M_a=" << son::M_a << endl;
//	cout << "父类中静态成员变量M_a=" << son::father::M_a << endl;
//	cout << "子类中静态成员函数func为："; 
//	son::func() ;
//	cout << "父类中静态成员函数func为：";
//	son::father::func() ;
//	cout << "父类中静态成员函数func(int a)为：";
//	son::father::func(100);
//};
//注意静态成员关键字 static的写法以及静态成员变量初始化的方法

//8.7 多继承语法

//语法：class 子类：继承方式 父类1，继承方式 父类2，继承方式 父类3......
//多继承语法可能会引发父类中的有同名成员出现，需要添加作用域区分（实际开发中不建议使用多继承）
//class father1
//{
//public:
//	father1() 
//	{
//		M_a = 10;
//	}
//	int M_a;
//};//父类1
//class father2
//{
//public:
//	father2() 
//	{
//		M_a = 20;
//	};
//	int M_a;
//};//父类2
//class son :public father1, public father2
//{
//public:
//	son() 
//	{
//		M_a = 30;
//	};
//
//	int M_a;
//};
//void test87() 
//{
//	son SSS;
//	cout << "子类中M_a为：" << SSS.M_a << endl;
//	cout << "父类1中M_a为：" << SSS.father1::M_a << endl;
//	cout << "父类2中M_a为：" << SSS.father2::M_a << endl;
//};

// 8.8 菱形继承（两个子类继承了同一个父类，又有一个孙子类继承了两个子类，这种继承方式称为菱形继承）
//经典案例：
//问题:菱形继承会导致孙子类（最底层子类）继承两份父类（最高层父类）的数据，导致资源浪费，且多余数据毫无意义
//解决方式：在子类继承父类时，添加vitural关键字，是子类初次继承变为虚继承，此时父类就变为了虚基类，这样最后的孙子类就只会得到一份虚基类的数据
//底层逻辑：添加了virtual关键字之后，孙子类从子类集成到的就成为了两个需基类指针，这两份虚基类指针指向各自的虚基类表，虚基类表中记载了一个偏移量，最终都指向父类中的一份数据

class Anmial 
{
public:
	int M_a;
};
class Sheep : virtual public Anmial
{
public:
	Sheep() 
	{
		M_a = 20;
	};
};
class Tuo : virtual public Anmial
{
public:
	Tuo() 
	{
		M_a = 20000;
	};
};
class CNM111 :public Sheep,public Tuo
{
public:
	CNM111() 
	{
		M_a = 6;//此时就会因为从sheep和tuo中继承了两份M_a数据而无法识别当前的赋值语句
				//要解决此类方法，需要使用virtual关键字来解决重复继承的问题
	};
};
void test88() 
{
	CNM111 cnm1;
	cout << "cnm1中的M_a为：" << cnm1.M_a << endl;
};



int main() 
{
	
	//*testJ();
	//cout << "————————————————————————" << endl;
	//testP();
	//cout << "————————————————————————" << endl;
	//testC()*/;
	//testJ2();
	//cout << "————————————————————————" << endl;
	//testP2();
	//cout << "————————————————————————" << endl;
	//testC2();
	//testS1();
	//test001();
	//test85();
	//test86();
	//test87();
	test88();


	cout << endl;
	system("pause");
	return 0;
}