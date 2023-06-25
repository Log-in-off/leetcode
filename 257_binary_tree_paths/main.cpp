#include <iostream>
#include <cassert>
#include <vector>

/**
https://leetcode.com/problems/binary-tree-paths/description/
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
    void fdp(TreeNode* root, std::vector<std::string>& answer, std::string tmp)
    {
        if(next)
            tmp += "->";
        next = true;
        tmp += std::to_string(root->val);
        if (!root->left && !root->right)
        {
            answer.push_back(tmp);
        }
        else
        {
            if (root->left)
            {
                fdp(root->left, answer, tmp);
            }

            if (root->right)
            {
                fdp(root->right, answer, tmp);
            }
        }

    }
    bool next;
public:
    std::vector<std::string> binaryTreePaths(TreeNode* root) {
        std::vector<std::string> answer;
        next = false;
        std::string tmp;

        fdp(root, answer, tmp);
        return answer;
    }
};

int main() 
{
    std::cout << "Test done" << std::endl;
    return 0;
}