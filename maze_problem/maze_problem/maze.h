#pragma once

#include <stack>
#include <vector>
#include <string>
#include <iostream>
#include <cassert>

//#define DEBUG

class maze {

	using Point = std::pair<int, int>;
	//�о���char�����ʱ������ܴ�
	std::vector<std::string> map;
	std::vector<std::vector<Point>> parent;
	
	std::vector<Point> path;
	Point end, start;

	//���Թ�����·������map��·���������ð�·��������
	void solver() {
		assert(end.first != -1 && start.first != -1);

		static int dir[5] = { 0,1,0,-1,0 };
		std::stack<Point> points;
		points.push(start);
		//dfs
		while (!points.empty()) {
			const auto top = points.top();
			points.pop();

			if (top.first == end.first&&top.second == end.second) {
#ifdef DEBUG
				std::cout << "search done!";
#endif
				break;
			}
			for (int i = 0;i < 4;++i) {
				int x = top.first + dir[i], y = top.second + dir[i + 1];
				if (x < 0 || x >= map.size() || y<0 || y >= map[0].size())continue;
				if ((map[x][y] == '0' || map[x][y] == 'E')&&parent[x][y].first == -1) {
					parent[x][y] = top;
					points.emplace(x,y);
				}
			}
		}
		//
		
	}

public:
	//ctr
	maze():end(-1,-1),start(-1,-1){}

	void get_solution() {
		solver();
		for (auto x : map)std::cout << x << std::endl;
		//��ӡ������ĵ�ͼ��·��
		auto cur = end;
		while (cur != Point(-1, -1)) {
#ifdef DEBUG
			std::cout << "( " << cur.first << ", " << cur.second << " ) ";
#endif // DEBUG
			path.push_back(cur);
			map[cur.first][cur.second] = '*';
			cur = parent[cur.first][cur.second];
		}
		std::cout << std::endl;
		if (path.size() <= 1) {
			std::cout << "�Ը����������յ�����Ӧ·����" << std::endl;
			return;
		}
		std::cout << "��ͼ���£�·������'*'�����" << std::endl;
		for (auto x : map)std::cout << x << std::endl;
		//
		std::cout << "·�����£�" << std::endl;
		
		//else
		for (auto it = path.rbegin();it != path.rend();++it) {
			std::cout << (it == path.rbegin() ? "" : " -> ");
			std::cout << "( " << it->first << ", " << it->second << " )";
		}
	}
	void set_maze(std::istream& in) {
		std::string row;
		while (in >> row)
		{
			//in >> row;
#ifdef DEBUG
			std::cout << row << std::endl;
#endif
			map.push_back(row);
		}

		//���ҵ������յ�
		//std::stack<Point> candidates;
		for (int r = 0;r<map.size();++r)
			for (int c = 0;c < map[0].size();++c) {
				if (map[r][c] == 'S')start = Point(r, c);
				else if (map[r][c] == 'E')end = Point(r, c);
			}
		parent.assign(map.size(), std::vector<Point>(map[0].size(), Point(-1, -1)));
	}
	
	//
};