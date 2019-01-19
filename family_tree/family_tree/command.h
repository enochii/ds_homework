/*
2018/12/7 By hangshuaibi
*/

#pragma once

#include "family_tree.h"

void command_A(family& ft)
{
	std::cout << "请输入要建立家庭的人：";
	std::string name;
	std::cin >> name;

	if (ft.search_member_by_name(name) == nullptr) {
		std::cout << "找不到该成员 " << name << "，请确认后重新输入！";
		return;
	}

	std::cout << "请输入" << name << "的儿女人数：";
	int n = (1 >> 30);
	std::cin >> n;
	while (n <= 0) {
		if (!std::cin.good()) {
			std::cin.clear();
			std::cin.ignore();

			std::cout << "你得输入个数字呀！" << std::endl;
			std::cin >> n;
			continue;
		}
		std::cout << "人数得大于0哦，不然组建什么家庭！\n";
		std::cin >> n;
	}
	std::vector<std::string> new_names;
	std::cout << "请依次输入" << name << "的儿女的姓名：";
	for (int i = 0;i < n;++i) {
		std::string temp;
		std::cin >> temp;
		new_names.push_back(std::move(temp));
	}

	ft.build_family(name, new_names);

	//std::cout << name << "的第一代子孙是：";
	ft.show_part(name);
}

void command_B(family& ft)
{
	std::cout << "请输入要添加儿子（或女儿）的人的姓名：";
	std::string old_name, new_name;
	std::cin >> old_name;
	std::cout << "请输入" << old_name << "新添加的儿子（或女儿）的姓名：";
	std::cin >> new_name;

	if (ft.search_member_by_name(old_name) == nullptr) {
		std::cout << "找不到该成员 " << old_name << "，请确认后重新输入！";
		return;
	}

	ft.add_a_descendant(old_name, new_name);
	
	ft.show_part(old_name);
}

void command_C(family& ft)
{
	//std::cout << "其实我在等member的erase_part" << std::endl;
	
	std::cout << "请输入解散家庭的人的名字：";
	std::string name;
	std::cin >> name;

	std::cout << "要解散家庭的人是：" << name << std::endl;
	if (ft.search_member_by_name(name) == nullptr) {
		std::cout << "找不到该成员 " << name << "，请确认后重新输入！";
		return;
	}
	ft.show_part(name);

	ft.erase_part(name);
}

void command_D(family& ft)
{
	std::string old_name, new_name;
	std::cout << "请输入要更改的人的目前姓名：";
	std::cin >> old_name;
	std::cout << "请输入更改后的姓名：";
	std::cin >> new_name;

	if (ft.search_member_by_name(old_name) == nullptr) {
		std::cout << "找不到该成员 " << old_name << "，请确认后重新输入！";
		return;
	}

	ft.modify_name(old_name, new_name);
	std::cout << old_name << "已改名为" << new_name << std::endl;
}