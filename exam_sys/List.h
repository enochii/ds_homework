#pragma once

#include "Node.h"

typedef Node* stu_ptr;

//�����࣬����ϵͳ���ڲ����ݽṹ
class List {
private:
	stu_ptr _head;//��ͷ�ڵ�
	//int _num;//�����ڵĽڵ�����

private:
	//���ң��޸��õ��Ľӿڣ����ٴ�������
	stu_ptr do_find(int num)
	{
		auto temp = _head->_next;
		while (temp != nullptr&&temp->_number!= num)
		{
			temp = temp->_next;
		}
		
			return temp;
	}
	
	void destroy_all(stu_ptr stu)
	{
		if (stu->_next != nullptr)
		{
			destroy_all(stu->_next);
		}
		delete stu;
	}

public:
	//���캯��
	List() :_head(nullptr) {
		_head = new Node();
		if (_head == nullptr) {
			std::cerr << "Failed in new operation!";
		}
	}
	~List() {
		destroy_all(_head);
	}
	void insert(Node* x, int position)
	{
		Node* temp = _head;
		for (int i = 1;i < position && temp != nullptr; ++i)
		{
			temp = temp->_next;
		}
		if (temp == nullptr)
		{
			std::cout << "illegal position! please give another position -- " << position << std::endl;
			//let user input a position

			//
			return;
		}
		x->_next = temp->_next;
		temp->_next = x;
	}

	void destroy(int num)
	{
		auto pre = _head;
		auto temp = _head->_next;
		while (temp != nullptr)
		{
			if (temp->_number == num)
			{
				pre->_next = temp->_next;
				std::cout << "��ɾ���Ŀ�����Ϣ�ǣ�" << *temp << std::endl;
				delete temp;
				return;
			}
			else {
				pre = temp;
				temp = temp->_next;
			}
		}
		std::cout << "���޴��ˣ�" << std::endl;
	}

	void display_table_head()
	{
		std::cout<<"����		����		�Ա�			����			�������"<<std::endl;
	}

	void find(int num)
	{
		auto stu = do_find(num);

		if (stu)
		{
			display_table_head();
			std::cout << *stu << std::endl;
		}
		else {
			std::cout << "���޴���!" << std::endl;
		}
	}

	void modify(int num)
	{
		auto stu = do_find(num);

		if (stu)
		{
			std::cout << "����������Ҫ�޸ĵĿ��ţ��������Ա��Ա����估�������"
				<< std::endl;
			std::cin >> *stu;
		}
		else {
			std::cout << "���޴���!" << std::endl;
		}
	}

	void show_all()
	{
		display_table_head();
		for (auto temp = _head->_next;temp != nullptr;temp = temp->_next)
		{
			std::cout << *temp << std::endl;
		}
	}
};