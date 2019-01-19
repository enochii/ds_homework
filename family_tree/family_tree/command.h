/*
2018/12/7 By hangshuaibi
*/

#pragma once

#include "family_tree.h"

void command_A(family& ft)
{
	std::cout << "������Ҫ������ͥ���ˣ�";
	std::string name;
	std::cin >> name;

	if (ft.search_member_by_name(name) == nullptr) {
		std::cout << "�Ҳ����ó�Ա " << name << "����ȷ�Ϻ��������룡";
		return;
	}

	std::cout << "������" << name << "�Ķ�Ů������";
	int n = (1 >> 30);
	std::cin >> n;
	while (n <= 0) {
		if (!std::cin.good()) {
			std::cin.clear();
			std::cin.ignore();

			std::cout << "������������ѽ��" << std::endl;
			std::cin >> n;
			continue;
		}
		std::cout << "�����ô���0Ŷ����Ȼ�齨ʲô��ͥ��\n";
		std::cin >> n;
	}
	std::vector<std::string> new_names;
	std::cout << "����������" << name << "�Ķ�Ů��������";
	for (int i = 0;i < n;++i) {
		std::string temp;
		std::cin >> temp;
		new_names.push_back(std::move(temp));
	}

	ft.build_family(name, new_names);

	//std::cout << name << "�ĵ�һ�������ǣ�";
	ft.show_part(name);
}

void command_B(family& ft)
{
	std::cout << "������Ҫ��Ӷ��ӣ���Ů�������˵�������";
	std::string old_name, new_name;
	std::cin >> old_name;
	std::cout << "������" << old_name << "����ӵĶ��ӣ���Ů������������";
	std::cin >> new_name;

	if (ft.search_member_by_name(old_name) == nullptr) {
		std::cout << "�Ҳ����ó�Ա " << old_name << "����ȷ�Ϻ��������룡";
		return;
	}

	ft.add_a_descendant(old_name, new_name);
	
	ft.show_part(old_name);
}

void command_C(family& ft)
{
	//std::cout << "��ʵ���ڵ�member��erase_part" << std::endl;
	
	std::cout << "�������ɢ��ͥ���˵����֣�";
	std::string name;
	std::cin >> name;

	std::cout << "Ҫ��ɢ��ͥ�����ǣ�" << name << std::endl;
	if (ft.search_member_by_name(name) == nullptr) {
		std::cout << "�Ҳ����ó�Ա " << name << "����ȷ�Ϻ��������룡";
		return;
	}
	ft.show_part(name);

	ft.erase_part(name);
}

void command_D(family& ft)
{
	std::string old_name, new_name;
	std::cout << "������Ҫ���ĵ��˵�Ŀǰ������";
	std::cin >> old_name;
	std::cout << "��������ĺ��������";
	std::cin >> new_name;

	if (ft.search_member_by_name(old_name) == nullptr) {
		std::cout << "�Ҳ����ó�Ա " << old_name << "����ȷ�Ϻ��������룡";
		return;
	}

	ft.modify_name(old_name, new_name);
	std::cout << old_name << "�Ѹ���Ϊ" << new_name << std::endl;
}