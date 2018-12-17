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
		"**\t\t ���׹���ϵͳ       \t\t**\n"
		<< seperator <<
		"**\t\tA�������Ƽ���      \t\t**\n"
		"**\t\tB������Ӽ�ͥ��Ա\t\t**\n"
		"**\t\tC������ɢ�ֲ���ͥ\t\t**\n"
		"**\t\tD�������ļ�ͥ��Ա����\t\t**\n"
		"**\t\tE�����˳�����\t\t\t**\n"
		<< seperator <<
		"�����뽨�����ף�\n���������ȵ�������";

	std::string ancestor;
	std::cin >> ancestor;
	std::cout << "�˼��׵������ǣ�" << ancestor << std::endl;
	
	family ft(ancestor);

	std::string command("init");
	while (command[0] != 'E') {
		std::cout << "��ѡ��Ҫִ�еĲ�����";
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
			std::cout << "�´��㻹������" << std::endl;
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

	std::cout << "ԭ�����ַ�����" << _ << std::endl;
	std::cout << "�¹�����ַ�����" << __ << std::endl;
#endif

	system("pause");
	return 0;
}