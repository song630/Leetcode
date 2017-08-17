#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        int size;
        int *merged = new int[n1 + n2];
        if(n1 == 0 && n2 == 0)
        	return 0;
        else if(n1 == 0)
        {
        	size = n2;
        	for(int i = 0; i <= n2 - 1; i++)
        		merged[i] = nums2[i];
        }
        else if(n2 == 0)
        {
        	size = n1;
        	for(int i = 0; i <= n1 - 1; i++)
        		merged[i] = nums1[i];
        }
        else
        {
        	size = n1 + n2;
        	int i = 0, j = 0, k = 0;
        	while(1)
        	{
        		if(nums1[i] <= nums2[j])
        			merged[k++] = nums1[i++];
        		else
        			merged[k++] = nums2[j++];
        		if(i == n1 || j == n2)
        			break;
        	}
        	if(i == n1)
        	{
        		for(; j < n2; j++)
        			merged[k++] = nums2[j];
        	}
        	else if(j == n2)
        	{
        		for(; i < n1; i++)
        			merged[k++] = nums1[i];
        	}
        }
        if(size % 2 == 0)
        	return (merged[size / 2] + merged[size / 2 - 1]) / 2.0;
        else
        	return merged[size / 2];
    }
};

int main(void)
{
	vector<int> a, b;
	b.push_back(1);
	b.push_back(1);
	b.push_back(1);
	Solution s;
	cout << s.findMedianSortedArrays(a, b) << endl;

	system("pause");
	return 0;
}