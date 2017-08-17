#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

class Solution {
public:
    int minimumTotal(vector< vector<int> >& triangle) {
        int n = triangle.size();
        if(n == 0)
        	return 0;
        int **path = new int* [n]; //===== ERROR: how to dynamically assign a two-dimension array
        int **sum = new int* [n];
        for(int i = 0; i <= n - 1; i++)
        {
        	path[i] = new int[n];
        	sum[i] = new int[n];
        }
        path[0][0] = -1;
        sum[0][0] = triangle[0][0]; // done with initialization

        for(int i = 1; i <= n - 1; i++)
        {
        	for(int j = 0; j <= i; j++)
        	{
        		if(j == 0) // the left bound element
        		{
        			path[i][j] = 0; // index in the row above
        			sum[i][j] = sum[i - 1][j] + triangle[i][j];
        		}
        		else if(j == i) // the right bound element
        		{
        			path[i][j] = j - 1;
        			sum[i][j] = sum[i - 1][j - 1] + triangle[i][j];
        		}
        		else
        		{
        			if(sum[i - 1][j - 1] <= sum[i - 1][j])
        			{
        				path[i][j] = j - 1;
        				sum[i][j] = sum[i - 1][j - 1] + triangle[i][j];
        			}
        			else
        			{
        				path[i][j] = j;
        				sum[i][j] = sum[i - 1][j] + triangle[i][j];
        			}
        		}
        	}
        }
        int min_sum = sum[n - 1][0];
        for(int i = 1; i <= n - 1; i++)
        	if(sum[n - 1][i] < min_sum)
        		min_sum = sum[n - 1][i];
        return min_sum;
    }
};

int main(void)
{
	vector<int> a, b, c, d;
	vector< vector<int> > triangle;
	a.push_back(2);
	b.push_back(3);
	b.push_back(4);
	c.push_back(6);
	c.push_back(5);
	c.push_back(7);
	d.push_back(4);
	d.push_back(1);
	d.push_back(8);
	d.push_back(3);
	triangle.push_back(a);
	triangle.push_back(b);
	triangle.push_back(c);
	triangle.push_back(d);
	Solution s;
	cout << s.minimumTotal(triangle);

	system("pause");
	return 0;
}
