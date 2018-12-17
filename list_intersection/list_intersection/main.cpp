#include <list>
#include <iostream>
#include <fstream>
#include "intersection.h"
#include <vector>

using namespace std;

int test_time = 0;

void solve(ifstream& file)
{
	cout << "第 " << ++test_time << " 次测试" << endl;
	//第一个链表
	list_int l1;
	int temp;
	file >> temp;
	while (temp != -1) {
		l1.insert(l1.end(), temp);
		file >> temp;
	}
	cout << "第一个链表： ";
	for (auto it = l1.begin();it != l1.end();++it) {
		if (it != l1.begin())cout << " ";
		cout << *it;
	}
	cout << endl;

	//第二个链表
	list_int l2;
	file >> temp;
	while (temp != -1) {
		l2.insert(l2.end(), temp);
		file >> temp;
	}
	cout << "第二个链表： ";
	for (auto it = l2.begin();it != l2.end();++it) {
		if (it != l2.begin())cout << " ";
		cout << *it;
	}
	cout << endl;

	auto l3 = intersection(l1, l2);
	cout << "交集是： ";
	if (l3.empty()) {
		cout << "NULL" << endl;
	}
	else {
		for (auto it = l3.begin();it != l3.end();++it) {
			if (it != l3.begin())cout << " ";
			cout << *it;
		}
	}
	cout << endl;
}

int main()
{
	//streambuf *backup = cin.rdbuf();
	ifstream fin;
	fin.open("data.txt");
	if (!fin)
	{
		cout << "文件打开失败！";
		exit(1);
	}

	//cin.rdbuf(fin.rdbuf());//重定向
	while (!fin.eof()) {
		solve(fin);
		cout << endl;
	}


	system("pause");
	return 0;
}