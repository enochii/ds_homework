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
			std::cout << "����ڵ�ʱ�ڴ����" << std::endl;
		}
		return new_node;
	}
	//
	node(int _weight, link_type _left = nullptr, link_type _right = nullptr):weight(_weight),left(_left),right(_right){}
	~node() {
#ifdef DEBUG
		std::cout << "�ұ������ˣ�" << std::endl;
#endif // DEBUG

		if (left != nullptr)delete left;
		if (right != nullptr)delete right;
	}

	/*bool isLeaf()
	{
		//������Ϊ�� ---> ������Ϊ��
		return left == nullptr;
	}*/

	int get_weight() { return weight; }

	struct cmp {
		bool operator()(const link_type l, const link_type r) {
			return l->weight > r->weight;
		}
	};
private:
	link_type		left;//����
	link_type		right;//�Һ���
	int					weight;//Ȩֵ
};