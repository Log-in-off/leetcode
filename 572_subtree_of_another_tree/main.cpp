#include <iostream>
#include <cassert>
#include <vector>

/**
 * https://leetcode.com/problems/subtree-of-another-tree/description/
 * Definition for a binary tree node.
 */ 
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    bool isSame(TreeNode* root, TreeNode* subRoot)
    {
    	if (nullptr == root ^ nullptr == subRoot)
    		return false;
    	if (nullptr == root)
    		return true;
    	
    	if (root->val != subRoot->val)
    		return false;
    	return isSame(root->left, subRoot->left) && isSame(root->right, subRoot->right);
    }
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        
        if (isSame(root, subRoot))
        	return true;
        
        bool left = root->left ? isSubtree(root->left, subRoot): false;
        if (left)
        	return true;
        bool right = root->right ? isSubtree(root->right, subRoot):false;
        if (right)
        	return true;
        
        return false;
    }
};

int main() 
{
    std::cout << "Test done" << std::endl;
    return 0;
}