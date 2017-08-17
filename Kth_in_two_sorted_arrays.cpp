#include <iostream>
#include <cstdlib>
#include <vector>
#include <deque>
using namespace std;

int find_Kth(deque<int> &a, deque<int> &b, int k)
{
	if(k == 1)
		return min(a[0], b[0]);
	
	int index = k/2 - 1;
	if(a.size() == 0)
		return b[k - 1];
	else if(b.size() == 0)
		return a[k - 1];
	else if(index >= a.size())
	{
		if(a[a.size() - 1] <= b[index])
		{
			k = k - a.size();
			a.clear();
			return find_Kth(a, b, k);
		}
		else
		{
			for(int i = 0; i <= index; i++)
				b.pop_front();
			return find_Kth(a, b, k - index - 1);
		}
	}
	else if(index >= b.size())
	{
		if(b[b.size() - 1] <= a[index])
		{
			k = k - b.size();
			b.clear();
			return find_Kth(a, b, k);
		}
		else
		{
			for(int i = 0; i <= index; i++)
				a.pop_front();
			return find_Kth(a, b, k - index - 1);
		}
	}
	else
	{
		if(a[index] <= b[index])
		{
			for(int i = 0; i <= index; i++)
				a.pop_front();
			return find_Kth(a, b, k - index - 1);
		}
		else
		{
			for(int i = 0; i <= index; i++)
				b.pop_front();
			return find_Kth(a, b, k - index - 1);
		}
	}
}

int find_Kth_drive(vector<int> &a, vector<int> &b, int k)
{
	deque<int> a_queue, b_queue;
	for(vector<int>::iterator i = a.begin(); i != a.end(); i++)
		a_queue.push_back(*i);
	for(vector<int>::iterator i = b.begin(); i != b.end(); i++)
		b_queue.push_back(*i);
	return find_Kth(a_queue, b_queue, k);
}

int main(void)
{
	vector<int> a, b;
	/*
	a.push_back(1);
	a.push_back(2);
	a.push_back(4);
	a.push_back(6);
	a.push_back(7);
	a.push_back(11);
	a.push_back(13);
	a.push_back(15);

	b.push_back(0);
	b.push_back(3);
	b.push_back(5);
	b.push_back(8);
	b.push_back(9);
	b.push_back(12);
	b.push_back(14);
	*/

	a.push_back(0);
	a.push_back(2);

	b.push_back(1);
	b.push_back(3);
	b.push_back(4);
	b.push_back(6);
	b.push_back(7);
	b.push_back(9);
	b.push_back(10);

	cout << find_Kth_drive(a, b, 7) << endl;

	system("pause");
	return 0;
}
