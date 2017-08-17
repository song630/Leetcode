#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <utility>
using namespace std;

typedef pair<int, int> Point;

class Solution {
public:
    vector< vector<string> > solveNQueens(int n) {
        string row(n, '.');
        for(int i = 0; i <= n - 1; i++)
            board.push_back(row); // initialize
        backtrace(0, 0, n);
        return results;
    }

    void backtrace(int row_index, int col_start, int n) {
        string row(n, '.');
        if(row_index > n - 1)
        {
            for(int i = 0; i <= n - 1; i++)
                cout << board[i] << endl;
            cout << endl;
            results.push_back(board);
            return;
        }
        bool flag = false;
        for(int col_index = col_start; col_index <= n - 1; col_index++)
        {
            if(is_valid_place(row_index, col_index))
            {
                cout << "1111" << endl;
                flag = true;
                board[row_index][col_index] = 'Q';
                Point new_point(row_index, col_index);
                placed_queens.push_back(new_point);
                cout << "backtrace(" << row_index + 1 << ", " << 0 << ")" << endl;
                backtrace(row_index + 1, 0, n);
                board[row_index][col_index] = '.';
                placed_queens.pop_back();
            }
        }
        if(flag == false) // cannot be placed at any place in the row
        {
            int new_col_start = placed_queens.back().second + 1;
            if(new_col_start == n && row_index == 1)
                backtrace(n, 0, n);
            else
            {
                placed_queens.pop_back();
                board[row_index-1] = row;
                cout << "backtrace(" << row_index - 1 << ", " << new_col_start << ")" << endl;
                backtrace(row_index - 1, new_col_start, n);
            }
        }
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
    print_vector(s.solveNQueens(4));

    system("pause");
    return 0;
}
