#include "intersection.h"

list_int intersection(const list_int& first_list, const list_int& second_list)
{
	list_int res;//result

	if (first_list.empty())
	{
		return res;//返回空链表
	}
	else if (second_list.empty())
	{
		return res;
	}
	//两个链表均不为空
	auto f_it = first_list.begin();
	auto s_it = second_list.begin();

	
	while (f_it != first_list.end() && s_it != second_list.end())
	{
		if (*f_it == *s_it)
		{
			res.insert(res.end(), *f_it);

			auto inserted_just_now = *f_it;
			while(f_it!=first_list.end() && *f_it==inserted_just_now)
				++f_it;

			while (s_it!= second_list.end() && *s_it == inserted_just_now)
				++s_it;
		}
		while (f_it != first_list.end() && *f_it < *s_it) {
			++f_it;
		}
		if (f_it == first_list.end())break;
		//
		while (s_it != second_list.end() && *s_it < *f_it) {
			++s_it;
		}
	}
	
	return res;
}