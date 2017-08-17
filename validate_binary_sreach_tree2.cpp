#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

class TreeNode {
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x), left(NULL), right(NULL) {}
};
 
class Solution {
public:
    bool isValidBST(TreeNode *root)
    {
    	return validate(root, -1e10, 1e10);
    }

    bool validate(TreeNode *root, long lower, long upper) // lower and upper bound of an interval
    { // must use long
        if(root == NULL)
            return true;
        if(root->val <= lower || root->val >= upper)
            return false;

        if(root->left == NULL && root->right == NULL)
            return true;
        else if(root->left == NULL && root->right)
            return validate(root->right, root->val, upper);
        else if(root->right == NULL && root->left)
            return validate(root->left, lower, root->val);
        else if(root->left && root->right)
            return validate(root->left, lower, root->val) && validate(root->right, root->val, upper);
    }
};

int main(void)
{
	TreeNode T1(2);
	TreeNode T2(3);
	TreeNode T3(1);
	T3.left = &T1;
	T3.right = &T2;
	Solution s;
	cout << s.isValidBST(&T3) << endl;

	system("pause");
	return 0;
}
