#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

class Solution {
public:
    vector< vector<int> > combine(int n, int k) {
        traverse(n, k);
        return results;
    }

private:
    void traverse(int n, int k) {
    	if(k == 0)
    	{
    		results.push_back(one_combine);
    		return;
    	}
    	if(one_combine.size() == 0)
    	{
    		for(int i = 1; i <= n - k + 1; i++)
    		{
    			one_combine.push_back(i);
    			traverse(n, k - 1);
    			one_combine.pop_back(); //=====
    		}
    	}
    	else
    	{
    		for(int i = one_combine.back() + 1; i <= n; i++)
    		{
    			one_combine.push_back(i);
    			traverse(n, k - 1);
    			one_combine.pop_back(); //=====
    		}
    	}
    }

	vector< vector<int> > results;
	vector<int> one_combine;
};

void print(vector< vector<int> > v)
{
	int n = v.size();
	int m = v[0].size();
	for(int i = 0; i <= n - 1; i++)
	{
		for(int j = 0; j <= m - 1; j++)
			cout << v[i][j] << " ";
		cout << endl;
	}
	cout << endl;
}

int main(void)
{
	Solution s;
	print(s.combine(5, 3));

	system("pause");
	return 0;
}
