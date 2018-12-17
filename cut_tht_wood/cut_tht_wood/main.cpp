#include "hfm.h"
//#include <vector>

using std::cout;
using std::cin;
//using std::endl;

int main()
{
	cout << "请输入木头最终的段数：";
	int n;
	cin >> n;

	cout << "请依次输入权值：";
	std::vector<int> values;
	for (int i = 0;i < n;++i) {
		int value;
		cin >> value;

		values.push_back(value);
	}

	hfm_tree hfm(values.begin(), values.end());
	cout << "最终结果为：" << hfm.get_sum() << std::endl;

	system("pause");
	return 0;
}