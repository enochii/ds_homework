#include <iostream>
#include "key_task.h"

using std::cout;
using std::cin;

int main()
{
	//int n, m;
	cout << "�������������񽻽ӵ�������������������������Կո�ָ\n";
	
	solver solution;
	solution.accept_input(cin);
	cout << "\n�������н��Ϊ��\n";
	solution.run();

	system("pause");
	return 0;
}