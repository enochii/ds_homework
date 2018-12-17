#include "hfm.h"
#include <cassert>

void hfm_tree::build_tree()
{
	assert(n == pq.size());

	while (pq.size() > 1) {
		auto left = pq.top();
		pq.pop();
		auto right = pq.top();
		pq.pop();

		sum += left->get_weight() + right->get_weight();//在构建哈夫曼树的同时累积权值

#ifdef DEBUG
		std::cout << "left -> " << left->get_weight() << "   right -> " << right->get_weight() << std::endl;
		std::cout << "left address -> " << left << "   right address -> " << right << std::endl;
#endif // DEBUG


		pq.push(node::make_node(left, right));
	}

	root = pq.top();
}

int hfm_tree::get_sum()
{
	build_tree();

	return sum;
}

void hfm_tree::clear_current_hfm()
{
	if (root == nullptr)return;
	else delete root;
}

/*

*/