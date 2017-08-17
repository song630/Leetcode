#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

// binary indexed tree, or Fenwick tree.

int lowbit(int x) // run faster: do not call a function, use inline instead
{
	return x & (-x);
}

class NumArray {
public:
    NumArray(vector<int> nums) {
    	a.push_back(-1); // start from index 1
        a.insert(a.end(), nums.begin(), nums.end()); // copy
        c.push_back(-1);
        c.insert(c.end(), a.size() - 1, 0); // initialize
        initialize();
    }

    void initialize() {
		for(int i = 1; i <= a.size() - 1; i++)
		{
			int j = i;
			while(j <= c.size() - 1)
			{
				c[j] += a[i];
				j += lowbit(j);
			}
		}
	}
    
    void update(int i, int val) {
    	i++;
    	int changed = val - a[i];
    	a[i] += changed;
        while(i <= c.size() - 1)
        {
        	c[i] += changed;
        	// cout << "c[" << i << "] = " << c[i] << endl;
        	i += lowbit(i);
        }
    }
    
    int sumRange(int i, int j) {
    	j++;
        int sum_i = 0, sum_j = 0;
        while(i)
        {
        	sum_i += c[i];
        	i -= lowbit(i);
        }
        // cout << "sum_i = " << sum_i << endl;
        while(j)
        {
        	sum_j += c[j];
        	j -= lowbit(j);
        }
        // cout << "sum_j = " << sum_j << endl;
        return sum_j - sum_i;
    }

	vector<int> a;
	vector<int> c;
};

void print_array(vector<int>& a)
{
	for(vector<int>::iterator i = a.begin(); i != a.end(); i++)
	{
		if(i == a.begin())
			i++;
		cout << *i << " ";
	}
	cout << endl;
}

int main(void)
{
	vector<int> nums;
	nums.push_back(7);
	nums.push_back(2);
	nums.push_back(7);
	nums.push_back(2);
	nums.push_back(0);
	NumArray N(nums);
	print_array(N.a);
	print_array(N.c);
	N.update(4, 6);
	print_array(N.a);
	print_array(N.c);
	N.update(0, 2);
	print_array(N.a);
	print_array(N.c);
	N.update(0, 9);
	print_array(N.a);
	print_array(N.c);
	N.update(3, 8);
	print_array(N.a);
	print_array(N.c);
	cout << N.sumRange(0, 4) << endl;

	system("pause");
	return 0;
}
