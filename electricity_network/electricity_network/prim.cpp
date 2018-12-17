#include "prim.h"
#include <iostream>
#include <string>
#include <cassert>

void solver::gen_prim_tree(std::istream& in)
{
	std::cout << "��������ʼ����" << std::endl;

	std::string vertex_name;
	in >> vertex_name;
	root = key_to_num[vertex_name];

	//���������״̬���ص����
	tree.clear();
	dist_to_tree.assign(n, -1);
	visited.assign(n, 0);
	parent.assign(n, root);

	//parent[root] = root;
	visited[root] = 1;

	/**/
	for (int i = 0;i < dist_to_tree.size();++i) {
		dist_to_tree[i] = dist[i][root];
	}
	dist_to_tree[root] = 0;

	int times = dist_to_tree.size() - 1;//ѭ��ִ�� n - 1��
	while (times-- > 0) {
		int nearest_ver = -1, shortest_len = (1 << 30);
		//�ҳ���ǰ��root�����δ���ʵĽڵ�
		for (int i = 0;i < dist_to_tree.size();++i) {
			if (dist_to_tree[i] != -1 && shortest_len > dist_to_tree[i]
				&& visited[i] == 0) {
				nearest_ver = i;
				shortest_len = dist_to_tree[i];
			}
		}
		
		assert(nearest_ver != -1);
		//���ڵ�����ѷ��ʼ���
		visited[nearest_ver] = 1;
		//�ѱ߼�����С������
		tree.emplace_back(parent[nearest_ver], 
										nearest_ver, 
										dist[parent[nearest_ver]][nearest_ver]);

		for (int i = 0;i < dist_to_tree.size();++i) {
			if (visited[i] == 0 &&																			//�ڵ�δ�����ʹ�
				dist[i][nearest_ver] != -1 &&															//���ڵ�ľ��벻Ϊ�����
				dist_to_tree[i] > dist[i][nearest_ver]												//����������������...
				) {
				dist_to_tree[i] = dist[i][nearest_ver];
				parent[i] = nearest_ver;
			}
		}
	}

	std::cout << "����Prim��С��������" << std::endl;
}

void solver::print_prim_tree()
{
	for (auto& x : tree) {
		std::cout << num_to_key[x.u] << "-( " << x.cost << " )->" << num_to_key[x.v] << " ";
	}
	std::cout << std::endl;
}

void solver::create_vertices(std::istream& in)
{
	std::cout << "�����붥��ĸ�����";
	in >> n;
	
	dist.assign(n, std::vector<int>(n, -1));
	//num_to_key.assign(n, "");

	std::cout << "������������ڵ�����ƣ�" << std::endl;

	std::string name;
	int num = 0;
	key_to_num.clear();
	while (num<n) {
		in >> name;
		key_to_num.emplace(name, num);
		num_to_key.push_back(name);
		++num;	//������
#ifdef DEBUG
		std::cout << key_to_num[name];
#endif // DEBUG
	}
}

void solver::add_edges(std::istream& in)
{
	std::string u, v;
	int cost;
	
	while (true) {
		std::cout << "�������������㼰�ߣ�" << std::endl;
		in >> u >> v >> cost;
		if (u[0] == '?')break;
		
		if (dist[key_to_num[u]][key_to_num[v]] != -1) {
			std::cout << "�Ѿ����ڴ˱ߣ��Ƿ���Ҫ���ǣ�[y/n]";
			char response;
			std::cin >> response;
			while (response == '\n')std::cin >> response;
			if (response != 'Y' || response != 'y')continue;
		}

		dist[key_to_num[u]][key_to_num[v]] = cost;
		dist[key_to_num[v]][key_to_num[u]] = cost;
	}
	
}