/*
2018/12/7 By hangshuaibi
*/

#include "member.h"
#include <cassert>

using std::vector;

void member::set_name(const std::string& self_name)
{
	name = self_name;
}

void member::add_a_descendant(const std::string& dsd_name)
{
	descendants.emplace_back(dsd_name);
#ifdef DEBUG
	std::cout << "copy后参数变成了：" << dsd_name;
#endif // DEBUG
}

void member::add_a_descendant(std::string&& dsd_name) 
{
	descendants.emplace_back(dsd_name);
#ifdef DEBUG
	std::cout << "move后参数变成了：" << dsd_name;
#endif // DEBUG

}
void member::build_family(std::vector<std::string> dsd_names)
{
	for (auto &x : dsd_names) {
		descendants.emplace_back(std::move(x));
	}
}

void member::show_descendants(bool recur)const
{
	std::cout << name << "的第一代子孙是：";
	for (const auto& dsd : descendants) {
		std::cout << dsd.name << " ";
		//递归打印
		if (recur) {
			std::cout << "（";dsd.show_descendants(recur);std::cout << "）";
		}
	}
	//std::cout << std::endl;
}

member *const member::search_by_name(const std::string& name)
{
	if (this->name == name) {
		return this;
	}
	for (auto& dsd : descendants) {
		auto res = dsd.search_by_name(name);
		if (res != nullptr)return res;
	}

	return nullptr;
}

bool member::erase_part(const std::string & name)
{
	assert(name != this->name);
	for (auto it = descendants.begin();it != descendants.end();++it) {
		if (it->name == name) {
			descendants.erase(it);
			return true;
		}
		else {
			if (it->erase_part(name))return true;
		}
	}

	return false;
}