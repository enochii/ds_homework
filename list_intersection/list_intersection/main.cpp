#include <list>
#include <iostream>
#include <fstream>
#include "intersection.h"
#include <vector>

using namespace std;

int test_time = 0;

void solve(ifstream& file)
{
	cout << "�� " << ++test_time << " �β���" << endl;
	//��һ������
	list_int l1;
	int temp;
	file >> temp;
	while (temp != -1) {
		l1.insert(l1.end(), temp);
		file >> temp;
	}
	cout << "��һ������ ";
	for (auto it = l1.begin();it != l1.end();++it) {
		if (it != l1.begin())cout << " ";
		cout << *it;
	}
	cout << endl;

	//�ڶ�������
	list_int l2;
	file >> temp;
	while (temp != -1) {
		l2.insert(l2.end(), temp);
		file >> temp;
	}
	cout << "�ڶ������� ";
	for (auto it = l2.begin();it != l2.end();++it) {
		if (it != l2.begin())cout << " ";
		cout << *it;
	}
	cout << endl;

	auto l3 = intersection(l1, l2);
	cout << "�����ǣ� ";
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
		cout << "�ļ���ʧ�ܣ�";
		exit(1);
	}

	//cin.rdbuf(fin.rdbuf());//�ض���
	while (!fin.eof()) {
		solve(fin);
		cout << endl;
	}


	system("pause");
	return 0;
}