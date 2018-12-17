#pragma once

#include <vector>

//������ĳ���
struct Task {
	int from,//��ʼ���ӵ� 
		to,//��ֹ���ӵ�
		cost,//����
		input_num;//����ʱ�ı�ţ����˳�򣬵��ж���ؼ�·����Ҫ�������...
	bool operator<(const Task& right) {
		return this->from < right.from ||
			(this->from == right.from&&this->input_num > right.input_num);
	}
	Task(int _from, int _to, int _cost, int _input_num) :from(_from), to(_to), cost(_cost),input_num(_input_num) {}
};



class solver {
	int															n;//���ӵ�������
	std::vector<std::vector<Task> >				subtasks;//��¼���������β���ӵ������ʱ��
	std::vector<Task>									key_tasks;//�ؼ��

	void														output_key_tasks();//��ӡ�ؼ��
	int															dfs(int cur);//������������ؼ�·��

	std::vector<std::vector<Task> >				sons;//�洢�ؼ�·������Ϣ
	std::vector<int>									visited;//�ж����޻�������
	std::vector<int>									final_costs;//��¼�õ㵽�յ�ĺ�ʱ

public:
	void														accept_input(std::istream& in);
	void														run();
	void														search_key_path(int cur = 1);
};