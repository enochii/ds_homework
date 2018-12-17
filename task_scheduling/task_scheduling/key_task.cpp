#include "key_task.h"
#include <iostream>
#include <cassert>
#include <algorithm>

//#define DEBUG

enum PATH_KEY{
	CIRCULAR = -2,//环形依赖
	NOPATH,//没有到达终点的路径
	END,//到达终点
};
enum POINT_STATE {
	INITIAL = 0,
	PERMERNANT,
	VISITED,
};

//打印关键路径
void solver::output_key_tasks()
{
	//sort()?
	std::sort(key_tasks.begin(), key_tasks.end());
	for (auto& task : key_tasks) {
		std::cout << task.from << "->" << task.to << std::endl;
	}
}

void solver::accept_input(std::istream& in)
{
	using std::cin;
	using std::cout;

	int m;
	cin >> this->n >> m;

	assert(this->n > 1);
	//++n;
	subtasks.assign(n + 1, std::vector<Task>());
	sons.assign(n + 1, std::vector<Task>());
	visited.assign(n + 1, 0);
	final_costs.assign(n + 1, -1);

	for (int i = 0;i < m;++i) {
		int from, to, value;
		cin >> from >> to >> value;
		subtasks[from].emplace_back(from, to, value, i);
	}
}

int solver::dfs(int cur = 1)
{
	if (visited[cur] == PERMERNANT) {
		return final_costs[cur];
	}
	//judge if the current point has been visted
	else if (visited[cur] == VISITED) {
		//环形依赖...
		return CIRCULAR;
	}
	else if (cur == n) {
		if(subtasks[cur].empty())
			return END;
		//else return CIRCULAR;
	}
	else if (subtasks[cur].empty()) {
		return NOPATH;
	}
	//还要继续递归搜索

	//设置访问标志
	visited[cur] = VISITED;

	int key_path_len = NOPATH;
	std::vector<Task > key_path_infos;
	for (auto& subtask : subtasks[cur]) {
		//key_tasks.push_back(subtask);
		int cost = dfs(subtask.to);

		if (cost == CIRCULAR)return CIRCULAR;//环形依赖

		cost += subtask.cost;
		key_path_infos.emplace_back(subtask.from, subtask.to, cost, subtask.input_num);
		if (cost > key_path_len)key_path_len = cost;
	}
	//清除访问标志
	visited[cur] = PERMERNANT;
	final_costs[cur] = key_path_len;

	if (key_path_len == NOPATH) {
		return NOPATH;
	}
	for (auto &x : key_path_infos) {
		if (x.cost == key_path_len) {
			sons[cur].push_back(x);
			//key_tasks.push_back(std::move(x));
		}
	}
	return key_path_len;
}

void solver::run()
{
	int key_path_len = dfs();
	if (key_path_len < 0) {
		std::cout << 0;
	}
	else {
		std::cout << key_path_len << '\n';

#ifdef DEBUG
		for (auto &ssons : sons) {//single
			for (auto&son : ssons) {
				std::cout << son.to << " ";
			}
			std::cout << std::endl;
		}
#endif // DEBUG
		//找出关键路径
		search_key_path(1);

		output_key_tasks();

	}
}

void solver::search_key_path(int cur)
{
	if (cur == n)return;

	for (auto &son: sons[cur]) {
		key_tasks.push_back(son);
		search_key_path(son.to);
	}
	
}