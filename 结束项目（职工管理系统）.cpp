#include<iostream>
#include<string>
#include<fstream>
using namespace std;


//职工管理系统
//需求分析：管理公司内部员工信息
		/*员工分类：普通员工：完成经理交给的任务
					经理：完成老板交给的任务，并下发任务给员工
					老板：管理公司的事务
						职工工作职责差异可以使用不同的子类来实现，定义一个员工基类，由此派生出不同的员工子类对应不同的员工*/
/*模块管理：
	模块一：退出模块——同理可以制作一个员工数组，用于整体管理的企业内部员工，退出模块需要终止循环并且执行清屏操作
	模块二：增加职工信息——让用户选择增加职工的类型，来选择不同的子类进行添加，构造函数保持一致，都使用有参构造函数
			同时，添加完毕后，数组长度加一，实现用户新增，新增用户需要用文本文件（或二进制文件）进行存储，此处也可封装一个函数进行写入操作
	模块三：显示职工信息——对应文件输出函数
	模块三：查找模块——采用for循环进行查找
	模块四：删除职工信息——数组长度减一，并且删除文件以空记录覆盖原有记录达到删除目的
	模块五：修改模块——使用单个属性修改的方式，生成临时变量进行值的替换，可以有一个交换函数，用于删除、修改、排序
	模块六：排序模块——升序降序序列——使用冒泡排序（比较基准尾员工编号）
	模块七：清空模块——数组长度置为0*/

//职工基类
class staff
{
public:
	//定义公共接口用于属性赋值
	int getnum() { return M_num; };
	string getname() { return M_name; };
	int getsex() { return M_sex; };
	int getage() { return M_age; };
	//职位
	virtual void positiion() = 0;//定一个纯虚函数，使得积累成为纯虚类，无法实例化对象
	//默认构造函数
	staff (int num, string name, int sex, int age, int posi)
	{
		M_num = num;
		M_name = name;
		M_sex = sex;
		M_age = age;
		M_posi = posi;
	};
protected:
	int M_num;//员工编号
	string M_name;//姓名
	int M_sex;//性别（1/2区分，检验输入有效性）
	int M_age;//年龄
	int M_posi;//职位
};
//普通员工子类
class worker :public staff
{
public:
	virtual void positiion() 
	{
		if ( M_posi==1)
		{
			cout << "该员工为普通员工，职责：完成经理交代的任务！！！" << endl;
		}

	};
};
//经理子类
class manager :public staff
{
public:
	virtual void positiion()
	{
		if (M_posi == 2)
		{
			cout << "该员工为经理,职责：完成老板交代的任务，并且给员工安排任务！！！" << endl;
		}

	};
};
//老板子类
class boss :public staff
{
public:
	virtual void positiion()
	{
		if (M_posi == 3)
		{
			cout << "该员工为老板，职责：统筹安排公司的各项事务！！！" << endl;
		}

	};
};
//功能菜单展示
void Display() 
{
	//界面模块——封装成函数
	cout << "————欢迎使用青木职工信息管理系统—————" << endl;
	cout << "——————0-退出职工信息管理系统——————" << endl;
	cout << "——————1-显示企业当前员工信息——————" << endl;
	cout << "——————2-添加企业新增员工信息——————" << endl;
	cout << "——————3-查找企业内部员工信息——————" << endl;
	cout << "——————4-修改企业内部员工信息——————" << endl;
	cout << "——————5-删除企业内部员工信息——————" << endl;
	cout << "——————6-排序企业内部员工信息——————" << endl;
	cout << "——————9-清空企业内部员工信息——————" << endl;
};
//信息展示函数——使用二进制文件读取操作
//信息添加函数——使用二进制文件写入操作
void InforBinaryInput(staff *work);
staff* InformationInput();
//信息展示
void  BianryIn(staff *p2)
{
	//1、包含头文件
	//2、创建流对象： ifstream ifs;
	ifstream ifs;
	//3、打开文件并判断是否打开成功：ifs.open("文件位置",打开方式);
			//使用ifs.is_open判断是否成功打开
	ifs.open("StaffInformation.txt", ios::in | ios::binary);
	if (!ifs.is_open())
	{
		cout << "文件未成功打开" << endl;
	}
	//4、读文件：ifs.read(char *,int length)
	ifs.read((char *)&p2, sizeof(p2));
	cout << p2->getnum() << " " << p2->getname() << " " 
		<<p2->getsex() << " " <<p2->getage() << " ";
	p2->positiion();
	//输出格式仍然受输出语句影响
//5、关闭文件：ifs.close();
	ifs.close();
};


int main() 
{
	staff * employee[1000];
	int* length = new (int);
	Display();
	cout << "请选择您要使用的功能：" << endl;
	int select;
	cin >> select;
	while (true)
	{
		switch (select)
		{
		case 0://退出模块
		{
			cout << "欢迎下次使用！！！" << endl;
			system("pause");
			return 0;
			break;
		}//退出模块——over
		case 1://显示模块
		{
			//信息输出函数
			for (int i = 0; i < length; i++)
			{
				BianryIn(employee[i]);
			}


			system("pause");
			system("cls");
			break;
		}
		case 2://添加模块
		{
			employee[length]=InformationInput();//调用信息输入函数
			InforBinaryInput(employee[length]);
			cout << "员工信息添加成功！" << endl;
			length++;
			system("pause");
			system("cls");
			break;
		}
		case 3://查找模块
		{
			system("pause");
			system("cls");
			break;
		}
		case 4://修改模块
		{
			system("pause");
			system("cls");
			break;
		}
		case 5://删除模块
		{
			system("pause");
			system("cls");
			break;
		}
		case 6://排序模块
		{
			system("pause");
			system("cls");
			break;
		}
		case 9://清空模块
		{
			system("pause");
			system("cls");
			break;
		}
		default:
			break;
		}
		system("cls");
		Display();
		cout << "请选择您要继续使用的功能：" << endl;//退出模块是唯一的退出方法
		cin >> select;
	}
	
}


//添加模块函数定义
staff* InformationInput()
{
	cout << "请输入你要添加的新员工的员工编号：" << endl;
	int num1;
	cin >> num1;
	cout << "请输入你要添加的新员工的姓名：" << endl;
	string name1;
	cin >> name1;
	cout << "请输入你要添加的新员工的性别：" << endl;
	cout << "0——女；1——男" << endl;
	int sex1;
	cin >> sex1;
	if (sex1!=1&&sex1!=0)
	{
		cout << "输入的性别编号不合法！！！" << endl;
	}
	cout << "请输入你要添加的新员工的年龄：" << endl;
	int age1;
	cin >> age1;
	cout << "请输入你要添加的新员工的职位编号：" << endl;
	cout << "1——普通职工；\n"
		 << "2——经 理；\n"
		 << "3——老 板\n"<< endl;
	int posi1;
	cin >> posi1;
	
	switch (posi1)
	{
	case 1:
	{
		
		staff * worker01=new worker(num1, name1, sex1, age1, posi1);
		return worker01;
		break;
	}
	case 2:
	{
		staff * worker01=new manager(num1, name1, sex1, age1, posi1);
		return worker01;
		break;
	}
	case 3:
	{
		staff * worker01= new boss(num1, name1, sex1, age1, posi1);
		return worker01;
		break;
	}
	default:
		break;

	}
}
//信息写入函数定义
void InforBinaryInput(staff *work)
{
	//使用文件写入函数进行存储
	ofstream ofs;
	ofs.open("StaffInformation.txt", ios::out | ios::binary);
	ofs.write((char *)work, sizeof(work));
}
