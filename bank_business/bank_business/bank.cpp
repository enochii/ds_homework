#include "bank.h"
#include <cassert>
#include <iostream>
#include <string>

void bank::process_once(std::istream& in)
{
	/*int rest_times = 2;
	while (rest_times > 0 && !win_a.empty()) {
		--rest_times;
		std::cout << win_a.front() << seperator();
		win_a.pop();
	}

	int num;
	while (rest_times > 0 && customers > 0) {
		in >> num;--customers;
		//A窗口处理奇数编号的顾客
		if (num % 2 == 1) {
			--rest_times;
			std::cout << num << seperator();
		}
		else {
			win_b.push(num);
		}
	}
	//输入结束，输出所有win_b的顾客编号
	if (customers <= 0) {
		queue_end = true;
		while (!win_b.empty()) {
			std::cout << win_b.front() << seperator();
			win_b.pop();
		}
		return;//直接返回
	}
	//else
	rest_times = 1;
	while (rest_times > 0 && !win_b.empty()) {
		--rest_times;
		std::cout << win_b.front() << seperator();
		win_b.pop();
	}
	while (rest_times > 0 && customers > 0) {
		in >> num;--customers;
		//A窗口处理奇数编号的顾客
		if (num % 2 == 0) {
			--rest_times;
			std::cout << num << seperator();
		}
		else {
			win_a.push(num);
		}
	}
	if (customers <= 0) {
		queue_end = true;
		while (!win_a.empty()) {
			std::cout << win_a.front() << seperator();
			win_a.pop();
		}
		return;//直接返回
	}*/
	process_one_win(in, win_a, win_b, 2, 1);
	process_one_win(in, win_b, win_a, 1, 0);
}

void bank::process_one_win(std::istream& in, queue& cur_win,queue& ano_win,int times,int flag)
{
	using std::cout;
	
	while (times > 0 && !cur_win.empty()) {
		cout << cur_win.front() << seperator();--times;
		cur_win.pop();
	}

	int num = -1;
	while (times > 0 && customers > 0) {
		in >> num;--customers;
		if (num % 2 == flag) {
			cout << num << seperator();
			--times;
		}
		else {
			ano_win.push(num);
		}
	}
	if (customers <= 0) {
		queue_end = true;
		while (!ano_win.empty()) {
			cout << ano_win.front() << seperator();
			ano_win.pop();
		}
	}
}

std::string bank::seperator()
{
	return --not_output_cus == 0 ? "" : " ";
}

void bank::process(std::istream& in)
{
	while (in >> customers) {
		/*
		奇妙的是如果把上面while里面的语句改为in，然后不注释下面
		的语句，那么会多输出一个“处理顺序”。其实就是多做了一次while
		循环，虽然循环内什么也没能输出，因为customers为0并且
		队列a b 都为空

		总结就是：得读到eof（下一个才是eof就不管了）才能触发输入流的fail?位置位，从而使while判断失败
		*/
		//in >> customers;
		if (customers <= 0) {
			std::cout << "顾客数必须大于0...请重新输入..." << std::endl;
			continue;
		}
		not_output_cus = customers;

		std::cout << "处理顺序：" << std::endl;

		while (!queue_end) {
			process_once(in);
		}
		queue_end = false;
		
		std::cout << std::endl;
	}
}