#include<iostream>
#include"spot.h"
using namespace std;


void spot::set_spot(int x, int y) 
{//����Ҫ�ٺ���ͷ�����������������������ú������ڸ���������
	point[0] = x;
	point[1] = y;
};//д��Բ������
int  spot::get_spot_x() { return point[0]; };//x
int  spot::get_spot_y() { return point[1]; };//y
//��������Ա������ʵ�ֹ��̣����������е�����
