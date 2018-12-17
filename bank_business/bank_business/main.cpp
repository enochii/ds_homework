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
		cout << "文件打开失败！" << endl;
		exit(1);
	}

	cout << "测试用例的结果如下" << endl;
	_bank.process(fin);

	cout << "你想继续输入吗？[y/n]：";
	char ctn = ' ';
	cin >> ctn;
	while (ctn == '\n') {
		cin >> ctn;
	}
	if (ctn == 'y' || ctn == 'Y') {
		cout << "想结束的话输入 Ctrl+z 就行了" << endl;
		_bank.process(cin);
	}

	system("pause");
	return 0;
}