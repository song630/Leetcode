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
    /*
    bool isValidBST(TreeNode* root) {
    	if(root == NULL)
    		return true;
        if(root->left == NULL && root->right == NULL)
        	return true;
        else
        {
        	if(root->left && root->right == NULL && root->left->val < root->val)
        		return isValidBST(root->left);
        	else if(root->left == NULL && root->right && root->right->val > root->val)
        		return isValidBST(root->right);
        	else if(root->left && root->right && root->left->val < root->val && root->right->val > root->val)
        		return isValidBST(root->left) && isValidBST(root->right);
        	else
        		return false;
        }
    }
    */

    bool isValidBST(TreeNode* root) {
    	if(root == NULL)
    		return true;
    	if(root->left == NULL && root->right == NULL)
    		return true;
    	if(root->left == NULL && root->right)
    	{
    		if(right_subtree(root->right, root->val))
    			return isValidBST(root->right);
    		else
    			return false;
    	}
    	if(root->right == NULL && root->left)
    	{
    		if(left_subtree(root->left, root->val))
    			return isValidBST(root->left);
    		else
    			return false;
    	}
    	else
    	{
    		if(left_subtree(root->left, root->val) && right_subtree(root->right, root->val))
    			return isValidBST(root->left) && isValidBST(root->right);
    		else
    			return false;
    	}
    }

    bool left_subtree(TreeNode *T, int flag) {
    	if(T->val >= flag)
    		return false;
    	else
    	{
    		if(T->left == NULL && T->right == NULL)
    			return true;
    		else if(T->left == NULL && T->right)
    			return left_subtree(T->right, flag);
    		else if(T->right == NULL && T->left)
    			return left_subtree(T->left, flag);
    		else
    			return left_subtree(T->left, flag) && left_subtree(T->right, flag);
    	}
    }

    bool right_subtree(TreeNode *T, int flag) {
    	if(T->val <= flag)
    		return false;
    	else
    	{
    		if(T->left == NULL && T->right == NULL)
    			return true;
    		else if(T->left == NULL && T->right)
    			return right_subtree(T->right, flag);
    		else if(T->right == NULL && T->left)
    			return right_subtree(T->left, flag);
    		else
    			return right_subtree(T->left, flag) && right_subtree(T->right, flag);
    	}
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
