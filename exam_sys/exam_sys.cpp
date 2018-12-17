#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include "List.h"

//#define REDIRECT//重定向标志

using namespace std;

int main()
{
	cout << "首先请先建立考生系统！\n请输入考生人数：";
	int stu_num = 0;

#ifdef REDIRECT
	streambuf *backup = cin.rdbuf();
	ifstream fin;
	fin.open("data.txt");
	if (!fin)
	{
		cout << "文件打开失败！";
		exit(1);
	}
	
	cin.rdbuf(fin.rdbuf());//重定向
#endif	
	cin >> stu_num;
	List test_sys;
	cout << "请依次输入考生的考号，姓名，性别，年龄及报考类别！" << std::endl;
	
	for (int i = 0;i < stu_num;++i)
	{
		stu_ptr temp = new Node();
		cin >> *temp;
		test_sys.insert(temp, i + 1);
	}

#ifdef REDIRECT
	cin.rdbuf(backup);//撤销重定向
#endif // REDIRECT

	test_sys.show_all();

	cout << "请选择您要进行的操作（1为插入，2为删除，3为查找，4为修改，5为统计）"
		<< endl;
	//主循环
	while (true)
	{
		int operation = -1;
		cout << "请选择您要进行的操作：";
		cin >> operation;
		switch (operation) {
		case 0:
			break;
		case 1: {//insert
			cout << "请输入你要插入的考生的位置：" << endl;
			int position;
			cin >> position;
			cout << "请依次输入要插入的考生的考号，姓名，性别，年龄及报考类别：";
			auto stu = new Node();
			cin >> *stu;
			test_sys.insert(stu, position);
			break;
		}
		case 2: {//delete
			cout << "请输入你要删除的考生的学号：";
			int num;
			cin >> num;
			test_sys.destroy(num);
			break;
		}
		case 3: {//find
			cout << "请输入你要查找的学生的学号：";
			int num;
			cin >> num;
			test_sys.find(num);
			break;
		}
		case 4: {//modify
			cout << "请输入你要修改的学生的学号：";
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
			cout << "你输入的操作有误！";
			break;
		}
		if (operation == 0)
		{
			cout << "您选择了退出考试报名系统" << endl;
			break;
		}
	}

	system("pause");
	return 0;
}