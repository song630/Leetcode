#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        if(n == 0)
        	return -1;
        if(n == 1)
        {
        	if(gas[0] - cost[0] >= 0)
        		return 0;
        	else
        		return -1;
        }
        int sum = 0;
        for(int i = 0; i <= n - 1; i++)
        {
        	gas[i] = gas[i] - cost[i];
        	sum += gas[i];
        }
        if(sum < 0)
        	return -1;
        if(n == 2)
        	return gas[0] >= 0 ? 0 : 1;
        else
        {
        	for(int i = 0; i <= n - 2; i++)
	        	cost[i] = gas[i] + gas[i + 1];
	        cost[n - 1] = gas[0] + gas[n - 1];
	        int i = 0;
	        while(cost[i] >= 0) // find the first negative number
	        	i++;
	        while(cost[i] < 0)
	        {
	        	if(i == n - 1)
	        		i = 0;
	        	else
	        		i++;
	        }
	        if(gas[i] < 0)
	        	i++;
	        return i;
        }
    }
};

void copy_array(vector<int>& v, int a[])
{
	for(int i = 0; i <= 49; i++)
		v.push_back(a[i]);
}

int main(void)
{
	vector<int> gas, cost;
	/*
	int a[50] = {
		31,32,33,34,35,36,37,38,39,40,
		41,42,43,44,45,46,47,48,49,50,
		1,2,3,4,5,6,7,8,9,10,11,12,13,
		14,15,16,17,18,19,20,21,22,23,
		24,25,26,27,28,29,30
	};
	int b[50] = {
		36,37,38,39,40,41,42,43,44,45,
		46,47,48,49,50,1,2,3,4,5,6,7,8,
		9,10,11,12,13,14,15,16,17,18,19,
		20,21,22,23,24,25,26,27,28,29,30,
		31,32,33,34,35
	};
	copy_array(gas, a);
	copy_array(cost, b);
	*/
	gas.push_back(1);
	gas.push_back(2);
	cost.push_back(2);
	cost.push_back(1);
	Solution s;
	cout << s.canCompleteCircuit(gas, cost) << endl;

	system("pause");
	return 0;
}
