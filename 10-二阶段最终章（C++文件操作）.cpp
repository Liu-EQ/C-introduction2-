#include<iostream>
#include<string>
#include<fstream>
using namespace std;

//10.0 文件操作
//两大类：文本文件读写操作、二进制文件读写操作



//10.1 文本文件读写操作
	//10.1.1 文本文件写操作（写操作可以视为输出到文本文件中）
void TxtOut() 
{
	// 1、包含头文件：#include<fstream>————必须要有的一步
		//2、创建流对象：ofstream ofs;
		ofstream ofs;
		//3、打开文件：ofs.open("文件路径",打开方式);
					//此处的文件路径可以是绝对路径也可以是相对路径;
					//此处的打开方式也需要记忆：（ios是必加前缀；in-读；out-写；ate-在文件尾打开；app-追加方式写入；trunc-如果文件存在，先删除再重新创建；binary-二进制方式）
		ofs.open("test.txt",ios::out);
		//4、写数据：ofs<<"写入的数据";
		ofs << "just for a test!" << endl;
		//5、关闭文件：ofs.close();————必须要有的一步
		ofs.close();
};
//10.1.2 文本文件读操作
void TxtIn() 
{
	//1、添加头文件
	//2、创建流对象：ifstream ifs;
	ifstream ifs;
	//3、打开文件并判断文件是否打开成功：ifs.open("文件路径",打开方式);
						//使用is_open()判断文件是否打开成功
	ifs.open("test.txt",ios::in);
	if (!ifs.is_open())
	{
		cout << "文件打开失败" << endl;
	}
	//4、读数据（四种方式）
	//第一种
	char buf[1024] = {0};
	//while (ifs >> buf)
	//{
	//	cout << buf<<endl ;//输出格式不会完全和写入格式相同，受输出语句的影响
	//}
	//第二种（推荐）
	while (ifs.getline(buf,sizeof(buf)))
	{
		cout << buf << endl;
	}
	//第三种(推荐)
	string buf1;
	while (getline(ifs,buf1))
	{
		cout << buf << endl;
	}
	//第四种（不推荐使用，仅作了解）
	char c;
	while ((c=ifs.get())!=EOF)//eof——end of file
	{
		cout << c;
	}
	//5、关闭文件：ifs。cliose();
	ifs.close();
};

class person 
{
public:
	string M_Name;
	int    M_Age;
};

// 10.2 二进制文件读写操作
//10.2.1 二进制文件写操作
void BinaryOut() 
{
	//二进制文件不仅能写入原有的数据类型，还可以写入自定义的数据类型
	//1、包含头文件
	//2、创建流对象：ofstream ofs;
	ofstream ofs;
	//3、打开文件：ofs.open("文件位置"，打开方式（需要额外添加：ios::binary）)
	ofs.open("Binary.txt", ios::out | ios::binary);
	//4、写文件：通过write函数进行写入（与其说是写文件不如说是写入对象）
	person P = { "青木",21 };
	ofs.write((char *)&P, sizeof(P));//注意格式，更像是把一个对象传入文本文件，而不太像是写入数据
	//5、关闭文件
	ofs.close();
	//可以封装成一个函数，而不必要在主函数中混乱
};

//10.2.2 二进制文件读取操作
void  BianryIn() 
{
	//1、包含头文件
	//2、创建流对象： ifstream ifs;
	ifstream ifs;
	//3、打开文件并判断是否打开成功：ifs.open("文件位置",打开方式);
			//使用ifs.is_open判断是否成功打开
	ifs.open("Binary.txt",ios::in|ios::binary);
	if (!ifs.is_open())
	{
		cout << "文件未成功打开" << endl;
	}
	//4、读文件：ifs.read(char *,int length)
	person p2;
	ifs.read((char *)&p2,sizeof(p2));
	cout << p2.M_Name<<"\t"<<p2.M_Age << endl;
			//输出格式仍然受输出语句影响
	//5、关闭文件：ifs.close();
	ifs.close();
};

int main() 
{
	BinaryOut();
	BianryIn();
	
	

	


	



	cout << endl;
	system("pause");
	return 0;
}