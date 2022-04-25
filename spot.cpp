#include<iostream>
#include"spot.h"
using namespace std;


void spot::set_spot(int x, int y) 
{//还需要再函数头部加上作用域声明，标明该函数是在该作用域下
	point[0] = x;
	point[1] = y;
};//写入圆的坐标
int  spot::get_spot_x() { return point[0]; };//x
int  spot::get_spot_y() { return point[1]; };//y
//仅保留成员函数的实现过程，不包括类中的属性
