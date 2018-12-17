#include "maze.h"
#include <fstream>

using std::ifstream;
using std::cout;
using std::endl;
using std::cin;

//#define NO_PATH_MAP

int main()
{
	cout << "你是想用内置地图还是自己输入捏~(￣▽￣)~*" << endl;
	cout << "想使用内置地图的话? [y/n]" << endl;

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
		cout << "你选择了自己输入地图，可能会有点累..." << endl;
		cout << "请按照这样的格式进行输入：" << "\n####\n#S0#\n#0E\n" << "其中#表示障碍，S表示起点，E表示终点，0表示可走格点" << endl;
		xi.set_maze(cin);
	}
	
	xi.get_solution();

	fin.close();

	system("pause");
	return 0;
}