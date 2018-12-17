/*
2018/12/9 by 施程航
*/

#include "sort.h"
#include <algorithm>
#include "test.h"

//local variable
static int __swap_times__ = 0;

//自定义的swap
void swap(int &a, int&b)
{
	++__swap_times__;
	//转为调用std::swap
	std::swap(a, b);
}

//提供外部访问__swap_times__的接口
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