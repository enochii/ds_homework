#include "hfm.h"
//#include <vector>

using std::cout;
using std::cin;
//using std::endl;

int main()
{
	cout << "������ľͷ���յĶ�����";
	int n;
	cin >> n;

	cout << "����������Ȩֵ��";
	std::vector<int> values;
	for (int i = 0;i < n;++i) {
		int value;
		cin >> value;

		values.push_back(value);
	}

	hfm_tree hfm(values.begin(), values.end());
	cout << "���ս��Ϊ��" << hfm.get_sum() << std::endl;

	system("pause");
	return 0;
}