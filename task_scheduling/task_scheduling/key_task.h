#pragma once

#include <vector>

//子任务的抽象
struct Task {
	int from,//起始交接点 
		to,//终止交接点
		cost,//花费
		input_num;//输入时的编号，标记顺序，当有多个关键路径需要逆序输出...
	bool operator<(const Task& right) {
		return this->from < right.from ||
			(this->from == right.from&&this->input_num > right.input_num);
	}
	Task(int _from, int _to, int _cost, int _input_num) :from(_from), to(_to), cost(_cost),input_num(_input_num) {}
};



class solver {
	int															n;//交接点总数量
	std::vector<std::vector<Task> >				subtasks;//记录子任务的首尾交接点和所需时间
	std::vector<Task>									key_tasks;//关键活动

	void														output_key_tasks();//打印关键活动
	int															dfs(int cur);//深度优先搜索关键路径

	std::vector<std::vector<Task> >				sons;//存储关键路径的信息
	std::vector<int>									visited;//判断有无环形依赖
	std::vector<int>									final_costs;//记录该点到终点的耗时

public:
	void														accept_input(std::istream& in);
	void														run();
	void														search_key_path(int cur = 1);
};