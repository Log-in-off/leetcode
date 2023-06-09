#include <iostream>
#include <cassert>
#include <vector>

/**
 * https://leetcode.com/problems/maximum-depth-of-binary-tree/description/
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
public:
    int maxDepth(TreeNode* root) {
        if(!root)
            return 0;
        return 1 + std::max(maxDepth(root->left), maxDepth(root->right));
    }
};

int main() 
{
    std::cout << "Test done" << std::endl;
    return 0;
}