#pragma once
#include <iostream>

//#define DEBUG

struct node {
	typedef node* link_type;
	//bool operator<(const node& rt) { return this->weight > rt.weight; }
	static node* make_node(link_type left, link_type right)
	{
		auto new_node = new node(left->weight + right->weight, left, right);
		if (new_node == nullptr)
		{
			std::cout << "申请节点时内存出错！" << std::endl;
		}
		return new_node;
	}
	//
	node(int _weight, link_type _left = nullptr, link_type _right = nullptr):weight(_weight),left(_left),right(_right){}
	~node() {
#ifdef DEBUG
		std::cout << "我被析构了！" << std::endl;
#endif // DEBUG

		if (left != nullptr)delete left;
		if (right != nullptr)delete right;
	}

	/*bool isLeaf()
	{
		//左子树为空 ---> 右子树为空
		return left == nullptr;
	}*/

	int get_weight() { return weight; }

	struct cmp {
		bool operator()(const link_type l, const link_type r) {
			return l->weight > r->weight;
		}
	};
private:
	link_type		left;//左孩子
	link_type		right;//右孩子
	int					weight;//权值
};