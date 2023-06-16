#include <iostream>
#include <cassert>
#include <vector>

/**
 * https://leetcode.com/problems/count-good-nodes-in-binary-tree/description/
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
    void dfs(TreeNode* root, int max)
    {
        if (!root)
            return;

        if (root->val>= max)
        {
            answer_++;
            max = root->val;
        }
        dfs(root->left, max);
        dfs(root->right, max);
    }
    int answer_;
public:
    int goodNodes(TreeNode* root) {
        answer_ = 0;
        if(root)
            dfs(root, root->val);
        return answer_;
    }
};

int main() 
{
    std::cout << "Test done" << std::endl;
    return 0;
}