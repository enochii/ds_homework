/*
2018/12/7 By hangshuaibi
*/

#include "family_tree.h"
#include "command.h"

//#define MOVE_TEST

int main()
{
	std::string seperator(50, '-');
	seperator.push_back('\n');
	std::cout << seperator <<
		"**\t\t 家谱管理系统       \t\t**\n"
		<< seperator <<
		"**\t\tA——完善家谱      \t\t**\n"
		"**\t\tB——添加家庭成员\t\t**\n"
		"**\t\tC——解散局部家庭\t\t**\n"
		"**\t\tD——更改家庭成员姓名\t\t**\n"
		"**\t\tE——退出程序\t\t\t**\n"
		<< seperator <<
		"首先请建立家谱！\n请输入祖先的姓名：";

	std::string ancestor;
	std::cin >> ancestor;
	std::cout << "此家谱的祖先是：" << ancestor << std::endl;
	
	family ft(ancestor);

	std::string command("init");
	while (command[0] != 'E') {
		std::cout << "请选择要执行的操作：";
		std::cin >> command;
		switch (command[0]){
		case 'A': {
			command_A(ft);
			break;
		}
		case 'B': {
			command_B(ft);
			break;
		}
		case 'C': {
			command_C(ft);
			break;
		}
		case 'D': {
			command_D(ft);
			break;
		}
#ifdef DEBUG
		case 'S': {
			ft.show_all();
			break;
		}
#endif
		case 'E':
			std::cout << "下次你还会来吗" << std::endl;
			//no_break
		default:
			break;
		}

		//ft.show_all();
		std::cout << std::endl;
	}

#ifdef MOVE_TEST
	std::string _("??");
	std::string __(std::move(_));

	std::cout << "原来的字符串：" << _ << std::endl;
	std::cout << "新构造的字符串：" << __ << std::endl;
#endif

	system("pause");
	return 0;
}