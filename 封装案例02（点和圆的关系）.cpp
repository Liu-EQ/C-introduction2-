#include<iostream>
#include<string>
#include"Circle.h"
#include"spot.h"//分文件编写后，需要在主函数中加入这些头文件
using namespace std;

//案例描述：对点和圆的关系进行判断（点在圆外、点在圆上、点在圆中）
				//分析：分析思路：本质是求点到圆心的距离与半径的大小关系
						//Tips：点到圆心的距离：两点之间的距离公式：x~2+y~2开根号（问题在于如何对这个值进行开根号操作）
						//因此就需要考虑其他做法：两边都平方之后，就可以省略开根号操作了
				//因此：就应该有两个类：圆类和点类
						//圆类属性：圆心坐标，半径长度
						//点类属性：坐标

						
//class spot
//{
//public:
//	//公共接口，用于读写点的坐标
//	void set_spot(int x, int y) {
//		spot[0] = x;
//		spot[1] = y;
//	};//写入圆的坐标
//	int  get_spot_x() { return spot[0]; };//x
//	int  get_spot_y() { return spot[1]; };//y
//private:
//	int spot[1];//点的坐标
//};//点类
//class Circle 
//{
//public:
//	//行为：接口（用于读取和写入圆心坐标和半径长度）
//	void set_center(spot point1) { center = point1; };//传入圆心坐标
//	void set_r(int a) { r = a; };//传入半径长度
//	int  get_center_x() { return center.get_spot_x(); };//x
//	int  get_center_y() { return center.get_spot_y(); };//y
//	int  get_r() { return r; };
//private:
//	spot center;//定义一个整型数组用于存放该圆的坐标
//				//用一个类作为另一个类的成员
//	int r;//半径
//
//
//};//圆类


void Judge(Circle &CC1,spot &PP1);//判断函数声明
									//传入参数为一个圆的对象，一个点的对象，采用引用的方式传入


int main()
{
	//声明了两个类之后，需要通过类创建对象
	Circle CC1;//圆类的实例化
	spot C_P;//创建圆心对象
	C_P.set_spot(10,10);
	spot   PP1;//点类的实例化
	CC1.set_center(C_P);//传入圆心坐标（10,10）
	CC1.set_r(10);//传入圆的半径长度10
	PP1.set_spot(10,5);//传入点的坐标（10,11）
	//下一步需要设置一个函数用于对比两者的距离关系
	Judge(CC1,PP1);//调用比较函数


	cout << endl;
	system("pause");
	return 0;
}

void Judge(Circle & CC1, spot & PP1)
{
	int x1 = CC1.get_center_x(); int x2 = PP1.get_spot_x();//获取两个x坐标
	int y1 = CC1.get_center_y(); int y2 = PP1.get_spot_y();//获取两个y坐标
	int temp = CC1.get_r();//获取圆的半径长度
	if ((x1-x2)*(x1 - x2) +(y1-y2)*(y1 - y2)<temp*temp)
	{
		cout<< "该点在圆内！！！！\n" ;
	}
	else if ((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2) == temp*temp)
	{
		cout<< "该点在圆上！！！\n";
	}
	else 
	{
		cout<< "该点在园外！！！\n" ;
	}

}


//总结：
	//可以在一个类中让另一个类作为他的成员
	//类的份文件编写（Tips：在头文件中只包含声明，没有函数实现过程；在源文件中需要添加相应的头文件，尤其是用到了其它类作为成员时；
								//需要添加作用域声明；主函数中需要加入相应的头文件）