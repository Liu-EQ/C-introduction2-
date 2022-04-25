#include<iostream>
#include<string>
using namespace std;

void swap1(int a, int b);//值传递，形参并不会修饰实参
void swap2(int * a, int * b);//地址传递，形参会修饰实参的值
void swap3(int &a, int &b);//引用传递，形参会修饰实参

int& test001();//此间a的值放在栈区，函数执行完毕，该内存就会被释放

int& test002();//在局部变量a之前添加static关键字，就将a变成了一个静态变量，放在全局区

void showvalue(const int &a);


int main() 
{
	//2.0 关于引用
	////2.1引用的语法
	//int a = 10;//内存中临时分配一个内存空间（4B），存储数字10（放在代码区中）
	//cout << "a的初始值为：" << a << endl;
	//int & a1= a;
	//cout << "对a进行引用之后的a1值为：" << a1 << endl; 
	////引用的写法：数据类型(与被引用的变量的数据类型保持相同)  &（引用符号，关键） 别名=被引用的变量；（（相当于给变量起别名）
	//			//此时a和a1指向的是同一块内存，都可以对这块内存进行操作
	//a1 = 20;
	//cout << "利用a1操纵a之后的新值为：" << a << endl;


	//2.2引用的注意事项
	//引用必须初始化；（即必须赋初值）（int & a-这是不合法的语句）

	//引用一旦初始化之后，就不能再更改（即引用是谁的别名就必须一直是谁的别名）
					//注意赋值操作与引用操作的区别
	//int num1 = 10;
	//int & Y= num1;
	//int c2 = 30;
	// Y = c2;
	//cout << "c="<<num1<<endl;
	//cout << "Y=" << Y << endl;
	//cout << "c2=" << c2 << endl;


	//2.3 引用做函数参数
	//函数传参时，可以利用引用让函数形参修饰实参（因为引用本身和实参本事指向的是同一个变量，但是函数传参是形参对其进行复制）
	//int a1 = 10, b1 = 20;
	//swap1(a1, b1);
	//cout << "值传递：\t";
	//cout << "a1=" << a1 
	//	<< "b1=" << b1 << endl;//值传递对实参的影响
	//a1 = 10, b1 = 20;//保持初始值不变
	//swap2(&a1,&b1);
	//cout << "地址传递：\t";
	//cout << "a1=" << a1 
	//	 << "b1=" << b1 << endl;//地址传递对实参的影响
	//a1 = 10, b1 = 20;//保持初始值不变
	//swap3(a1, b1);
	//cout << "引用传递：\t";
	//cout << "a1=" << a1 
	//	 << "b1=" << b1 << endl;//引用传递对实参的影响

	////可以简化指针修改参数


	//2.4 引用做函数1返回值
	//不要返回局部变量的引用
	//int & a1 = test001();
	//cout << "a1=" << a1<<endl;
	//cout << "a1=" << a1<<endl;
	////如果函数返回值是一个引用，那函数的调用可以作为左值
	//int &a2 = test002();//可以视为函数返回的是一个别名，要求用一个别名来接收
	//cout << "a2=" << a2 << endl;
	//cout << "a2=" << a2 << endl;
	//test002() = 1000;//给原名赋值，用别名调用
	//cout << "a2=" << a2 << endl;
	//cout << "a2=" << a2 << endl;

	//2.5 引用的本质
	//引用的本质在C++内部就是一个指针常量（不能修改指向，可以修改赋值）

	//int aa = 10;
	//int& aa001 = aa;//此时相当于：int * const aa001=&aa;对于该指针常量而言，固定指向aa变量，不能在指向其他变量，但是可以更改赋值
	//aa001 = 30;//此时相当于：*aa001=30，是一个对指针解引用的过程


	//2.6 常量引用
	//常量引用主要用来修饰形参，防止误操作
	int   a002 = 20;
	int & aa003 = a002;//不能写为：int & aa003 = 20（20是一个常量），而引用必须引用一块合法的内存空间（栈或者堆区的数据）
	const int &aa004 = 10;//正确，编译器修改代码为：int temp=10；int &aa004 = temp；
						  //加入const之后，就变为一个只读常量，不能修改
	showvalue(a002);
	cout << "a002=" << a002 << endl;//此时就通过函数内部对实参做了更改
	//函数形参列表中，可以添加关键字const来修饰形参，防止对实参产生更改
					//因此可以通过const来修饰形参，防止更改实参

	cout << endl;
	system("pause");
	return 0;
}

//void swap1(int a,int b)
//{
//	int temp = a;
//	a = b;
//	b = temp;
//}


void swap2(int * a, int * b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void swap3(int &a, int &b)//以引用方式接收实参的值，就相当于形参成为了实参的别名
{
	int temp = a;
	a = b;
	b = temp;
}

//int & test001()
//{
//	int a = 20;
//	return a;
//	// TODO: 在此处插入 return 语句
//}

int & test002()
{
	static int a = 30;
	return a;
	// TODO: 在此处插入 return 语句
}

void showvalue(const int  &aaa2)
{
	//a = 2000;
	cout << aaa2 << endl;
}
