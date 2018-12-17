#pragma once

#include <vector>
#include <map>


class solver {
private:
	//�ߵĶ���
	struct edge {
		edge(int _u,int _v,int _cost):u(_u),v(_v),cost(_cost){}
		int u, v;
		int cost;
	};
	
	std::vector<edge>						tree;					//��С�������ı�
	std::vector<int>							dist_to_tree;		//���ڵ㵽���ڵ�ľ���
	std::vector<int>							visited;				//�ڵ��Ƿ��Ѿ������ʹ�
	std::vector<int>							parent;				//���ڵ㣬����root�����Ӧ�ڵ�����������һ���ڵ�

	std::vector<std::vector<int> >		dist;					//�����ڵ�֮��ľ���
	std::map<std::string, int>				key_to_num;		//������ת���ɽڵ��Ӧ�ı��
	std::vector<std::string>					num_to_key;		//�ѱ��ת���ɽڵ������
	int													root;					//���ڵ��Ӧ�ı��
	int													n;						//�ڵ�����


public:
	void create_vertices(std::istream& in);						//���������ڵ�
	void add_edges(std::istream& in);							//��ӵ����ı�
	void gen_prim_tree(std::istream& in);											//������С������
	void print_prim_tree();											//��ӡ��С������
};