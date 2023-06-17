#include <iostream>
#include <cassert>
#include <vector>

/**
 * https://leetcode.com/problems/validate-binary-search-tree/submissions/
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
    bool isValidNode(TreeNode* root, long max, long min)
    {
        if (!root)
            return true;        

        if (root->val >= max || root->val <= min)
                return false;
        
        return isValidNode(root->left,  root->val, min) &&
               isValidNode(root->right, max, root->val); 
    }
public:
    bool isValidBST(TreeNode* root) {
        return isValidNode(root, INT64_MAX, INT64_MIN);
    }
};

int main() 
{
    std::cout << "Test done" << std::endl;
    return 0;
}