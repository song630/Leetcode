#include <iostream>
#include <cstdlib>
#include <vector>
#include <ctime>
#include <algorithm>
using namespace std;

class Solution {
public:
    Solution(vector<int> nums) {
        a.insert(a.end(), nums.begin(), nums.end());
        sort(a.begin(), a.end());
    }
    
    int pick(int target) {
        long lower = target - 1;
        long upper = target + 1;
        long left_bound, right_bound;
        left_bound = search_left(lower);
        right_bound = search_right(upper);
        // cout << "left_bound = " << left_bound << endl;
        // cout << "right_bound = " << right_bound << endl;
        if(left_bound + 1 == right_bound - 1)
        	return left_bound + 1;
        srand(time(NULL));
        left_bound++;
        right_bound--;
        return rand() % (right_bound - left_bound + 1) + left_bound;
    }

private:
	int search_left(long lower) {
		int left = 0, right = a.size() - 1;
        int middle;
        while(left < right)
        {
        	middle = (left + right) / 2;
        	if(a[middle] == lower)
        		return middle;
        	else if(a[middle] < lower)
        		left = middle + 1;
        	else
        		right = middle - 1;
        }
        if(a[left] == lower + 1)
        	return --left;
        else
        	return left;
	}

	int search_right(long upper) {
		int left = 0, right = a.size() - 1;
        int middle;
        while(left < right)
        {
        	middle = (left + right) / 2;
        	if(a[middle] == upper)
        		return middle;
        	else if(a[middle] < upper)
        		left = middle + 1;
        	else
        		right = middle - 1;
        }
        if(a[left] == upper - 1)
        	return ++left;
        else
        	return left;
	}
	vector<long> a;
};

int main(void)
{
	vector<int> nums;
	nums.push_back(1);
	nums.push_back(1);
	nums.push_back(3);
	nums.push_back(3);
	nums.push_back(5);
	Solution s(nums);
	cout << s.pick(3) << endl;

	system("pause");
	return 0;
}
