#pragma once

#include <queue>


class bank {
private:
	using queue = std::queue<int>;
	queue win_a, win_b;
	
	int customers;
	int not_output_cus;

	//队列是否到达最后
	bool queue_end;

	//把窗口b处理一位顾客的时间看为单位时间，process_once执行单位时间内窗口a和窗口b发生的处理流程
	void process_once(std::istream& in);
	void process_one_win(std::istream& in, queue& cur_win, queue& ano_win, int times, int flag);

	inline std::string seperator();
public:
	bank():queue_end(false){}
	void process(std::istream& in);
};