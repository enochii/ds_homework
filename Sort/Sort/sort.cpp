/*
2018/12/9 by ʩ�̺�
*/

#include "sort.h"
#include <algorithm>
#include "test.h"

//local variable
static int __swap_times__ = 0;

//�Զ����swap
void swap(int &a, int&b)
{
	++__swap_times__;
	//תΪ����std::swap
	std::swap(a, b);
}

//�ṩ�ⲿ����__swap_times__�Ľӿ�
int get_swap_times()
{
	return __swap_times__;
}
void clear_swap_times()
{
	__swap_times__ = 0;
}

int get_bit(int num, int bit)
{
	if (num == 0)return 0;
	else if (bit == 0)return num % 10;
	else return get_bit(num / 10, bit - 1);
}