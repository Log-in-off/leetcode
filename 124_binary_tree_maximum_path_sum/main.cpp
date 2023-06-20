#include <iostream>
#include <cassert>
#include <vector>

/**
 * https://leetcode.com/problems/binary-tree-maximum-path-sum/description/
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
    int max_;
    int dfs(TreeNode* root)
    {
        if (!root)
            return 0;
        int left = std::max(dfs(root->left), 0);
        int right = std::max(dfs(root->right), 0);
                        
        max_ = std::max(max_, left+right+root->val);
        return std::max(left, right)+root->val;
    }
public:
    int maxPathSum(TreeNode* root) {
        max_ = 0;
    	if (root)
        	max_=root->val;
        return std::max(max_, dfs(root));
    }
};

int main() 
{
    std::cout << "Test done" << std::endl;
    return 0;
}