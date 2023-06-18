#include <iostream>
#include <cassert>
#include <vector>

/**
 * https://leetcode.com/problems/kth-smallest-element-in-a-bst/description/
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
    void LNR(TreeNode* root, int& k, int& answer)
    {
        if (!k || !root)
            return;
        
        LNR(root->left, k, answer);
        if (k == 1)
            answer = root->val;
        k--;
        LNR(root->right, k, answer);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        int answer = 0;
        LNR(root, k, answer);
        return answer;
    }
};

int main() 
{
    std::cout << "Test done" << std::endl;
    return 0;
}