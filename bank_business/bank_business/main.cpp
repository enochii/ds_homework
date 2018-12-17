#include "bank.h"
#include <iostream>
#include <fstream>
#include <cassert>

using namespace std;

int main()
{
	bank _bank;

	fstream fin("data.txt");
	if (!fin) {
		cout << "�ļ���ʧ�ܣ�" << endl;
		exit(1);
	}

	cout << "���������Ľ������" << endl;
	_bank.process(fin);

	cout << "�������������[y/n]��";
	char ctn = ' ';
	cin >> ctn;
	while (ctn == '\n') {
		cin >> ctn;
	}
	if (ctn == 'y' || ctn == 'Y') {
		cout << "������Ļ����� Ctrl+z ������" << endl;
		_bank.process(cin);
	}

	system("pause");
	return 0;
}