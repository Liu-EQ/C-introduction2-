#include<iostream>
#include<string>
#include<fstream>
using namespace std;


//ְ������ϵͳ
//�������������˾�ڲ�Ա����Ϣ
		/*Ա�����ࣺ��ͨԱ������ɾ�����������
					��������ϰ彻�������񣬲��·������Ա��
					�ϰ壺����˾������
						ְ������ְ��������ʹ�ò�ͬ��������ʵ�֣�����һ��Ա�����࣬�ɴ���������ͬ��Ա�������Ӧ��ͬ��Ա��*/
/*ģ�����
	ģ��һ���˳�ģ�顪��ͬ���������һ��Ա�����飬��������������ҵ�ڲ�Ա�����˳�ģ����Ҫ��ֹѭ������ִ����������
	ģ���������ְ����Ϣ�������û�ѡ������ְ�������ͣ���ѡ��ͬ�����������ӣ����캯������һ�£���ʹ���вι��캯��
			ͬʱ�������Ϻ����鳤�ȼ�һ��ʵ���û������������û���Ҫ���ı��ļ�����������ļ������д洢���˴�Ҳ�ɷ�װһ����������д�����
	ģ��������ʾְ����Ϣ������Ӧ�ļ��������
	ģ����������ģ�顪������forѭ�����в���
	ģ���ģ�ɾ��ְ����Ϣ�������鳤�ȼ�һ������ɾ���ļ��Կռ�¼����ԭ�м�¼�ﵽɾ��Ŀ��
	ģ���壺�޸�ģ�顪��ʹ�õ��������޸ĵķ�ʽ��������ʱ��������ֵ���滻��������һ����������������ɾ�����޸ġ�����
	ģ����������ģ�顪�����������С���ʹ��ð�����򣨱Ƚϻ�׼βԱ����ţ�
	ģ���ߣ����ģ�顪�����鳤����Ϊ0*/

//ְ������
class staff
{
public:
	//���幫���ӿ��������Ը�ֵ
	int getnum() { return M_num; };
	string getname() { return M_name; };
	int getsex() { return M_sex; };
	int getage() { return M_age; };
	//ְλ
	virtual void positiion() = 0;//��һ�����麯����ʹ�û��۳�Ϊ�����࣬�޷�ʵ��������
	//Ĭ�Ϲ��캯��
	staff (int num, string name, int sex, int age, int posi)
	{
		M_num = num;
		M_name = name;
		M_sex = sex;
		M_age = age;
		M_posi = posi;
	};
protected:
	int M_num;//Ա�����
	string M_name;//����
	int M_sex;//�Ա�1/2���֣�����������Ч�ԣ�
	int M_age;//����
	int M_posi;//ְλ
};
//��ͨԱ������
class worker :public staff
{
public:
	virtual void positiion() 
	{
		if ( M_posi==1)
		{
			cout << "��Ա��Ϊ��ͨԱ����ְ����ɾ����������񣡣���" << endl;
		}

	};
};
//��������
class manager :public staff
{
public:
	virtual void positiion()
	{
		if (M_posi == 2)
		{
			cout << "��Ա��Ϊ����,ְ������ϰ彻�������񣬲��Ҹ�Ա���������񣡣���" << endl;
		}

	};
};
//�ϰ�����
class boss :public staff
{
public:
	virtual void positiion()
	{
		if (M_posi == 3)
		{
			cout << "��Ա��Ϊ�ϰ壬ְ��ͳ�ﰲ�Ź�˾�ĸ������񣡣���" << endl;
		}

	};
};
//���ܲ˵�չʾ
void Display() 
{
	//����ģ�顪����װ�ɺ���
	cout << "����������ӭʹ����ľְ����Ϣ����ϵͳ����������" << endl;
	cout << "������������0-�˳�ְ����Ϣ����ϵͳ������������" << endl;
	cout << "������������1-��ʾ��ҵ��ǰԱ����Ϣ������������" << endl;
	cout << "������������2-�����ҵ����Ա����Ϣ������������" << endl;
	cout << "������������3-������ҵ�ڲ�Ա����Ϣ������������" << endl;
	cout << "������������4-�޸���ҵ�ڲ�Ա����Ϣ������������" << endl;
	cout << "������������5-ɾ����ҵ�ڲ�Ա����Ϣ������������" << endl;
	cout << "������������6-������ҵ�ڲ�Ա����Ϣ������������" << endl;
	cout << "������������9-�����ҵ�ڲ�Ա����Ϣ������������" << endl;
};
//��Ϣչʾ��������ʹ�ö������ļ���ȡ����
//��Ϣ��Ӻ�������ʹ�ö������ļ�д�����
void InforBinaryInput(staff *work);
staff* InformationInput();
//��Ϣչʾ
void  BianryIn(staff *p2)
{
	//1������ͷ�ļ�
	//2������������ ifstream ifs;
	ifstream ifs;
	//3�����ļ����ж��Ƿ�򿪳ɹ���ifs.open("�ļ�λ��",�򿪷�ʽ);
			//ʹ��ifs.is_open�ж��Ƿ�ɹ���
	ifs.open("StaffInformation.txt", ios::in | ios::binary);
	if (!ifs.is_open())
	{
		cout << "�ļ�δ�ɹ���" << endl;
	}
	//4�����ļ���ifs.read(char *,int length)
	ifs.read((char *)&p2, sizeof(p2));
	cout << p2->getnum() << " " << p2->getname() << " " 
		<<p2->getsex() << " " <<p2->getage() << " ";
	p2->positiion();
	//�����ʽ��Ȼ��������Ӱ��
//5���ر��ļ���ifs.close();
	ifs.close();
};


int main() 
{
	staff * employee[1000];
	int* length = new (int);
	Display();
	cout << "��ѡ����Ҫʹ�õĹ��ܣ�" << endl;
	int select;
	cin >> select;
	while (true)
	{
		switch (select)
		{
		case 0://�˳�ģ��
		{
			cout << "��ӭ�´�ʹ�ã�����" << endl;
			system("pause");
			return 0;
			break;
		}//�˳�ģ�顪��over
		case 1://��ʾģ��
		{
			//��Ϣ�������
			for (int i = 0; i < length; i++)
			{
				BianryIn(employee[i]);
			}


			system("pause");
			system("cls");
			break;
		}
		case 2://���ģ��
		{
			employee[length]=InformationInput();//������Ϣ���뺯��
			InforBinaryInput(employee[length]);
			cout << "Ա����Ϣ��ӳɹ���" << endl;
			length++;
			system("pause");
			system("cls");
			break;
		}
		case 3://����ģ��
		{
			system("pause");
			system("cls");
			break;
		}
		case 4://�޸�ģ��
		{
			system("pause");
			system("cls");
			break;
		}
		case 5://ɾ��ģ��
		{
			system("pause");
			system("cls");
			break;
		}
		case 6://����ģ��
		{
			system("pause");
			system("cls");
			break;
		}
		case 9://���ģ��
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
		cout << "��ѡ����Ҫ����ʹ�õĹ��ܣ�" << endl;//�˳�ģ����Ψһ���˳�����
		cin >> select;
	}
	
}


//���ģ�麯������
staff* InformationInput()
{
	cout << "��������Ҫ��ӵ���Ա����Ա����ţ�" << endl;
	int num1;
	cin >> num1;
	cout << "��������Ҫ��ӵ���Ա����������" << endl;
	string name1;
	cin >> name1;
	cout << "��������Ҫ��ӵ���Ա�����Ա�" << endl;
	cout << "0����Ů��1������" << endl;
	int sex1;
	cin >> sex1;
	if (sex1!=1&&sex1!=0)
	{
		cout << "������Ա��Ų��Ϸ�������" << endl;
	}
	cout << "��������Ҫ��ӵ���Ա�������䣺" << endl;
	int age1;
	cin >> age1;
	cout << "��������Ҫ��ӵ���Ա����ְλ��ţ�" << endl;
	cout << "1������ְͨ����\n"
		 << "2������ ��\n"
		 << "3������ ��\n"<< endl;
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
//��Ϣд�뺯������
void InforBinaryInput(staff *work)
{
	//ʹ���ļ�д�뺯�����д洢
	ofstream ofs;
	ofs.open("StaffInformation.txt", ios::out | ios::binary);
	ofs.write((char *)work, sizeof(work));
}
