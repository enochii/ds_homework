#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include "List.h"

//#define REDIRECT//�ض����־

using namespace std;

int main()
{
	cout << "�������Ƚ�������ϵͳ��\n�����뿼��������";
	int stu_num = 0;

#ifdef REDIRECT
	streambuf *backup = cin.rdbuf();
	ifstream fin;
	fin.open("data.txt");
	if (!fin)
	{
		cout << "�ļ���ʧ�ܣ�";
		exit(1);
	}
	
	cin.rdbuf(fin.rdbuf());//�ض���
#endif	
	cin >> stu_num;
	List test_sys;
	cout << "���������뿼���Ŀ��ţ��������Ա����估�������" << std::endl;
	
	for (int i = 0;i < stu_num;++i)
	{
		stu_ptr temp = new Node();
		cin >> *temp;
		test_sys.insert(temp, i + 1);
	}

#ifdef REDIRECT
	cin.rdbuf(backup);//�����ض���
#endif // REDIRECT

	test_sys.show_all();

	cout << "��ѡ����Ҫ���еĲ�����1Ϊ���룬2Ϊɾ����3Ϊ���ң�4Ϊ�޸ģ�5Ϊͳ�ƣ�"
		<< endl;
	//��ѭ��
	while (true)
	{
		int operation = -1;
		cout << "��ѡ����Ҫ���еĲ�����";
		cin >> operation;
		switch (operation) {
		case 0:
			break;
		case 1: {//insert
			cout << "��������Ҫ����Ŀ�����λ�ã�" << endl;
			int position;
			cin >> position;
			cout << "����������Ҫ����Ŀ����Ŀ��ţ��������Ա����估�������";
			auto stu = new Node();
			cin >> *stu;
			test_sys.insert(stu, position);
			break;
		}
		case 2: {//delete
			cout << "��������Ҫɾ���Ŀ�����ѧ�ţ�";
			int num;
			cin >> num;
			test_sys.destroy(num);
			break;
		}
		case 3: {//find
			cout << "��������Ҫ���ҵ�ѧ����ѧ�ţ�";
			int num;
			cin >> num;
			test_sys.find(num);
			break;
		}
		case 4: {//modify
			cout << "��������Ҫ�޸ĵ�ѧ����ѧ�ţ�";
			int num;
			cin >> num;
			test_sys.modify(num);
			break;
		}
		case 5: {//show_all
			test_sys.show_all();
			break;
		}
		default:
			cout << "������Ĳ�������";
			break;
		}
		if (operation == 0)
		{
			cout << "��ѡ�����˳����Ա���ϵͳ" << endl;
			break;
		}
	}

	system("pause");
	return 0;
}