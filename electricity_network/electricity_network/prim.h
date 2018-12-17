#pragma once

#include <vector>
#include <map>


class solver {
private:
	//边的定义
	struct edge {
		edge(int _u,int _v,int _cost):u(_u),v(_v),cost(_cost){}
		int u, v;
		int cost;
	};
	
	std::vector<edge>						tree;					//最小生成树的边
	std::vector<int>							dist_to_tree;		//各节点到根节点的距离
	std::vector<int>							visited;				//节点是否已经被访问过
	std::vector<int>							parent;				//父节点，即从root到达对应节点所经过的上一个节点

	std::vector<std::vector<int> >		dist;					//两两节点之间的距离
	std::map<std::string, int>				key_to_num;		//把名字转换成节点对应的编号
	std::vector<std::string>					num_to_key;		//把编号转换成节点的名字
	int													root;					//根节点对应的编号
	int													n;						//节点数量


public:
	void create_vertices(std::istream& in);						//创建电网节点
	void add_edges(std::istream& in);							//添加电网的边
	void gen_prim_tree(std::istream& in);											//构建最小生成树
	void print_prim_tree();											//打印最小生成树
};