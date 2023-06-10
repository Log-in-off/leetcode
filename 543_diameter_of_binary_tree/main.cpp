#include <iostream>
#include <cassert>
#include <vector>

/**
 * https://leetcode.com/problems/diameter-of-binary-tree/description/
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
    int dfs(TreeNode* root, int& result)
    {
        if (!root)
            return 0;
        int l = dfs(root->left, result);
        int r = dfs(root->right, result);
        if (l+r > result)
            result = l+r;
        return std::max(r, l)+1;
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int result = 0;
        dfs(root, result);
        return result;
    }
};

int main() 
{
    std::cout << "Test done" << std::endl;
    return 0;
}