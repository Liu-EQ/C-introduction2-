#include<iostream>
#include<string>
#include<fstream>
using namespace std;

//10.0 �ļ�����
//�����ࣺ�ı��ļ���д�������������ļ���д����



//10.1 �ı��ļ���д����
	//10.1.1 �ı��ļ�д������д����������Ϊ������ı��ļ��У�
void TxtOut() 
{
	// 1������ͷ�ļ���#include<fstream>������������Ҫ�е�һ��
		//2������������ofstream ofs;
		ofstream ofs;
		//3�����ļ���ofs.open("�ļ�·��",�򿪷�ʽ);
					//�˴����ļ�·�������Ǿ���·��Ҳ���������·��;
					//�˴��Ĵ򿪷�ʽҲ��Ҫ���䣺��ios�Ǳؼ�ǰ׺��in-����out-д��ate-���ļ�β�򿪣�app-׷�ӷ�ʽд�룻trunc-����ļ����ڣ���ɾ�������´�����binary-�����Ʒ�ʽ��
		ofs.open("test.txt",ios::out);
		//4��д���ݣ�ofs<<"д�������";
		ofs << "just for a test!" << endl;
		//5���ر��ļ���ofs.close();������������Ҫ�е�һ��
		ofs.close();
};
//10.1.2 �ı��ļ�������
void TxtIn() 
{
	//1�����ͷ�ļ�
	//2������������ifstream ifs;
	ifstream ifs;
	//3�����ļ����ж��ļ��Ƿ�򿪳ɹ���ifs.open("�ļ�·��",�򿪷�ʽ);
						//ʹ��is_open()�ж��ļ��Ƿ�򿪳ɹ�
	ifs.open("test.txt",ios::in);
	if (!ifs.is_open())
	{
		cout << "�ļ���ʧ��" << endl;
	}
	//4�������ݣ����ַ�ʽ��
	//��һ��
	char buf[1024] = {0};
	//while (ifs >> buf)
	//{
	//	cout << buf<<endl ;//�����ʽ������ȫ��д���ʽ��ͬ�����������Ӱ��
	//}
	//�ڶ��֣��Ƽ���
	while (ifs.getline(buf,sizeof(buf)))
	{
		cout << buf << endl;
	}
	//������(�Ƽ�)
	string buf1;
	while (getline(ifs,buf1))
	{
		cout << buf << endl;
	}
	//�����֣����Ƽ�ʹ�ã������˽⣩
	char c;
	while ((c=ifs.get())!=EOF)//eof����end of file
	{
		cout << c;
	}
	//5���ر��ļ���ifs��cliose();
	ifs.close();
};

class person 
{
public:
	string M_Name;
	int    M_Age;
};

// 10.2 �������ļ���д����
//10.2.1 �������ļ�д����
void BinaryOut() 
{
	//�������ļ�������д��ԭ�е��������ͣ�������д���Զ������������
	//1������ͷ�ļ�
	//2������������ofstream ofs;
	ofstream ofs;
	//3�����ļ���ofs.open("�ļ�λ��"���򿪷�ʽ����Ҫ������ӣ�ios::binary��)
	ofs.open("Binary.txt", ios::out | ios::binary);
	//4��д�ļ���ͨ��write��������д�루����˵��д�ļ�����˵��д�����
	person P = { "��ľ",21 };
	ofs.write((char *)&P, sizeof(P));//ע���ʽ�������ǰ�һ���������ı��ļ�������̫����д������
	//5���ر��ļ�
	ofs.close();
	//���Է�װ��һ��������������Ҫ���������л���
};

//10.2.2 �������ļ���ȡ����
void  BianryIn() 
{
	//1������ͷ�ļ�
	//2������������ ifstream ifs;
	ifstream ifs;
	//3�����ļ����ж��Ƿ�򿪳ɹ���ifs.open("�ļ�λ��",�򿪷�ʽ);
			//ʹ��ifs.is_open�ж��Ƿ�ɹ���
	ifs.open("Binary.txt",ios::in|ios::binary);
	if (!ifs.is_open())
	{
		cout << "�ļ�δ�ɹ���" << endl;
	}
	//4�����ļ���ifs.read(char *,int length)
	person p2;
	ifs.read((char *)&p2,sizeof(p2));
	cout << p2.M_Name<<"\t"<<p2.M_Age << endl;
			//�����ʽ��Ȼ��������Ӱ��
	//5���ر��ļ���ifs.close();
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