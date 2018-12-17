#pragma once

#include "hfm_node.h"
#include <queue>
//#include <vector>

//std::priority_queue<node*, std::vector<node*>, node::cmp> pq;

class hfm_tree {
	typedef node::link_type link_type;
	std::priority_queue<link_type
								,std::vector<link_type>
								,node::cmp
																	> pq; //�洢�ڵ�����ȶ���
	int																n;//Ҷ�ڵ�������
	link_type													root;
	int																sum;//�ܳ��


	void build_tree();

public:
	int get_sum();
	void clear_current_hfm();

	template <class It>
	void set_leaves(It first, It last)
	{
		for (auto it = first;it != last;++it) {
			pq.push(new node(*it));
			++n;
		}
	}

	
	//
	template<class It>
	hfm_tree(It first,It last):hfm_tree(){
#ifdef DEBUG
		if(root == nullptr)cout << n << " " << sum << std::endl;
#endif // DEBUG

		set_leaves(first, last);
	}
	hfm_tree():root(nullptr), n(0), sum(0){}
	~hfm_tree() {
		clear_current_hfm();
	}
};