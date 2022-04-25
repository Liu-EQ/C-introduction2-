#include<iostream>
#include<string>
using namespace std; 


//4.0 类和对象（重要）
//C++面向对象的三大特性为：封装、继承、多态
//C++认为万事万物皆为对象，单反是对象就会有其属性和行为

//4.1 封装

//封装的意义一：将属性和行为作为一个整体，表现生活中的事物；

//语法：class 类名{访问权限：属性/行为}；
//案例一：设计一个圆类，求园的周长
		//分析：求圆的周长：1、知道求圆周长公式（C=2Πr）；2、明确所涉及的量的意义：Π为常量，不用定义，r为圆的半径（不同的圆，r不同）
									                         //c也可以视为圆的一个属性，
											//Tips：规定一个类的属性是，要根据实际需求，如果用不到某些属性，可以不用写
const double PI = 3.14159;//圆周率
//开始设计圆类：（使用关键字class创建类）  class 类名
class Circle
{
public://访问权限：公共权限
	int radius;//属性:圆的半径
	double circle_C()
	{
		return (2 * PI * radius);
	
	}//行为：获取圆的周长（通常用一个函数来代表）
};//一个完整的圆类就已经定义完毕，只有创建一个具体的圆之后，才能说生成了一个对象

//案例二：设计一个学生类，属性有姓名和学号，可以给姓名和学号赋值，可以显示姓名和学号
class Student
{
public://权限：公开
	//属性
	int Stu_ID;//学号
	string Stu_Name;//姓名
	//行为
	void ShowStu() 
	{
		cout << "该学生信息为：\n学号：" << Stu_ID << "\t姓名：" << Stu_Name << endl;
	}
	void SetName(string Name) { Stu_Name = Name; };
	void SetID(int ID) { Stu_ID = ID; };

};
//类中的属性的行为统一称为成员
//属性 也称为 成员属性和成员变量
//行为 也成为 成员函数或成员方法

//封装的意义二：将属性和行为加以权限控制。

	//Tips：雷灾设计时，可以将不同的属性和行为放在不同的权限下，加以控制
		//权限类型：公共权限：public；——类内和类外都可以访问
				  //保护权限：protected；——类内可以访问，类外不可以访问（儿子也可以访问父亲中的保护权限）
				  //私有权限：privated。——类内可以访问，类外不可以访问（儿子不能访问父亲中的私有权限）

//4.1.2 struct和class的区别：struct默认权限为公共；class默认权限为私有。其他无区别
class c1
{
	int m_A;//默认私有权限
};
struct c2 
{
	int m_A;//默认公共权限
};

//4.1.3  将成员属性设置为私有
		//优点一：成员属性设置为私有可以自己控制读和写的权限
		//优点二：对于写权限，可以检测数据的有效性
//设计人类
class hunman 
{
public://设置接口对属性进行读和写
	//姓名的写权限
	void set_Name(string Name) 
	{
		P_Name = Name;//函数是公共权限，所以可以进行赋值
	};
	//姓名的读权限
	string get_Name() 
	{
		return  P_Name;
	};
	//性别的读权限
	string get_Sex() 
	{
		return P_Sex;
	};
	//优点二：此时如果给年龄一个写的权限，那么可以通过该行为内部进行调整，验证写入数据的有效性
	void set_Age(int age)
	{
		if (age > 0 && age < 150)
		{
			P_Age = age;
		}
		else
		{
			cout << "年龄输入不合法" << endl;
			return;
		};
	}
	//年龄的读权限
	int get_Age() 
	{
		return P_Age;
	};
	//地址的读权限
	void set_Add(string Address) 
	{
		P_Address = Address;
	};
private:
	string P_Name;//姓名（可读可写）
	string P_Sex="男";//性别（只读）
	int    P_Age=21;//年龄（只读）
	string P_Address; // 只写
};





class person
{
	public://公共权限
		string P_Name;
		void funName() 
		{
			P_Name = "青木";
			P_car = "拖拉机";
			password = 11223344;
		};
	protected://保护权限
		string P_car;
	private://私有权限
		long password;//银行卡密码

};

int main() 
{
	//通过圆类来创建一个具体的对象
	//实例化（通过一个类来创建一个对象的过程）
	//Circle C1;
	//	//给该对象的属性进行赋值操作
	//C1.radius = 100;
	////也可以通过该类来获取圆的周长（圆的周长算是圆的属性吗？只是说的是行为）
	//cout << "半径为100的圆的周长为：" << C1.circle_C() << endl;//函数中的（）不能省略

	//Student Stu_1;//学生类的实例化
	//Stu_1.Stu_ID = 170902316;
	//Stu_1.Stu_Name = "青木与禾";//属性赋值操作——法一
	////属性赋值——法二：
	//Stu_1.SetID(1111);
	//Stu_1.SetName("青木");//仍可进行赋值，且因为顺序问题，覆盖了上面的赋值

	//Stu_1.ShowStu();//???

	//person p1;
	//p1.P_Name = "青";
	////p1.password = 112233;权限不允许
	//cout << p1.funName << endl;

	//c1 c1;//创建一个class对象
	//c2 c2;//创建一个struct对象
	////c1.m_A=10;//报错，权限不允许
	//c2.m_A = 20;//正确
	//cout << c2.m_A << endl;

	hunman pp1;
	pp1.set_Name("青木");
	cout << pp1.get_Name() << endl;
	cout << pp1.get_Sex() << endl;
	cout << pp1.get_Age() << endl;
	pp1.set_Add("青木村");
	//cout << pp1.P_Address << endl;
	pp1.set_Age(15);
	cout << pp1.get_Age() << endl;

	cout << endl;
	system("pause");
	return 0;
}