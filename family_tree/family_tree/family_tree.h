/*
2018/12/7 By hangshuaibi
*/

#pragma once

#include "member.h"

class family {
private:
	member ancestor;
	member& search_member_by_name(const std::string& name);

public:
	family(const std::string& name):ancestor(name){}

	bool erase_part(const std::string& name);
	void add_a_descendant(const std::string& old_name, const std::string& new_name);
	void add_a_descendant(const std::string& old_name, std::string&& new_name);
	void build_family(const std::string& old_name, std::vector<std::string> dsd_names);
	void show_part(const std::string& name);
	void show_all();
	void modify_name(const std::string& old_name, const std::string& new_name);
};