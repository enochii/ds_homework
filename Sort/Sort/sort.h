/*
2018/12/9 by ʩ�̺�
*/

#pragma once
#include <iostream>
#include <string>
#include <ctime>
#include <algorithm>

/*
���������㷨������һ�Ե�����������Ĭ�ϴ���ĵ��������������������Ԫ�أ�����ʱ����ͳһʹ��stl��std::vector<int>
������������Ҳ����ʹ��ԭ��ָ�����std::deque<int>��etc. 

����������˵����֧��˫������������������

������һ���ֲ���Ҫ������������㷨Ҳ����֧��std::list<int>���֣���ʵ�������Ҫ�Ļ�Ҳ����֧��std::list��Ӧ��ʹ��std::next
һ��Ķ�������Ҫ�ǳ������ܲ���...
*/

/*
TODO:Ͱ����˫��ð��...��β�ݹ�Ŀ��ţ���������
*/

#define TOTAL_TIME(sort_type, times) cout<<sort_type<<"��������ʱ�䣺\t"<<times<<"s\n"
#define EXCHANGES(sort_type)cout<<sort_type<<"���򽻻�������\t"<<get_swap_times()<<'\n';

#define DEBUG

//�������Ӿ�̬������������Ҳû��...
extern int __swap_times__;

template<class C>
void display_container(C& container)
{
	for (auto &x : container) {
		std::cout << x << " ";
	}
	std::cout << std::endl;
}

//������ͬʱ��¼����
void swap(int &a, int &b);

int get_swap_times();

void clear_swap_times();

//�����û���������зַ��������㻨��ʱ��
template<class It>
void dispatch(int sort_num, It first, It last)
{
	clear_swap_times();
	//__swap_times__ = 0;
	static std::string to_string[10] = {
		"","ð��","ѡ��","ֱ�Ӳ���","ϣ��","����","��","�鲢","����",
	};
	int time_start = clock();
	switch (sort_num)
	{
	case 1:bubble_sort(first, last);break;
	case 2:select_sort(first, last);break;
	case 3:insert_sort(first, last);break;
	case 4:shell_sort(first, last);break;
	case 5:quick_sort(first, last);break;
	case 6:heap_sort(first, last);break;
	case 7:merge_sort(first, last);break;
	case 8:radix_sort(first, last);break;
	default:
		return;//break;
	}
	int time_finish = clock();
	TOTAL_TIME(to_string[sort_num], (time_finish - time_start)*1.0 / CLOCKS_PER_SEC);
	EXCHANGES(to_string[sort_num]);
}

//��������
template<class It>
void _insert_sort(It first, It last)
{
	auto beg = first ++;
	while (first != last) {
		for (auto it = beg;it != first;++it) {

			if (*it > *first) {
#ifdef DEBUG
				std::cout << *it << " <-> " << *first << std::endl;
#endif // DEBUG
				for (auto _it = first;_it != it;--_it) {
					swap(*_it, *(std::prev(_it, 1)));
				}
				break;
			}
		}
		++first;
		//break;
	}
}

//����v2...
template<class It>
void insert_sort(It first, It last)
{
	//assert(0);
	if (first == last)return;
	auto beg = first++;
	
	while (first != last) {
		auto temp = *first;
		for (It it = first;it != beg;--it) {
			if (*(it - 1) <= temp)break;
			else ::swap(*(it - 1), *it);
		}

		++first;
	}
}

//ѡ������
template<class It>
void select_sort(It first, It last)
{
	//��cur_position֮ǰ��Ԫ�ؾ�����
	//auto beg = first;
	//typedef typename It::value_type value_type;
	while (first != last) {
		It smallest = first;
		for (auto it = first;it != last;++it) {
			if (*smallest > *it) {
				smallest = it;
			}
		}
		swap(*smallest, *first++);
	}
}

//ð������
template<class It>
void bubble_sort(It first, It last)
{
	//auto beg = first++;
	//ð�ݴ���Ϊ��������Χ�ڵ�Ԫ������-1
	while (first < --last) {
		for (auto it = first;it != last;++it) {
			if (*it > *(it + 1)) {
				swap(*it, *(it + 1));
			}
		}
	}
}

//(3^k - 1) / 2
static int __shell_steps__[20] = {
	1, 4, 13, 40, 121, 364, 1093, 3280, 9841, 29524, 88573, 265720, 797161,
};

//ϣ������
//ϣ������ֻ֧�����������
template<class It>
void shell_sort(It first, It last)
{
	int delta_index = -1;
	int num = (last - first);
	for (;__shell_steps__[delta_index + 1] < num / 3;++delta_index);

	int delta;
	//ÿ���������������1
	while (delta_index>=0) {
		delta = __shell_steps__[delta_index];

		for (int i = delta;i < num;++i) {
			if (*(first + i) >= *(first + (i - delta)))continue;
			//else
			auto temp = *(first + i);
			for (int j = i - delta;j >= 0;j -= delta) {
				if (temp < *(first + j))
					::swap(*(first + j + delta), *(first + j));
				else break;
			}
		}
		delta_index--;
	}
}

//��������
//֧��˫����ʵ�����
template<class It>
void quick_sort(It first, It last)
{
	/*
	ѭ��������Ϊ������it���Ԫ��split_pos��keyֵӦ�ò����λ��
	*/
	if (first == last || first + 1 == last) {
		return;
	}
	//
	auto key = *first;

	auto split_pos1 = ::partition(first, last, [key](const auto& elem) {return elem < key;});
	auto split_pos2 = ::partition(split_pos1, last, [key](const auto& elem) {return elem == key;});

	quick_sort(first, split_pos1);
	quick_sort(split_pos2, last);
}


template<class It, class UnaryPred>
It partition(It first, It last, UnaryPred pred)
{
	for (;;) {
		for (;;) {
			if (first == last)
				return first;
			if (!pred(*first))
				//����ʱfirstָ���Ԫ�ش���keyֵ
				break;
			++first;
		}
		do {
			--last;
			if (first == last)
				return first;
		} while (!(pred(*last)));

		::swap(*last, *first++);
	}
}

//������
//ֻ֧��������ʵ�����
template<class It>
void heap_sort(It first, It last)
{
	__build_heap__(first, last);
	auto num = last - first;
	for (int i = 0;i < num - 1;++i) {
		__extract_heap__(first, last - i);
	}
}

//����
template<class It>
void __adjust_heap__(It pos, It first, It last)
{
	auto index = pos - first + 1;
	auto len = last - first + 1;

	while (index * 2 < len) {
		auto bigger_son = index * 2;
		if (index * 2 + 1 < len&&*(first + index * 2 + 1 - 1) > *(first + index * 2 - 1)) {
			bigger_son += 1;
		}
		//auto next_index = -1;
		if (*(first + bigger_son - 1) > *(first + index - 1)) {
			swap(*(first + bigger_son - 1), *(first + index - 1));
			index = bigger_son;
		}
		else {
			return;//???
		}
	}
}

//ȡ����������Ԫ�ؼ��Ѷ����������ĩβλ�ò����е���
template<class It>
void __extract_heap__(It first, It last)
{
	swap(*first, *(last - 1));
	__adjust_heap__(first, first, last - 1);
}

//��������
template<class It>
void __build_heap__(It first, It last)
{
	auto len = last - first + 1;

	for (auto begin = len / 2;begin > 0;--begin) {
		__adjust_heap__(first + (begin - 1), first, last);
	}
}

//��������
template<class It>
void radix_sort(It first, It last)
{
	typedef typename It::value_type value_type;
	std::vector<value_type> bukects[10];

	int max_num = -1;
	for (auto it = first;it != last;++it) {
		if (*it > max_num)max_num = *it;
	}
	int max_bit = 0;
	while (max_num != 0) {
		max_num /= 10;
		++max_bit;
	}

	//int max_bits = -1;
	for (int cur_bit = 0;cur_bit < max_bit;++cur_bit) {
		for (auto it = first;it != last;++it) {
			bukects[get_bit(*it, cur_bit)].push_back(*it);
			//swap(int a(), int b());
		}
		auto beg = first;
		for (int bucket_i = 0;bucket_i < 10;++bucket_i) {
			for (auto &x : bukects[bucket_i]) {
				swap(*beg++, x);
			}
			bukects[bucket_i].clear();
		}
	}
}

//ȡ��num��Ӧbitλ�ϵ�����bit=0��ʾ��λ����������
int get_bit(int num, int bit);

template<class It>
void merge_sort(It first, It last)
{
	if (first == last || first == last - 1) {
		return;
	}

	auto len = last - first;

	merge_sort(first, first + len / 2);
	merge_sort(first + len / 2, last);

	std::vector<It::value_type> temp(len, 0);

	__merge__(first, first + len / 2, first + len / 2, last, temp.begin());

	auto src = temp.begin();
	for (auto it = first;it != last;++it) {
		swap(*it, *src++);
	}
}

template<class It>
void __merge__(It first1, It last1, It first2, It last2, It dest)
{
	while (first1 != last1 && first2 != last2) {
		if (*first1 < *first2) {
			*dest++ = *first1++;
		}
		else {
			*dest++ = *first2++;
		}
	}
	while (first1 != last1) {
		*dest++ = *first1++;
	}
	while (first2 != last2) {
		*dest++ = *first2++;
	}
}