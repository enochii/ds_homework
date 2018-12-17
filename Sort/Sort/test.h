#pragma once

extern int __swap_times__;

template<class It>
bool test(It first, It last)
{
	if (first == last)return true;
	++first;
	while (first != last) {
		if (*first < *(first - 1))return false;
		++first;
	}
	return true;
}