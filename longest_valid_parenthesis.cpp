#include <iostream>
#include <cstdlib>
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size();
        if(n == 0)
        	return 0;
        stack<char> sta;
        int max_length = 0;
        int temp = 0, count;
        bool flag;
        for(int i = 0; i <= n - 1;)
        {
        	count = 0;
        	if(s[i] == ')')
        	{
        		flag = false;
        		i++;
        	}
        	else
        	{
        		if(flag == false)
        			temp = 0;
        		do {
        			if(sta.size() != 0 && sta.top() == '(' && s[i] == ')')
        			{
        				sta.pop();
        				temp += 2;
        				count += 2;
        			}
        			else
        				sta.push(s[i]);
        			i++;
        		} while(sta.size() && i <= n - 1);
        		cout << "sta.size() = " << sta.size() << endl;
        		cout << "temp = " << temp << endl;
        		cout << "count = " << count << endl;
        		flag = true;
        		max_length = (max_length > temp)? max_length: temp;
        		if(sta.size() && i >= n - 1)
        			max_length -= count;
        	}
        }
        if(max_length == 0)
        	return count;
        return max_length;
    }
};

int main(void)
{
	string s;
	s = "(()(((()";
	Solution s1;
	cout << s1.longestValidParentheses(s) << endl;

	system("pause");
	return 0;
}
