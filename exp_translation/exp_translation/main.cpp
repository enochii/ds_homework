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
		cout << "转换前：" << str << endl;
		cout << "转换后：";

		pr.set_exp(str);
		pr.translation();

		cout << "\n" << endl;
	}
	
	system("pause");

	return 0;
}