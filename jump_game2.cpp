#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) { // linear time
    	int destination = nums.size() - 1;
    	int max_reach = 0, i;
		for(i = 0; i < destination && i <= max_reach; ++i) // update
		{
			if(max_reach < i + nums[i])
				max_reach = i + nums[i];
		}
		return max_reach >= destination;
    }
};

int main(void)
{
	vector<int> a;
	Solution s;
	a.push_back(0);
	a.push_back(1);

	cout << s.canJump(a) << endl;

	system("pause");
	return 0;
}