#pragma once

#include <string>
#include <iostream>

//�Ա����bool����
typedef bool __student_sex;
//const bool __student_male = true;
//const bool __student_female = false;

//Node�ڵ��࣬һ���ڵ�洢��Ӧѧ����Ϣ��ָ����һ��ѧ����ָ��
struct student_node {
	typedef student_node* student_ptr;
	typedef __student_sex sex_type;

	int					_number;
	std::string		_name;
	sex_type		_sex;//
	int					_age;
	std::string		_test_type;

	student_ptr _next;
	//���캯��
	student_node(int number = -1, std::string name = "",sex_type sex = true,
							int age = -1, std::string test_type = ""):
		_number(number),_name(name),_sex(sex),_age(age),_test_type(test_type),
		_next(nullptr){}
};

typedef student_node Node;

// ����Node��������������
std::ostream& operator<< (std::ostream&, const Node&);
std::istream& operator >> (std::istream&, Node&);

#undef student_node