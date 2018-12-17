#pragma once

#include <queue>


class bank {
private:
	using queue = std::queue<int>;
	queue win_a, win_b;
	
	int customers;
	int not_output_cus;

	//�����Ƿ񵽴����
	bool queue_end;

	//�Ѵ���b����һλ�˿͵�ʱ�俴Ϊ��λʱ�䣬process_onceִ�е�λʱ���ڴ���a�ʹ���b�����Ĵ�������
	void process_once(std::istream& in);
	void process_one_win(std::istream& in, queue& cur_win, queue& ano_win, int times, int flag);

	inline std::string seperator();
public:
	bank():queue_end(false){}
	void process(std::istream& in);
};