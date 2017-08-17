#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;

// long and int: overflow----[-214748368, 2147483647]

class Solution {
public:
	Solution(): count(0) {}
    int countRangeSum(vector<int>& nums, int lower, int upper) // drive
    {
    	if(nums.size() == 0)
    		return 0;
        divide(nums, lower, upper, 0, nums.size() - 1);
        return count;
    }

private:
	int count;
	void divide(vector<int>& nums, int lower, int upper, int left, int right)
	{
		if(left == right)
		{
			if(nums[left] >= lower && nums[left] <= upper)
				count++;
			return;
		}
		else if(right == left + 1)
		{
			int sum = nums[left] + nums[right];
			if(nums[left] >= lower && nums[left] <= upper)
				count++;
			if(nums[right] >= lower && nums[right] <= upper)
				count++;
			if(sum >= lower && sum <= upper)
				count++;
			return;
		}
		else
		{
			int m = (right + left) / 2; //===== ERROR: m = (right - left) / 2;
			int size = right - m;
			int *prefix = new int[size];
			int sum = 0;
			for(int i = m + 1; i <= right; i++) // prefix
			{
				sum += nums[i];
				prefix[i - m - 1] = sum;
			}
			sort(prefix, prefix + size);
			sum = 0;
			for(int i = m; i >= left; i--) // suffix
			{
				sum += nums[i];
				double new_upper = static_cast<double> (upper) - static_cast<double> (sum),
				       new_lower = static_cast<double> (lower) - static_cast<double> (sum);
				count += upper_binary_search(prefix, size, new_upper) - lower_binary_search(prefix, size, new_lower) + 1;
				// cout << "search result 1: " << upper_binary_search(prefix, size, new_upper);
				// cout << ", ";
				// cout << "search result 2: " << lower_binary_search(prefix, size, new_lower) << endl;
			}
			delete [] prefix;
			divide(nums, lower, upper, left, m);
			divide(nums, lower, upper, m + 1, right);
			return;
		}
	}

	int upper_binary_search(int prefix[], int size, double value) // return an index of prefix[]
	{
		int left = 0, right = size - 1;
		int middle = right / 2;
		while(left < right) // when left == right, break
		{
			if(prefix[middle] == value)
			{
				while(prefix[middle + 1] == value)
					middle++; // in case of duplicate numbers
				return middle;
			}
			else if(prefix[middle] < value)
			{
				left = middle + 1;
				middle = (left + right) / 2;
			}
			else if(prefix[middle] > value)
			{
				right = middle - 1;
				middle = (left + right) / 2;
			}
		}
		if(prefix[left] > value)
			return left - 1;
		else
			return left;
	}

	int lower_binary_search(int prefix[], int size, double value) // return an index of prefix[]
	{
		int left = 0, right = size - 1;
		int middle = right / 2;
		while(left < right) // when left == right, break
		{
			if(prefix[middle] == value)
			{
				while(prefix[middle - 1] == value)
					middle--; // in case of duplicate numbers
				return middle;
			}
			else if(prefix[middle] < value)
			{
				left = middle + 1;
				middle = (left + right) / 2;
			}
			else if(prefix[middle] > value)
			{
				right = middle - 1;
				middle = (left + right) / 2;
			}
		}
		if(prefix[left] < value)
			return left + 1;
		else
			return left;
	}
};

int main(void)
{
	vector<int> nums;
	nums.push_back(2147483647);
	nums.push_back(-2147483648);
	nums.push_back(-1);
	nums.push_back(0);
	Solution s;
	cout << s.countRangeSum(nums, -1, 0) << endl;

	system("pause");
	return 0;
}
