#include<iostream>
#include"spot.h"
#include"Circle.h"
using namespace std;


void Circle::set_center(spot point1) { center = point1; };//传入圆心坐标
void Circle::set_r(int a) { r = a; };//传入半径长度
int  Circle::get_center_x() { return center.get_spot_x(); };//x
int  Circle::get_center_y() { return center.get_spot_y(); };//y
int  Circle::get_r() { return r; };
