#include "prim.h"
#include <iostream>
#include <fstream>
#include <cassert>
#include <string>

using std::cin;
using std::cout;
using std::endl;

//#define FILE_INPUT

int main(void)
{
	//cout << sizeof(std::vector<bool>(1, 0)[0]) << endl;

	cout << "**                    电网模拟系统                    **" << endl;
	cout << std::string(57, '=') << endl;
	cout << "**                  A --- 创建电网节点                **" << endl;
	cout << "**                  B --- 添加电网的边                **" << endl;
	cout << "**                  C --- 构造最小生成树	      **" << endl;
	cout << "**                  D --- 显示最小生成树              **" << endl;
	cout << "**                  E --- 退出程序                    **" << endl;
	cout << std::string(57, '=') << endl << endl;

#ifdef FILE_INPUT
	auto file = std::ifstream("data.txt");
	assert(file);
#else
	auto& file = cin;
#endif // FILE_INPUT


	/**/
	solver en;
	std::string command("init_command");
	while (command[0] != 'E') {
		cout << "请选择操作：" << endl;
		file >> command;
		switch (command[0]) {
		case 'A':
			en.create_vertices(file);
			break;
		case 'B':
			en.add_edges(file);
			break;
		case 'C':
			en.gen_prim_tree(file);
			break;
		case 'D':
			en.print_prim_tree();
			break;
			
		case 'E':
			/*empty*/
		default:
			break;
		}
	}
	system("pause");
	return 0;
}