#include<iostream>
#include<string>
using namespace std;


//3.0 函数提高
//3.1函数默认参数（函数列表中，形参是可以有默认值的）
//示例：
int func1(int a,int b=20,int c=30);
//函数默认值注意事项：
		//如果函数形参某个位置有了默认值，那么从这个位置往后都必须有默认值
		//如果函数声明已经有了默认值，那么函数定义（实现）时就不能在给形参传入默认值（反之，若函数实现有默认值，那么声明就不能有）

//3.2 函数占位参数（形参列表可以有展位参数，用于占位，调用函数时必须填补该位置）
void func2(int a,int);//第二个int就是占位参数，调用时必须要传入该类型的参数(函数声明和定义都需要同步更改)
						//返回值类型 函数名（数据类型）{}
						//占位参数可以有默认参数


//3.3 函数重载（函数名可以相同，提高复用率）
			//函数重载条件：
					//同一个作用域下；函数名相同；函数参数类型不同或者顺序不同或者个数不同
					//Tips：函数返回值不能作为函数重载的条件
//示例：
void func3(int a) 
{
	cout << "函数重载" << endl;
}

void func3()
{
	cout << "函数重载！" << endl;
}
//函数重载注意事项：
		//引用作为函数重载条件
void func4(int & a) 
{
	cout << "This is a function too!!!!" << endl;
}
void func4(const int & a)//形参不同，允许重载
{
	cout << "This is a function again !!!!" << endl;
}
		//函数重载出现默认参数
void func5(int a) 
{
	cout << "This is still a function !!!!" << endl;
}
void func5(int a,int b)//此时如果给b一个默认值，那么这两个函数重载救护一样了
{
	cout << "This is still a function again !!!!" << endl;
}
int main()
{
	//函数调用
	//cout<<"函数调用的结果为："<<func1(10,30)<<endl;//函数声明是可以给形参进行默认赋值
													//之后调用过程中，如果没有再给形参赋值，就是使用默认赋值；
													//如果调用时又传入了参数，那么就以调用时传入参数为准
	//func2(10,20);

	//func3(10);//形参是分别函数重载的关键
	//func3();
	//int a = 20;
	//func4(a);
	//func4(a);//a为变量，因此不会调用const版本（int & a=a(合法)）
	//func4(10);//10为常量，因此会调用const版本（const int & a=10(合法)），而对于int &a=10；这是一个不合法的语法


	func5(20);
	func5(1,2);




	cout << endl;
	system("pause");
	return 0;

}

int func1(int a,int b,int c)
{
	return a + b + c ;
}

void func2(int a,int)
{
	cout << "This is a function!" << endl;
}
