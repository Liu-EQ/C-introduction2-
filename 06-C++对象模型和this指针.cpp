#include<iostream>
#include<string>
using namespace  std;

//6.0 C++对象模型和this指针

//6.1 对象模型-成员变量和成员函数分开存储（只有非静态的成员变量才属于类的对象上）
									//即静态成员、非静态成员函数都不属于某一个对象

//class person 
//{
//public:
//	//若一开始并未在对象中声明任何成员，则对象占用大小为1，
//				//因为C++编译器也会给每一个空对象分配一个字节空间，是为了区分控股对象占内存的位置
//	int a;//内部定义了一个非静态成员变量之后，大小变为该成员的类型大小，
//							//因此也就得出了该非静态成员变量属于该对象
//	static int b;//内部声明了一个静态成员变量之后，对象所占内存大小并不会发生改变，因此也就证明了静态成员变量并不属于该对象
//
//	void func()
//	{
//		cout << "" << endl;
//	};//内部添加了非静态成员函数之后，对象所占内存大小并不会发生改变，因此也就证明了非静态成员函数并不属于该对象
//
//	static void func2() {};
//
//};
//
//void test01()
//{
//	person P;
//	cout << "sizeof P=" << sizeof(P) << endl;
//};
//结论：只有非静态成员变量才属于对象，其余的都不属于该对象

//6.2 this指针（非静态成员函数如何区分不同的对象）

////this指针指向被调用的成员函数所属的对象（谁调用成员函数，this就指向谁）
////this指针隐函在每一个非静态成员函数内，不需要定义，直接使用即可
////this用途：
//	//形参和成员变量同名时，可以使用this来区分（解决名称冲突）；
//class person1 
//{
//public:
//	int Age;//定义成员变量时，为防止后期命名冲突，可以加m_(m是member)
//	person1(int Age) 
//	{
//		this->Age = Age;//重名了
//					//此时若加了this->，就会区分开形参与成员变量，避免了重名问题
//						//此时this指针就指向调用该成员函数所属的对象（P1），通过箭头来访问其成员变量
//	};
//	person1& personAgeAdd(person1 &p) //一定要以引用方式返回，否则不i会对本体做更改
//	{
//		this->Age += p.Age;//将传入的这个人的年龄加到调用该函数的人身上
//							//例如：P2.personAgeAdd（P1）就相当于将P1的年龄加到了P2身上
//		return *this;
//	};
//};
//
//void test11() 
//{
//	person1 P1(18);//定义了有参构造函数之后，就没有默认构造函数了，因此只能有用参构造函数的方法生成对象
//	person1 P2(20);
//	cout << "P1.Age=" << P1.Age << endl;
//	P2.personAgeAdd(P1);//此时函数返回值是void，如果还想再继续调用该函数就会出错（即P2.personAgeAdd(P1).personAgeAdd(P1)就会报错）
//							//而要解决该问题就要更改函数返回值，如果返回值是P2，那么就可以继续调用了
//								//此时就可以使用return *this来返回P2本身（注意更改函数返回值类型）（且如果要返回本体，要以引用方式返回）
//	cout << "P2.Age=" << P2.Age << endl;//此时P2.Age=38
//	P2.personAgeAdd(P1).personAgeAdd(P1);//链式编程思想，可以无限调用
//	cout << "P2.Age=" << P2.Age << endl;//过程是：P2.Age（38）+P1.Age（18）+P1.Age（18）=74
//};
//	//类的非静态成员函数中返回对象本身，可以使用 return *this。（因为在调用成员函数时，this指向对象，所以可以通过解引用的操作来返回对象）
// 

//6.3 空指针访问成员函数

//C++中空指针也是可以放访问成员函数的，凡是也要注意有没有用到this指针（如果用到this指针，需要加以判断保证代码的健壮性）
//class person3
//{
//public:
//	void showClassName()
//	{
//		cout << "This is a person3 class!" << endl;
//	};
//	void showPersonAge() 
//	{
//		//对于this为空的预防：
//		if (this==NULL)
//		{
//			return;
//		}//提高代码健壮性
//		cout << "person.Age=" <<M_Age<< endl;//调用属性时，编译器默认在属性前加this->(表明这是该对象的属性)
//	};
//
//	int M_Age;
//};
//
//void test01() 
//{
//	person3 * P3 = NULL;
//	P3->showClassName();
//	P3->showPersonAge();//调用成员函数
//						//而此时的P3是一个空指针（即为指向任何实体对象），因此this—>就是没有办法指明是哪个对象，
//								//此时如果在访问this所指对象的一个成员属性就会出错（因为this并没有一个确切的值）
//
//};
////结论：空指针是可以访问成员函数的，如果加了this，需要考虑this为空的情况，需要添加判断语句，防止程序出错，提高程序健壮性


//6.4 const修饰成员函数

//常函数（const 成员函数）
	//内部不能修改成员属性；
	//若有某些属性需要修改，可以在属性声明时加关键字 mutable
class  person4
{
public:

	//this指针的本质是一个指针常量，默认指向调用该函数的对象（相当于person * const this）
		//而如果对于this指针再加限制，使它不仅不能修改指向，而且连值都不能修改，则需要再加一个const（const person * const this）
				//而这个const体现出来就是加在函数声明后
	void showperson() const//此时对于M_Age的修改就会出错
	{
		//M_Age = 20;//此时是正确的，而如果不想让函数修改该属性的值，则需要在函数声明后加const
		M_c = 30;//此时就不会出错
		cout << "" << endl;
	};//在成员函数之后加const，修饰的时this指针，使其变为了一个既不能修改指向也不能修改值的指针
	void show2() {};//并非常函数
	int M_Age;
	int M_b;//此时M_b的值也是不可修改的
			//而如果想要修改M_b的值，就需要加关键字mutable
	mutable int M_c;
};
void testP41() 
{
	person4 P1;
	P1.M_c = 30;
	P1.M_b = 20;//并未对属性进行限制，因此可以正常赋值
	P1.showperson();
};
//常对象（const 对象）
	//常对象只能调用常函数
void testP42()
{
	const person4 P2;//此时创建了一个常对象
					//常对象也不允许修改指针指向的值
	//P2.M_b = 20;//常对象不允许修改普通的成员变量
	P2.M_c = 30;
	P2.showperson();
	//P2.show2();//常对象只能调用常函数，而show2（）并非常函数，报错
};

int main() 
{
	//test01();
	//test11();
	//test01();









	system("pause");
	return 0;
}
