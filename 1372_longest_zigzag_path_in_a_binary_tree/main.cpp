#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>

/*
https://leetcode.com/problems/longest-zigzag-path-in-a-binary-tree/description/
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
    void dfs(TreeNode* root, bool left, int sum)
    {
        if (!root)
        {
            if (sum > max_)
                max_ = sum;
            return;
        }
        sum++;

        if (left)
        {
            dfs(root->left, true, 0);
            dfs(root->right, false, sum);
        }
        else
        {
            dfs(root->left, true, sum);
            dfs(root->right, false, 0);
        }

    }
public:
    int longestZigZag(TreeNode* root) {
        max_ = 0;
        dfs(root->left, true, 0);
        dfs(root->right, false, 0);
        return max_;
    }
};

#define null std::nullopt
int main()
{
    Solution a;
    std::cout << "Test done" << std::endl;
    return 0;
}