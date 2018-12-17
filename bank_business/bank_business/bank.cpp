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
		//A���ڴ���������ŵĹ˿�
		if (num % 2 == 1) {
			--rest_times;
			std::cout << num << seperator();
		}
		else {
			win_b.push(num);
		}
	}
	//����������������win_b�Ĺ˿ͱ��
	if (customers <= 0) {
		queue_end = true;
		while (!win_b.empty()) {
			std::cout << win_b.front() << seperator();
			win_b.pop();
		}
		return;//ֱ�ӷ���
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
		//A���ڴ���������ŵĹ˿�
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
		return;//ֱ�ӷ���
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
		����������������while���������Ϊin��Ȼ��ע������
		����䣬��ô������һ��������˳�򡱡���ʵ���Ƕ�����һ��while
		ѭ������Ȼѭ����ʲôҲû���������ΪcustomersΪ0����
		����a b ��Ϊ��

		�ܽ���ǣ��ö���eof����һ������eof�Ͳ����ˣ����ܴ�����������fail?λ��λ���Ӷ�ʹwhile�ж�ʧ��
		*/
		//in >> customers;
		if (customers <= 0) {
			std::cout << "�˿����������0...����������..." << std::endl;
			continue;
		}
		not_output_cus = customers;

		std::cout << "����˳��" << std::endl;

		while (!queue_end) {
			process_once(in);
		}
		queue_end = false;
		
		std::cout << std::endl;
	}
}