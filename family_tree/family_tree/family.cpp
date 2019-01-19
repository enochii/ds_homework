/*
2018/12/7 By hangshuaibi
*/

#include "family_tree.h"

member* family::search_member_by_name(const std::string& name)
{
	return ancestor.search_by_name(name);
}


bool family::erase_part(const std::string& name)
{
	if (name == ancestor.name) {
#ifdef LOG
		std::cout << "ÂúÃÅ³­Õ¶µÄÂð......" << std::endl;
#endif//LOG
		ancestor.name = "";
		ancestor.descendants.clear();
		
		return true;
	}
	else 
		return ancestor.erase_part(name);
}
void family::add_a_descendant(const std::string& old_name,  const std::string& new_name)
{
	member* old = search_member_by_name(old_name);
	old->add_a_descendant(new_name);
}
void family::add_a_descendant(const std::string& old_name, std::string&& new_name)
{
	member* old = search_member_by_name(old_name);
	old->add_a_descendant(std::move(new_name));
}

void family::build_family(const std::string& name, std::vector<std::string> dsd_names)
{
	search_member_by_name(name)->build_family(dsd_names);
}

void family::show_part(const std::string& name)
{
	search_member_by_name(name)->show_descendants(false);
	std::cout << std::endl;
}

void family::show_all()
{
	search_member_by_name(ancestor.name)->show_descendants(true);
	std::cout << std::endl;
}

void family::modify_name(const std::string& old_name, const std::string& new_name)
{
	search_member_by_name(old_name)->set_name(new_name);
}