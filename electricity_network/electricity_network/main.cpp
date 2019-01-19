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

	cout << "**                    ����ģ��ϵͳ                    **" << endl;
	cout << std::string(57, '=') << endl;
	cout << "**                  A --- ���������ڵ�                **" << endl;
	cout << "**                  B --- ��ӵ����ı�                **" << endl;
	cout << "**                  C --- ������С������	      **" << endl;
	cout << "**                  D --- ��ʾ��С������              **" << endl;
	cout << "**                  E --- �˳�����                    **" << endl;
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
		cout << "��ѡ�������" << endl;
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