#include "maze.h"
#include <fstream>

using std::ifstream;
using std::cout;
using std::endl;
using std::cin;

//#define NO_PATH_MAP

int main()
{
	cout << "�����������õ�ͼ�����Լ�������~(������)~*" << endl;
	cout << "��ʹ�����õ�ͼ�Ļ�? [y/n]" << endl;

	ifstream fin;
	maze xi;

	char c;
	cin >> c;
	while (c == '\n')cin >> c;
	if (c == 'y' || c == 'Y') {
#ifdef NO_PATH_MAP
		fin.open("no_path.txt");
#else
		fin.open("data.txt");
#endif
		assert(fin);
		xi.set_maze(fin);
	}
	else {
		cout << "��ѡ�����Լ������ͼ�����ܻ��е���..." << endl;
		cout << "�밴�������ĸ�ʽ�������룺" << "\n####\n#S0#\n#0E\n" << "����#��ʾ�ϰ���S��ʾ��㣬E��ʾ�յ㣬0��ʾ���߸��" << endl;
		xi.set_maze(cin);
	}
	
	xi.get_solution();

	fin.close();

	system("pause");
	return 0;
}