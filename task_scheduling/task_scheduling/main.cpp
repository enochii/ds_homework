#include <iostream>
#include "key_task.h"

using std::cout;
using std::cin;

int main()
{
	//int n, m;
	cout << "请依次输入任务交接点总数量和子任务的数量，并以空格分割：\n";
	
	solver solution;
	solution.accept_input(cin);
	cout << "\n程序运行结果为：\n";
	solution.run();

	system("pause");
	return 0;
}