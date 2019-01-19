#pragma once

#include <string>
#include <stack>
#include <cstring>
#include <cassert>
#include <iostream>

class parser {

	enum OP {
		RIGHT = 1,

		ADD,
		SUB,

		MUL,
		DIV,

		LEFT,
	};
	const char OP2char[10] = {
		' ', ')', '+', '-', '*', '/','(',
	};

	//���ʽ����С��Ԫ�����ֻ��߲�����
	struct object {
		typedef union {
			double num;
			OP op;
		} VAL;

		bool isnumber;
		VAL val;

		//Ĭ��Ϊ����
		//object(int _val, bool _isnumber = true) :val(_val), isnumber(_isnumber) {}
	};

	std::stack<object>			ops;//�洢operator��ջ
	std::string						exp;//��ȡ��һ����׺���ʽ
	object							obj;	//parse֮���õ�obj
	int									ptr;	//ָ��
	bool								last_is_lb;	//��һ���Ƿ��������Ż�����ʼλ
	bool								number_prefix;	//��ǰ��parsing�������Ƿ���������
														/*
														��������bool������Ϊ�˽���������λ������
														*/
public:
	//ctor
	parser(std::string _exp) :exp(_exp) {}

	void translation()
	{
		using std::cout;

		ptr = 0;
		last_is_lb = true;

		//std::deque<object> output;

		while (ptr != exp.size()) {
			parse_one_object();

			if (obj.isnumber) {
				if (number_prefix) {
					//obj.val = -obj.val;
					assert(!ops.empty());

					if (ops.top().val.op == SUB) {
						obj.val.num = -obj.val.num;
					}
					ops.pop();
					number_prefix = false;
				}

				cout << obj.val.num << ' ';
			}
			else {
				//�������
				OP op = obj.val.op;
				switch (op) {
				case LEFT: {
					ops.push(obj);

					break;
				}
				case RIGHT: {
					if (ops.top().val.op != LEFT) {
						cout << OP2char[ops.top().val.op];
						space_or_end();

						ops.pop();
					}
					assert(!ops.empty() && ops.top().val.op == LEFT);

					ops.pop();//LEFT

					break;
				}
				default: {
					//+-*/
					//
					//auto top_op = ops.top().val.op;
					while (!ops.empty()) {
						auto last_op = ops.top().val.op;
						if (last_op / 2 >= op / 2 && last_op != LEFT) {
							cout << OP2char[last_op];
							space_or_end();

							ops.pop();
						}
						else break;
					}
					//ѹ���²�����
					ops.push(obj);
				}
				}
			}
		}

		if (!ops.empty()) {
			cout << OP2char[ops.top().val.op];
			ops.pop();
		}
		while (!ops.empty()) {
			cout << " " << OP2char[ops.top().val.op];

			ops.pop();
		}
	}

	void set_exp(const std::string& _exp)
	{
		exp = _exp;
	}

private:
	void space_or_end()
	{
		std::cout << (ptr == exp.size() ? "" : " ");
	}

	void parse_one_object()
	{
		while (exp[ptr] == ' ')++ptr;

		switch (exp[ptr]) {

		case '+':
		case '-': {
			parse_add_and_mul();
			number_prefix = last_is_lb;
			//last_is_lb = false;

			break;
		}
		case '*':
		case '/': {
			parse_mul_and_div();

			break;
		}
		case '(': {
			parse_lb();
			last_is_lb = true;

			break;
		}
		case ')': {
			parse_rb();

			break;
		}
		default: {
			parse_number();

			break;
		}
		}
		//�����ǰ��obj���������ţ��ѱ�־λ��Ϊfalse
		if (obj.isnumber || obj.val.op != OP::LEFT) {
			last_is_lb = false;
		}
	}

	void parse_number()
	{
		//std::cout<<exp[ptr];
		assert(isdigit(exp[ptr]));//ȷ����λΪ����

		double int_part = 0.0;
		while (isdigit(exp[ptr])) {
			int_part = (exp[ptr] - '0') + int_part * 10.0;
			++ptr;
		}
		//����еĻ�������С������
		if (exp[ptr] == '.') {
			double weight = 0.1;
			++ptr;//����С����

			while (isdigit(exp[ptr])) {
				int_part += weight * (exp[ptr] - '0');
				weight = weight * 0.1;

				++ptr;
			}
		}

		obj.isnumber = true;
		obj.val.num = int_part;
	}
	void parse_rb()
	{
		obj.isnumber = false;
		obj.val.op = RIGHT;

		++ptr;
	}
	void parse_lb()
	{
		obj.isnumber = false;
		obj.val.op = LEFT;

		++ptr;
	}
	void parse_add_and_mul()
	{
		obj.isnumber = false;
		obj.val.op = (exp[ptr] == '+') ? ADD : SUB;

		++ptr;
	}
	void parse_mul_and_div()
	{
		obj.isnumber = false;
		obj.val.op = (exp[ptr] == '*') ? MUL : DIV;

		++ptr;
	}
};