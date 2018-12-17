/*
2018/12/9 by 施程航
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
	
	cout << "**\t\t排序算法比较\t\t**\n";
	cout << seperator;
	cout << "**\t\t1 --- 冒泡排序\t\t**\n";
	cout << "**\t\t2 --- 选择排序\t\t**\n";
	cout << "**\t\t3 --- 直接插入排序\t**\n";
	cout << "**\t\t4 --- 希尔排序\t\t**\n";
	cout << "**\t\t5 --- 快速排序\t\t**\n";
	cout << "**\t\t6 --- 堆排序\t\t**\n";
	cout << "**\t\t7 --- 归并排序\t\t**\n";
	cout << "**\t\t8 --- 基数排序\t\t**\n";
	cout << "**\t\t9 --- 退出程序\t\t**\n";
	cout << "**\t\t10 --- 全部排序算法\t**\n";
	cout << seperator;

	cout << "请输入要产生的随机数的个数：";
	int random_int;
	cin >> random_int;

	
	generate_random_number(random_int, arr);
	arr_copy = arr;
	
	int sort_num;
	while (true) {
		cout << "\n请选择排序算法：\t";
		cin >> sort_num;
		if (sort_num == 9)break;
		if (sort_num == 10) {
			cout << "所有算法运行如下：\n";
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