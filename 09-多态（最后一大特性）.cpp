#include<iostream>
#include<string>
using namespace std;


// 9.0 多态
//多态分为两类
	//静态多态——函数重载、运算符重载

	//动态多态

	//二者的区别：静态多态函数地址是早绑定的（编译阶段确定函数地址），动态多态是地址晚绑定（函数地址在运行阶段确定）

//9.1 多态建立(是对函数地址的晚绑定)

//class Animal 
//{
//public:
//	 void speak() 
//	{
//		cout << "动物在说话呀！！！！" << endl;
//	};
//	string S;
//	
//};
//class Cat :public Animal //公共方式继承Animal类
//{
//public:
//	/*void speak()
//	{
//		cout << "小猫在说话呀！！！" << endl;
//	};*///与父类中函数同名
//};
//void dospeak(Animal &animal) 
//{
//	animal.speak();//调用Animal中的speak函数
//};
//void test90() 
//{
//	Cat cat;//Cat的实例化
//	dospeak(cat);//调用dospeak函数  Animal &animal=cat（合法语句，用父类引用去接受子类数据）
//					//此时之所能传入Cat类而不报错，是因为C++中允许父子之间的类型转换，不需要进行强化类型转换操作
//						//然而此时虽然传入的是cat，但是确指向的是animal中的speak函数，是因为在dospeak函数定义时就已经定义好了speak函数的地址
//			//而要想实现传入哪个类，就执行哪个类的speak函数，就需要将animal的speak函数设为虚函数（通过virtual关键字）
//};
//动态多态满足条件：有继承关系；子类重写父类中的虚函数（重写=完全一样（函数返回值类型、函数名、形参列表））
//动态多态使用条件：父类指针或引用指向子类对象；重写


//9.2 动态多态原理解析

//父类中仅有成员函数时，占用内存空间为1B，但是将成员函数转换为虚函数之后，占用内存空间就变为了4B
//从类内部结构分析：父类如果将内部成员函数转换为虚函数之后，其内部就会又一个vfptr（虚函数指针），指向一个cftable，这个虚函数表中存储的就是自己成员函数的地址
				//具体来说，就是指向Animal中的speak函数的地址
	//当子类未对父类中的虚函数发生重写时（单纯的继承了父类），此时子类中会有和父类中相同的内存结构，存储着相同的成员函数的地址
				//此时如果发生调用，因为vftable中指向的时父类中的成员函数的地址，所以就会执行父类中的成员函数
							//也就是输出“动物在说话呀！！！”
	//当子类对父类中的虚函数发生重写后，此时子类中的vftable中就会存储的时子类中的成员函数的地址
				//此时在发生调用（Animal &animal=cat），因为调用实际是用引用方式接受子类，所以也会随之执行子类中的成员函数
						//也就是输出“小猫在说话呀！！！”
//class Animal1 
//{
//public:
//	virtual void speak1() 
//	{
//		cout << "动物在说话呀！！！" << endl;
//	};
//};
//
//class Cat1 :public Animal1
//{
//public:
//	void speak1() 
//	{
//		cout << "小猫在说话呀！！！" << endl;
//	};
//};

// 多态案例1

//案例描述：分别使用普通写法和多态技术，设计实现两个操作数进行运算的计算器类
//普通写法
//class calculator1 
//{
//public:
//	void setnum1(int a) { M_a = a; };
//	void setnum2(int b) { M_b = b; };
//	int  getnum1() { return M_a; };
//	int  getnum2() { return M_b; };
//	int getresult(string operand) 
//	{
//		if (operand=="+")
//		{
//			return M_a + M_b;
//		}
//		else if (operand=="-")
//		{
//			return
//				M_a - M_b;
//		}
//		else if (operand == "*")
//		{
//			return M_a * M_b;
//		};
//		return 0;
//	};
//private:
//	int M_a;
//	int M_b;
//};
//void testopera01() 
//{
//	calculator1 cc1;
//	cc1.setnum1(5); cc1.setnum2(6);
//	cout<<cc1.getresult("+");
//};
////使用普通型写法，会发现扩展和修改并不方便，需要不停的回溯原函数进行修改，并且代码结构也不够清晰
////在实际开发中，提倡开闭原则（开放扩展，关闭修改），而多态技术可以很好的弥补上述缺点
//
////多态技术
////时刻牢记使用多态技术的条件：有继承关系；子类重写父类中的成员函数
//class AbstractCalculator 
//{
//public:
//	int num1;
//	int num2;//定义两个操作数
//	//十分关键——有一个虚函数（用于实现功能要求，但是要是空函数体，不同功能分设成不同的子类实现）
//	virtual int getresult() { return 0; };//虚函数提供外壳，具体功能由不同的子类提供（充当函数体）
//};
//
////加法计算器类
//class AddCalculator :public AbstractCalculator
//{
//	int getresult() 
//	{
//		return num1 + num2;
//	};
//};
////减法计算器类
//class SubCalculator :public AbstractCalculator
//{
//	int getresult()
//	{
//		return num1 - num2;
//	};
//};
////乘法计算器类
//class MulCalculator :public AbstractCalculator
//{
//	int getresult()
//	{
//		return num1 *num2;
//	};
//};
//void testcalcu() 
//{
//	int a; int b; string opera;//临时变量
//	cout << "请输入两个操作数的值：" << endl;
//	cin >> a >> b;
//	cout << "请输入它们要执行的操作：" << endl;
//	cin >> opera;
//	//加法运算
//	if (opera=="+")
//	{
//		//多态使用条件：父类指针或引用指向子类对象
//		AbstractCalculator *abc = new(AddCalculator);//函数传参时所使用引用类型
//		abc->num1 = a;
//		abc->num2 = b;
//		cout << a << opera << b << "=" << abc->getresult() << endl;
//		delete abc;
//		abc = NULL;
//	}
//	//减法运算
//	if (opera == "-")
//	{
//		AbstractCalculator *abc = new(SubCalculator);
//		abc->num1 = a;
//		abc->num2 = b;
//		cout << a << opera << b << "=" << abc->getresult() << endl;
//		delete abc;
//		abc = NULL;
//	}
//	//乘法运算
//	if (opera == "*")
//	{
//		AbstractCalculator *abc = new(MulCalculator);
//		abc->num1 = a;
//		abc->num2 = b;
//		cout << a << opera << b << "=" << abc->getresult() << endl;
//		delete abc;
//		abc = NULL;
//	}
//	
//};
//多态优点：
	//代码组织结构清晰；——不同功能定义出不同子类来实现
	//可读性强；——单独一个实现一个功能，避免复杂判断
	//利于前期和后期的扩展以及维护——功能独立化，彼此之间互不影响或一般不影响

//9.3 纯虚函数和抽象类

//多态技术中，父类中的虚函数毫无意义，不会被实现，基本是由子类中的函数实现所需功能
		//基于此，可以将父类中的函数改为纯虚函数
				//纯虚函数语法：virtual 返回值类型 函数名 （参数列表）=；
  //而当类中有了纯虚函数，这个类就成为了抽象类
				//抽象类特点：
//class Animal 
//{
//public:
// 	virtual void speak() 
//	{
//		cout << "动物在说话！！！" << endl;
//	};//加了virtual关键字之后，该函数就成为了虚函数
//			//而对于父类中的虚函数而言，并没有实际意义，所以可以直接将其转换为纯虚函数
//	//纯虚函数语法
//	virtual void speak() = 0;//此时父类中的speak函数就成为了纯虚函数
//			//对于纯虚函数而言：拥有纯虚函数的类称为抽象类，无法实例化对象，同时与该类有继承关系的子类若没有重写该纯虚函数，也无法实例化对象
//};
//class Cat :public Animal
//{
//	void speak() 
//	{
//		cout << "小猫在说话！！！" << endl;
//	};//有了继承关系之后，这个函数就可以看成是对于父类中虚函数的重写
//};
//
//void dospaeak(Animal &animal)//使用引用方式传参，就可以实现多态的使用
//{
//	animal.speak();
//};
//void test93() 
//{
//	//多态使用条件：父类以指针或引用方式调用子类
//	Cat cat;
//	dospaeak(cat);//此时就实现了父类以引用方式调用子类
//					//重写之后，子类vftable中的函数地址就变为了自己的成员函数的地址
//};


//多态案例2 

//案例描述：利用多态技术实现饮品制作（流程为：煮水、冲泡、倒入杯中、加入辅料）
			//提供抽象制作饮品基类、提供子类制作咖啡和茶
//分析：使用多态技术的本质是不同子类实现不同功能，而本案例的重难点在于，如何理解那个是功能，哪一个是流程
		//得出：制作不同的饮品（咖啡、茶）属于功能，有不同的子类实现
			//一杯饮品的制作过程属于流程，分别定义不同的函数实现
	//基于上述分析得出：四个流程有四个函数实现，不论是什么饮品都会有这四个函数，只是函数体不同，最终决定类实现的功能不同
//父类
//class AbstractDrink 
//{
//public:
//	virtual  void Boil() = 0;//定义一个煮水纯虚函数
//	virtual  void Brew() = 0;//定义一个冲泡纯虚函数
//	virtual  void Pour() = 0;//定义一个倒入杯中纯虚函数
//	virtual  void Add() = 0; //定义一个加入辅料纯虚函数
//};
////咖啡子类
//class Coffee:public AbstractDrink
//{
//public:
//	//需要重写父类中的纯虚函数
//	virtual  void Boil() 
//	{
//		cout << "开始准备煮咖啡用的水" << endl;
//		cout << "水已经煮开" << endl;
//	};
//	virtual  void Brew() 
//	{
//		cout << "研磨咖啡豆..." << endl;
//		cout << "煮咖啡粉" << endl;
//	};
//	virtual  void Pour() 
//	{
//		cout << "将煮好的咖啡倒入壶中进行过滤..." << endl;
//	};
//	virtual  void Add() 
//	{
//		cout << "开始拉花" << endl;
//		cout << "咖啡制作完成！" << endl;
//	};
//};
//class Tea:public AbstractDrink
//{
//public:
//	//需要重写父类中的纯虚函数
//	virtual  void Boil()
//	{
//		cout << "开始准备煮茶叶用的水" << endl;
//		cout << "水已经煮开" << endl;
//	};
//	virtual  void Brew()
//	{
//		cout << "挑选茶叶..." << endl;
//		cout << "煮茶" << endl;
//	};
//	virtual  void Pour()
//	{
//		cout << "将煮好的茶倒入茶壶中..." << endl;
//	};
//	virtual  void Add()
//	{
//		cout << "茶饮制作完成！" << endl;
//	};
//};
////多态条件：继承关系已满足
//
//void dodrink(AbstractDrink &drink) //多态条件：父类以引用或指针方式调用子类已满足
//{
//	drink.Boil();
//	drink.Brew();
//	drink.Pour();
//	drink.Add();
//};
//void testdrink() 
//{
//	Tea tea;
//	dodrink(tea);
//};

//9.4 虚析构和纯虚析构（解决子类中有成员在堆区开辟空间无法释放的问题）

//class Animal 
//{
//public:
//	Animal() 
//	{
//		cout << "父类中默认构造函数的调用！！！" << endl;
//	};
//	virtual void speak()=0;//父类中的纯虚函数——条件1
//	//virtual ~Animal()
//	//{
//	//	cout << "父类中析构函数的调用！！！" << endl;
//	//}//将主类中的析构函数转换为虚析构函数之后，子类中的析构函数就能正常执行了
//	virtual ~Animal() = 0;//主类中的纯虚析构函数
//	//同样，将主类中的析构函数变为纯虚析构函数，也可以使子类中的析构函数正常执行，但是需要对主类中的析构函数在类外进行定义
//};
//Animal::~Animal() { cout << "1" << endl; };//完成了对于主类中纯虚析构函数的定义之后，也可以解决子类中虚构函数没有执行的问题
//class Cat :public Animal//继承关系——条件2
//{
//public:
//	Cat(int a)
//	{
//		M_Age = new int(a);
//		cout << "子类中默认构造函数的调用" << endl;
//	};
//	virtual void speak() 
//	{
//		cout << "" << endl;
//	};//父类中纯虚函数的重写——条件3
//	~Cat()
//	{
//		cout << "子类中析构函数的调用！！！" << endl;
//		if (M_Age!=NULL)
//		{
//			delete M_Age;
//			M_Age = NULL;
//		}
//	}
//	int *M_Age;
//};
////void dospeak(Animal &animal) //以引用方式调用子类——条件4
////{
////	animal.speak();
////};
////在未对父类中的
//void test94() 
//{
//	Animal *animal = new Cat(5);
//	animal->speak();
//	delete animal;
//	/*Cat cat(5);
//	dospeak(cat);*/
//	//下面的方式并未将子类生成在堆区，test94执行完毕之后，cat对象就会被释放，按照先子类后父类的顺序正常释放，此时并不会出现问题
//	//但是如果按照上面的方式在堆区生成一个子类，在test94执行完毕之后，并不会执行子类的析构函数而是直接去执行父类中的析构函数
//						//此时子类中开辟在堆区中的内存就没有得到释放，造成了内存释放不干净的问题
//	//要解决上述问题就要使用虚析构或者纯虚析构的方式对主类中的析构函数进行处理
//};

//多态案例3

//案例描述：电脑组装：主要组成部分为：CPU（用于计算）、显卡（用于显示）、内存条（用于存储）
		//将每个零件封装出抽象基类，并且提供不同的厂商生产不同的零件
	//创建电脑类提供让电脑工作的函数，并且调用每个零件工作的接口
		//测试时，组装三台电脑进行工作
//分析：区分什么时候使用多态，什么情况下使用多态（或者说，什么是多态）
		//多态可以理解为是解决不同父类下的子类差异性而出现的技术
			//计算器：都是执行两个数的运算——因此可以抽象出不同计算之间的共性，构成父类——计算
				//而具体到每一个子类身上，就是具体的计算功能不同（加减乘除）
		//同时要注意识别多态应该使用在什么地方
				//电脑本身是一个复杂类，其中又有零件成员类，而零件成员类本身又有两个不同的属性——生产厂家、功能
							//如果将这两个属性都作为区分子类的标准，目前还难以做到（一个零件基类，再分出三个子类，三个子类中又有两个不同属性（即子类又产生子类））
									//一般选择基类时，不会要求有大的概括性，相反，要求有小的概括性
												//即，不抽象零件基类，转而抽象出单纯的CPU、GPU、RAM基类
														//此时，在三个基类中产生的子类只有一个差异——生产厂家
//综上，基类就抽象为不同的零件，子类中的差异就是不同的生产厂家
//而多态产生，除了继承关系、重写父类函数，还需要父类以指针或引用方式调用子类
	//要满足这个要求，就需要电脑类了，一台电脑固定会有这三个零件，而要完成电脑组装就需要在电脑类中添加默认构造函数，此时就可以实现父类以指针或引用方式调用子类
//流程：生成零件基类——生成零件子类——生成电脑类——测试电脑工作、
//CPU基类
class CPU 
{
public:
	virtual void Calculate() = 0;//父类中的纯虚函数
};
//GPU基类
class GPU
{
public:
	virtual void Display() = 0;
};
//RAM基类
class RAM
{
public:
	virtual void Storage() = 0;
};
//CPU子类
//子类中的不同此时只有生产厂商，所以将差异具体化
//IntelCPU子类
class IntelCPU :public CPU
{
public:
	//重写父类中纯虚函数
	void Calculate() 
	{
		cout << "Interl的CPU正在进行计算！！！！" << endl;
	};
};//CPU子类定义完成
//IntelGPU子类
class IntelGPU :public GPU
{
public:
	//重写父类中纯虚函数
	void Display()
	{
		cout << "Interl的GPU正在进行显示！！！！" << endl;
	};
};//GPU子类定义完成
//IntelRAM子类
class IntelRAM :public RAM
{
public:
	//重写父类中纯虚函数
	void Storage()
	{
		cout << "Interl的RAM正在进行存储！！！！" << endl;
	};
};//CPU子类定义完成
//HuaweiCPU子类
class HuaweiCPU :public CPU
{
public:
	void Calculate()
	{
		cout << "Huawei的CPU正在进行计算！！！！" << endl;
	};
};
//HuaweiGPU子类
class HuaweiGPU :public GPU
{
public:
	void Display()
	{
		cout << "Huawei的GPU正在进行显示！！！！" << endl;
	};
};
//HuaweiRAM子类
class HuaweiRAM :public RAM
{
public:
	void Storage()
	{
		cout << "Huawei的RAM正在进行存储！！！！" << endl;
	};
};
//至此，所有的零件类已经定义完成，需要电脑类进行组装
//电脑类
	//使用有参构造函数实现组装功能，定义一个工作函数，使用析构函数释放堆区内存
class Computer 
{
public:
	Computer(CPU *cpu,GPU* gpu,RAM *ram)
	{
		M_cpu = cpu;
		M_gpu = gpu;
		M_ram = ram;
	};//对于组装的定义(使用构造函数生成对象实质是一个赋值过程)
	void work() //还需要一个工作函数，进行各配件的工作
	{
		M_cpu->Calculate();
		M_gpu->Display();
		M_ram->Storage();
	};

	//需要析构函数来对变量的内存进行手动释放
			//堆区内存释放关键字：delete
~Computer()
{
	if (M_cpu!=NULL)
	{
		delete M_cpu;
		M_cpu = NULL;
	}
	if (M_gpu!=NULL)
	{
		delete M_gpu;
		M_gpu = NULL;
	}
	if (M_ram!=NULL)
	{
		delete M_ram;
		M_ram = NULL;
	}
}
private:
	CPU * M_cpu;
	GPU * M_gpu;
	RAM * M_ram;//定义三个成员变量由于构造函数
    //由于电脑中的零件是在堆区开辟的空间，因此需要手动释放
};
void testCom() 
{
	cout<<"第一台电脑："<<endl;
	CPU *cpu01 = new IntelCPU;//父类以指针方式调用子类
	GPU *gpu01 = new IntelGPU;
	RAM *ram01 = new IntelRAM;
	Computer Computer01(cpu01, gpu01, ram01);//此时一台电脑已经产生
	//需要调用电脑的工作函数使电脑进行正常工作
	Computer01.work();
					//此时computer变量是创建在栈区的，若想要后续继续使用，则需要使用new关键字将其创建在堆区（要注意最后的释放堆区内存）
					//Computer *computer01=new Computer(cpu01,gpu01,ram01);//使用有参构造函数创建变量
	cout << "————————————————" << endl;
	cout << "第二台电脑：" << endl;
	Computer *computer02=new Computer(new HuaweiCPU, new HuaweiGPU, new HuaweiRAM);
	computer02->work();
	delete computer02;
	computer02 = NULL;
	cout << "————————————————" << endl;
	cout << "第三台电脑：" << endl;
	Computer computer03(new IntelCPU,new HuaweiGPU,new HuaweiRAM);
	computer03.work();
};
//上述案例中，通过多态是实现了使用不同厂商不同零件的需求
			//零件是基类，厂商决定子类，最后使用电脑实现父类以指针方式对子类的调用
//明确在何处使用多态，以何种方式满足父类以指针方式调用子类是两个比较难的地方
		//个人总结：多态中基类概括性弱，一般包含一个差异性属性
				//父类以指针和引用方式调用子类，可以通过默认构造函数实现，或者单独定义一个全局函数，以父类的引用或者指针作为形参，传入子类实现要求



int main() 
{
	//testCom();
	//test90();
	//testopera01();
	//testcalcu();
	//test93();
	//testdrink();
	//test94();
	testCom();





	cout << endl;
	system("pause");
	return 0;
}