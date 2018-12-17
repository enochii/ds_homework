#include "Node.h"

std::ostream& operator<< (std::ostream& os, const Node& _)
{
	static std::string seperator = "		";
	os << _._number << seperator << _._name << seperator
		<< (_._sex ? "ÄÐ" : "Å®") <<seperator << _._age <<seperator
		<< _._test_type;
	return os;
}
std::istream& operator >> (std::istream& is, Node& _)
{
	static std::string sex;
	is >> _._number >> _._name >> sex >> _._age >> _._test_type;
	_._sex = sex == "ÄÐ" ? true : false;
	return is;
}