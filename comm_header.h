#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <sstream>
#include <fstream>
#include <cmath>
#include <climits>
#include <assert.h>
using namespace std;


struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};


template<class T>
vector<T> input_vec()
{
	vector<T> data;
	string line;
	while (line.empty() && getline(cin, line));
	
	if (!line.empty())
	{
		stringstream ss;
		ss << line;
		T ele;
		while (ss >> ele)
		{
			data.push_back(ele);
		}
	}
	
	return data;
}

ListNode * input_ListNode()
{
	ListNode * head = NULL;
	string line;
	while (line.empty() && getline(cin, line));

	if (!line.empty())
	{
		stringstream ss;
		ss << line;
		int val;
		ListNode * tail = NULL;
		while (ss >> val)
		{
			ListNode * ptr = new ListNode(val);
			if (head == NULL)
			{
				head = tail = ptr;
			}
			else
			{
				tail->next = ptr;
				tail = tail->next;
			}
		}
	}
	
	return head;
}

template<class T>
T input()
{
	T data;
	cin >> data;
	return data;
}


bool equal(double a, double b)
{
	return abs(a - b) < 1e-8;
}


template<class T>
bool equal(const vector<T> & lhs, const vector<T> & rhs)
{
	if (lhs.size() != rhs.size())
	{
		cout << "vector size not fit " << lhs.size() << ", " << rhs.size() << endl;
		return false;
	}
	for (size_t i = 0; i < lhs.size(); ++i)
	{
		if (lhs[i] != rhs[i])
		{
			cout << "lhs[i]=" << lhs[i] << ", rhs[i]=" << rhs[i] << ", i=" << i << endl;
			return false;
		}
	}

	return true;
}


bool equal(ListNode * lhs, ListNode * rhs)
{
	while (lhs != NULL && rhs != NULL)
	{
		if (lhs->val != rhs->val)
			return false;
		lhs = lhs->next;
		rhs = rhs->next;
	}

	return lhs == rhs;
}

