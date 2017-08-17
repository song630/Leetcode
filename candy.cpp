#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;
// solution: scan the array twice, forward and backward.

class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        int *each = new int[n];
        each[0] = 1;
        int sum = 0;
        for(int i = 1; i <= n - 1; i++)
        	each[i] = ratings[i] > ratings[i-1] ? each[i-1] + 1 : 1;
        sum = each[n-1];
        for(int i = n - 2; i >= 0; i--)
        {
        	if(ratings[i] > ratings[i+1] && each[i] <= each[i+1] + 1)
        		each[i] = each[i+1] + 1;
        	sum += each[i];
        }
        delete [] each;
        return sum;
    }
};

int main(void)
{
	vector<int> ratings;
	ratings.push_back(1);
	ratings.push_back(2);
	ratings.push_back(3);
	ratings.push_back(4);
	ratings.push_back(5);
	ratings.push_back(1);
	ratings.push_back(4);
	ratings.push_back(3);
	ratings.push_back(2);
	ratings.push_back(1);
	ratings.push_back(1);
	Solution s;
	cout << s.candy(ratings) << endl;

	system("pause");
	return 0;
}