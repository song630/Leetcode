#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

class Solution {
public:
    int minPathSum(vector< vector<int> >& grid) {
        int row = grid.size();
        int column = grid[0].size();
        int **sum = new int* [row]; // ERROR?
        for(int i = 0; i <= column - 1; i++)
        	sum[i] = new int[column];
        sum[0][0] = grid[0][0];
        for(int i = 1; i <= column - 1; i++) // the first row
        	sum[0][i] = sum[0][i-1] + grid[0][i];
        for(int j = 1; j <= row - 1; j++) // the first column
        	sum[j][0] = sum[j-1][0] + grid[j][0]; // done with initialization

        for(int i = 1; i <= row - 1; i++)
        	for(int j = 1; j <= column - 1; j++)
        		sum[i][j] = (sum[i][j-1] >= sum[i-1][j]) ? (sum[i-1][j] + grid[i][j]) : (sum[i][j-1] + grid[i][j]);

        return sum[row-1][column-1];
    }
};

int main(void)
{
	vector<int> a1, a2, a3;
	a1.push_back(1);  a1.push_back(2);
	a2.push_back(5);  a2.push_back(6);
	a3.push_back(1);  a3.push_back(1);
	vector< vector<int> > grid;
	grid.push_back(a1);
	grid.push_back(a2);
	grid.push_back(a3);
	Solution s;
	cout << s.minPathSum(grid) << endl;

	system("pause");
	return 0;
}
