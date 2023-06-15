#include <iostream>
#include <cassert>
#include <vector>
#include <queue>

/**
 * https://leetcode.com/problems/binary-tree-level-order-traversal/description/
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
    /*BFS*/
    std::vector<std::vector<int>> levelOrder(TreeNode* root) {
        std::vector<std::vector<int>> answer;
        std::queue<TreeNode*> q;
        if (root) {
            q.push(root);
        }

        while(!q.empty())
        {
            std::vector<int> tmp;
            int count = q.size();
            for(int i = 0; i < count; i++)
            {
                TreeNode* node = q.front();
                q.pop();
                
                tmp.push_back(node->val);
                
                if (node->left)
                    q.push(node->left);
                
                if (node->right)
                    q.push(node->right);
            }
            answer.push_back(tmp);
        }
	    return answer;
    }
};

int main() 
{
    std::cout << "Test done" << std::endl;
    return 0;
}