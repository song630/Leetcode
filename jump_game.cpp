#include <iostream>
#include <cstdlib>
#include <vector>
#include <Windows.h>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) { // drive
        return can_reach(nums, 0, nums.size() - 1);
    }

private:
    bool can_reach(vector<int>& nums, int start, int destination) {
    	cout << "can_reach(" << start << ", " << destination << ", ";
    	cout << nums[start] << ", " << nums[destination] << ")" << endl;
		Sleep(100);
    	int i = start;
    	while(i < destination) // get to the nearest spot
    	{
    		if(i + nums[i] >= destination || nums[i] == 0)
    			break;
    		else
    			i += nums[i];
    	}
    	// cout << "i = " << i << endl;
    	if(i + nums[i] >= destination)
    		return true;
    	else
    	{
    		i--;
    		// cout << "nums[i]" << nums[i] << endl;
    		while(i > start)
    		{
    			if(can_reach(nums, i, destination))
    				return can_reach(nums, 0, i);
    			else
    				i--;
    		}
    		return false;
    	}
    }
};

void copy_array(vector<int>& a, int b[])
{
	for(int i = 0; i <= 103; i++)
		a.push_back(b[i]);
	cout << "done" << endl;
}

int main(void)
{
	vector<int> a;
	
	int b[104] = {
		2,0,6,9,8,4,5,0,8,9,1,2,9,6,8,8,0,6,3,1,2,2,1,
		2,6,5,3,1,2,2,6,4,2,4,
		3,0,0,0,3, // 34, 35, 36, 37, 38
		8,2,4,0,1,2,0,
		1,4,6,5,8,0,7,9,3,4,6,6,5,8,9,3,4,3,7,0,4,9,0,
		9,8,4,3,0,7,7,1,9,1,9,4,9,0,1,9,5,7,7,1,5,8,2,
		8,2,6,8,2,2,7,5,1,7,9,6
	};
	copy_array(a, b);
	
	Solution s;

	cout << s.canJump(a) << endl;

	system("pause");
	return 0;
}
