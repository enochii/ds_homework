#pragma once

//a simple list implementation

namespace _sch {
	struct _list_node {
		typedef _list_node* link_type;
		link_type next, prev;
		int element;

		//在这里next指针还是用不了的-=-
		_list_node(int val) :element(val) {}
	};

	struct _list_iterator {
		friend class list;
		typedef _list_node* link_type;
	private:
		link_type node;
	public:
		bool operator==(const _list_iterator& it)const {
			return node == it.node;
		}
		bool operator!=(const _list_iterator& it) const{
			return !(operator==(it));
		}

		_list_iterator(link_type _node) :node(_node) {}

		_list_iterator& operator++() {
			node = node->next;
			return *this;
		}

		_list_iterator operator++(int) {
			auto copy_ = *this;

			++(*this);
			return copy_;
		}

		int& operator *() {
			return node->element;
		}
		//link_type operator ->() {}
	};

	//list
	class list {
		typedef _list_node* link_type;
		link_type _end;//环形链表

		//typedef _slist_node node;

	public:
		typedef _list_iterator iterator;
		typedef const _list_iterator const_iterator;
	private:
		void initial_node_ptr() {
			_end->next = _end;
			_end->prev = _end;
		}

		link_type alloc_node(int val) {
			return new _list_node(val);
		}

		void destroy_node(link_type node) {
			delete node;
		}
	public:
		iterator begin() {
			return iterator(_end->next);
		}
		iterator end() {
			return iterator(_end);
		}

		//constant version
		const_iterator begin()const {
			return const_iterator(_end->next);
		}
		const_iterator end() const{
			return const_iterator(_end);
		}
		void insert(iterator it, int x)//insert before
		{
			auto insert_node = alloc_node(x);

			it.node->prev->next = insert_node;
			insert_node->prev = it.node->prev;

			it.node->prev = insert_node;
			insert_node->next = it.node;
		}

		bool empty()const {
			return _end->next == _end;
		}
		//ctr
		list():_end(alloc_node(-1)){
			initial_node_ptr();
		}

		template <class It>
		list(It begin, It end):_end(alloc_node(-1)){
			initial_node_ptr();

			copy(begin, end);
		}

		list(const list & list_):_end(alloc_node(-1)){
			initial_node_ptr();//p1

			clear();
			copy(list_.begin(), list_.end());
		}

		//dtr
		~list() {
			clear();
			delete _end;
		}
	private:
		void clear() {
			for (auto it = begin();it != end();) {
				auto temp = it.node;
				temp->prev->next = temp->next;
				temp->next->prev = temp->prev;

				++it;
				
				delete temp;
			}
		}

		//
		template<class It>
		void copy(It first, It last) {
			//clear();

			while (first != last) {
				//减少函数调用，不过代码会变丑--
#ifdef __FAST_COPY

				auto insert_node = alloc_node(*first);
				_end->prev->next = insert_node;
				insert_node->prev = _end->prev;

				insert_node->next = _end;
				_end->prev = insert_node;
#else
				insert(end(), *first);
#endif
				++first;
			}
		}
	};
}//end of namespace _sch