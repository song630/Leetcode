#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <utility>
using namespace std;

typedef pair<int, int> Point;

class Solution {
public:
    vector< vector<string> > solveNQueens(int n) { // drive
        string row(n, '.');
        for(int i = 0; i <= n - 1; i++)
            board.push_back(row); // initialize
        backtrace(0, n, n);
        return results;
    }

private:
    bool is_valid_place(int x, int y) {
        int n = placed_queens.size();
        if(n == 0)
            return true;
        for(int i = 0; i <= n - 1; i++)
        {
            if(placed_queens[i].second == y)
                return false;
            int sub_x = placed_queens[i].first - x;
            int sub_y = placed_queens[i].second - y;
            if(sub_x == sub_y || sub_x == -sub_y)
                return false;
        }
        return true;
    }

    void backtrace(int row_index, int k, int n) {
        string row(n, '.');
        if(k == 0) //===== ERROR: do not use row_index > n - 1 as a terminate condition
        {
            results.push_back(board);
            return;
        }
        for(int i = 0; i <= n - 1; i++)
        {
            if(is_valid_place(row_index, i))
            {
                Point new_point(row_index, i);
                placed_queens.push_back(new_point);
                board[row_index][i] = 'Q';
                backtrace(row_index + 1, k - 1, n);
                placed_queens.pop_back();
                board[row_index][i] = '.';
            }
        }
    }

    vector< vector<string> > results;
    vector<string> board;
    vector<Point> placed_queens;
};

void print_vector(vector< vector<string> > results)
{
    int n = results.size();
    int m = results[0].size();
    for(int i = 0; i <= n - 1; i++)
    {
        for(int j = 0; j <= m - 1; j++)
            cout << results[i][j] << endl;
        cout << endl;
    }
}

int main(void)
{
    Solution s;
    print_vector(s.solveNQueens(6));

    return 0;
}
