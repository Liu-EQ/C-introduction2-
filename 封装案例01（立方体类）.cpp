#include<iostream>
#include<string>
using namespace std;



//案例描述：设计一个立方体类（Cube）
			//要求：求出立方体的面积和体积；分别使用全局函数和成员函数判断两个立方体是否相等
				//分析：立方体类——属性：长宽高（用于计算立方体体积和面积）
									//Tips：立方体体积公式：V=（长*宽*高）；面积公式：（长*宽+宽*高+长*高）*2=S
				//分析：立方体类——行为：计算面积、体积；比较两个立方体是否相等（长、宽、高都相等）
class Cube
{
public:

	//行为
	//面积
	int  S_Cube() 
	{
		return (H*L+ L*W+ W*H) * 2;
	};
	//体积
	int  V_Cube() 
	{
		return L*W*H;
	
	};
	//还需要有一个成员函数来比较两个立方体是否相等
	string Compare(Cube CC2) //有一个成员就是自身，所以只需要传入一个参数即可
	{
		if (H==CC2.H&&W == CC2.W&&L == CC2.L)
		{
			return "这两个立方体是相同的！！！！";
		}
		else
		{
			return "这两个立方体并不相同！！！！";
		}

	};
	//公共接口（用于输入立方体的长宽高）
	void set_L(int a) { L = a; };
	void set_W(int a) { W = a; };
	void set_H(int a) { H = a; };
	//公共接口（用于获取立方体长宽高）
	int get_L() { return L; };
	int get_W() { return W; };
	int get_H() { return H; };
private:
	//属性
	int L = 5;//length
	int W = 7;//Wideth
	int H = 9;//Hight
};


string Compare1(Cube &CC1, Cube &CC2)//数据传入简单——使用引用
{
	if (CC1.get_L() == CC2.get_L()&&CC1.get_W() == CC2.get_W()&&CC1.get_H() == CC2.get_H())//函数的（）不能少
	{
		return "这两个立方体是相同的！！！！";
	}
	else
	{
		return "这两个立方体并不相同！！！！";
	}

};//全局函数

int main() 
{
	Cube V1, V2;
	V1.set_L(10); V1.set_W(10); V1.set_H(10);
	V2.set_L(10); V2.set_W(10); V2.set_H(10);
	cout << "立方体V1的面积为：" << V1.S_Cube()<<endl;
	cout << "立方体V2的面积为：" << V2.S_Cube() << endl;
	cout << "立方体V1的体积为：" << V1.V_Cube() << endl;
	cout << "立方体V2的体积为：" << V2.V_Cube() << endl;
	cout<<V1.Compare(V2)<<endl;//调用成员函数判断
	cout << Compare1(V1,V2) << endl;//调用全局函数
	//全局函数和成员函数进行比较操作，传入参数是不同的



	cout << endl;
	system("pause");
	return 0;

}