#include "translation.h"
#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<std::string> test_strs = {
		"2 + 3 * ( 7 - 4 ) + 8 / 4",
		"( ( 2 + 3) * 4 - ( 8 + 2 ) ) / 5",
		"1314 + 25.5 * 12",
		"-2 * ( +3 )",
		"123",
		"-2 * ((( +3 )))",
		"2 + 3   *   ( 7- 4)   + 8 /       4"
	};

	parser pr("");
	for (const auto &str : test_strs) {
		cout << "ת��ǰ��" << str << endl;
		cout << "ת����";

		pr.set_exp(str);
		pr.translation();

		cout << "\n" << endl;
	}

	cout << "�����ǲ��Խ�����㻹���Լ��������������\n������Ϸ��ı��ʽ��\n";
	std::string exp;

	getline(cin, exp);
	//if (exp[exp.size() - 1] == '\n')cout << "0-0";
	cout << "ת��ǰ��" << exp << endl;
	cout << "ת����";
	pr.set_exp(exp);
	pr.translation();

	system("pause");

	return 0;
}