/*
2018/12/9 by ʩ�̺�
*/

#include <iostream>
#include <vector>
#include <string>
#include <deque>
#include <list>

#include <cstdlib>
#include <cmath>

#include "sort.h"
#include "test.h"

using std::cout;
using std::cin;

//suppport list, deque, and vector
template<class Container>
void generate_random_number(int random_int, Container& c)
{
	srand(time(NULL));

	while (random_int-- > 0) {
		c.push_back(rand());
	}
}

std::vector<int> arr, arr_copy;

int main()
{
#ifdef __SHELL_STEPS__
	for (int i = 0;i <= 20;++i) {
		//cout << (pow(3, i + 1) - 1) / 2 << " ";
	}
	int gap = 1;
	for (int i = 0;i <= 20;++i) {
		cout << gap << " ";
		gap = gap * 3 + 1;
	}
#endif//__SHELL_STEPS__
	std::string seperator(42, '=');seperator.push_back('\n');
	
	cout << "**\t\t�����㷨�Ƚ�\t\t**\n";
	cout << seperator;
	cout << "**\t\t1 --- ð������\t\t**\n";
	cout << "**\t\t2 --- ѡ������\t\t**\n";
	cout << "**\t\t3 --- ֱ�Ӳ�������\t**\n";
	cout << "**\t\t4 --- ϣ������\t\t**\n";
	cout << "**\t\t5 --- ��������\t\t**\n";
	cout << "**\t\t6 --- ������\t\t**\n";
	cout << "**\t\t7 --- �鲢����\t\t**\n";
	cout << "**\t\t8 --- ��������\t\t**\n";
	cout << "**\t\t9 --- �˳�����\t\t**\n";
	cout << "**\t\t10 --- ȫ�������㷨\t**\n";
	cout << seperator;

	cout << "������Ҫ������������ĸ�����";
	int random_int;
	cin >> random_int;

	
	generate_random_number(random_int, arr);
	arr_copy = arr;
	
	int sort_num;
	while (true) {
		cout << "\n��ѡ�������㷨��\t";
		cin >> sort_num;
		if (sort_num == 9)break;
		if (sort_num == 10) {
			cout << "�����㷨�������£�\n";
			for (int i = 0;i < 9;++i) {
				dispatch(i, arr.begin(), arr.end());
				arr = arr_copy;
				cout << "\n";
			}
			continue;
		}
		dispatch(sort_num, arr.begin(), arr.end());
#ifdef DEBUG
		if (!test(arr.begin(), arr.end()) && sort_num <= 10)
			std::cerr << "algorithm doesn't work well...\n";
		//display_container(arr);
#endif // DEBUG
		arr = arr_copy;
	}

	system("pause");
	return 0;
}