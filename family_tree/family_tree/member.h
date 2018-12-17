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
		std::cout << "��Һã�����move�汾��ctr" << std::endl;
		std::cout << "move����������������" << _name << std::endl;
#endif // DEBUG
	}
	member(const std::string& _name = "") :name(_name) {
#ifdef DEBUG
		std::cout << "��Һã�����copy�汾��ctr" << std::endl;
		std::cout << "copy����������������" << _name << std::endl;
#endif // DEBUG
	}

private:
	//��ֹ����
	member(const member& left) = delete;


	std::string name;
	std::list<member> descendants;							//�������


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
		std::cout << "����" << name << "���ұ������ˣ�" << std::endl;
#endif // BPL


#ifndef BPL
		std::cout << "��Һã��ҽ�" << name << "�������ˣ�������֪��Ϊʲô������Ϊ�ҵİְֻ�үү��...��ɢ�˼�ͥ��";
		std::cout << "   ������Ҳ����ν����Ϊ�ҵ����������������һ���뿪" << std::endl;
#endif // DEBUG
	}
#endif // LOG


};