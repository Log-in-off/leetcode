#include <iostream>
#include <cassert>
#include <vector>

/**
 * https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/description/
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    TreeNode* dfs(TreeNode* root, TreeNode* l, TreeNode* r) {        
        if (root->val == l->val || root->val == r->val)
        	return root;
        
        if (root->val > l->val)
        {
        	if (root->val < r->val)
        	    return root;
        	else
        	   return dfs(root->left, l, r);
        }
        else
        {
        	return dfs(root->right, l, r);	
        }
     }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (p->val > q->val)
        {
            return dfs(root, q, p);
        }
        else
        {
            return dfs(root, p, q);
        }
    }
};

int main() 
{
    std::cout << "Test done" << std::endl;
    return 0;
}