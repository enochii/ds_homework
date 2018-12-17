/*
2018/12/7 By hangshuaibi
*/

#pragma once

#include <string>
#include <list>
#include <vector>
#include <iostream>

//
//#define DEBUG
//#define LOG
#define BPL

class member {
	friend class family;
	//friend class std::list<member>;

public:
	member(std::string&& _name = "") :name(std::move(_name)) {
#ifdef DEBUG
		std::cout << "大家好，我是move版本的ctr" << std::endl;
		std::cout << "move后参数变成了这样：" << _name << std::endl;
#endif // DEBUG
	}
	member(const std::string& _name = "") :name(_name) {
#ifdef DEBUG
		std::cout << "大家好，我是copy版本的ctr" << std::endl;
		std::cout << "copy后参数变成了这样：" << _name << std::endl;
#endif // DEBUG
	}

private:
	//禁止复制
	member(const member& left) = delete;


	std::string name;
	std::list<member> descendants;							//后代数组


	void set_name(const std::string& self_name);
	void add_a_descendant(const std::string& dsd_name);
	void add_a_descendant(std::string&& dsd_name);
	void build_family(std::vector<std::string> dsd_names);
	void show_descendants(bool recur)const;
	member * const search_by_name(const std::string& name);
	bool erase_part(const std::string& name);

#ifdef LOG
public:
	~member() {
#ifdef BPL
		std::cout << "我是" << name << "，我被析构了！" << std::endl;
#endif // BPL


#ifndef BPL
		std::cout << "大家好，我叫" << name << "，我死了，甚至不知道为什么，就因为我的爸爸或爷爷或...解散了家庭吗";
		std::cout << "   不过那也无所谓，因为我的子子孙孙会陪着我一起离开" << std::endl;
#endif // DEBUG
	}
#endif // LOG


};