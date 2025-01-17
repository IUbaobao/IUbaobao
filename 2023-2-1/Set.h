#pragma once 

#include "RBTree.h"

namespace hdm
{
	template<class K>
	class set
	{
	public:
		class SetKeyOfT
		{
		public:
			const K& operator()(const K&key)
			{
				return key;
			}
		};

		typedef typename  RBTree<K, K, SetKeyOfT>::const_iterator iterator;
		typedef typename  RBTree<K, K, SetKeyOfT>::const_iterator const_iterator;


		iterator begin()const 
		{
			return _t.begin();
		}
		
		iterator end()const
		{
			return _t.end();
		}
		pair<iterator,bool> insert(const K&key)
		{
			return _t.Insert(key);
		}
	private:
		RBTree<K, K, SetKeyOfT> _t;
	};


	void test_set()
	{
		int a[] = { 4, 2, 6, 1, 3, 5, 15, 7, 16, 14 };
		set<int> s;
		for (auto e : a)
		{
			s.insert(e);
		}

		set<int>::iterator it = s.begin();
		while (it != s.end())
		{
			//(*it)++;
			//++(*it);
			cout << *it << " ";
			++it;
		}
		cout << endl;

		for (auto e : s)
		{
			cout << e << " ";
		}
		cout << endl;
	}

}