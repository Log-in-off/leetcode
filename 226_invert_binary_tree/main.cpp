#include <iostream>
#include <cassert>
#include <vector>

/**
 * https://leetcode.com/problems/invert-binary-tree/description/
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
    void rev(TreeNode* root)
    {
        if (!root)
            return;
        std::swap(root->left, root->right);
        rev(root->left);
        rev(root->right);    
    }
public:
    TreeNode* invertTree(TreeNode* root) {
        if (!root)
  	        return root;
        rev(root);
        return root;     
    }
};

int main() 
{
    std::cout << "Test done" << std::endl;
    return 0;
}