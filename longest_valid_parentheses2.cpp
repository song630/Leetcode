#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size();
        vector<int> stack;
        int max_length = 0;
        for(int i = 0; i <= n - 1; i++)
        {
            if(stack.size() && s[i] == ')' && s[stack.back()] == '(')
                stack.pop_back();
            else
                stack.push_back(i);
        }
        if(stack.size() == 0)
            return n;
        else
        {
            int max_index = stack.size() - 1;
            cout << max_index << endl;
            cout << stack[max_index] << endl;
            for(int i = 0; i <= max_index; i++)
            {
                if(i == 0)
                    max_length = stack[0] - 0;
                if(i == max_index)
                    max_length = max_length > n - 1 - stack[max_index]? max_length: (n - 1 - stack[max_index]);
                if(i != 0)
                    max_length = max_length > stack[i] - stack[i - 1] - 1 ? max_length: (stack[i] - stack[i - 1] - 1);
            }
        }
        return max_length;
    }
};

int main(void)
{
	string s;
	s = ")(((((()())()()))()(()))(";
	Solution s1;
	cout << s1.longestValidParentheses(s) << endl;

	system("pause");
	return 0;
}
