#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>
#include <stack>

/**
 * https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/
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
    TreeNode* build(std::vector<int>& preOrder, std::vector<int>& inOrder, int& index, int i, int j) {
        if (i > j)
            return nullptr;
        
        TreeNode* root = new TreeNode(preOrder[index]);
        auto it = std::find(inOrder.begin(), inOrder.end(), preOrder[index]);
        int split = std::distance(inOrder.begin(), it);
        index++;

        root->left = build(preOrder, inOrder, index, i, split-1);
        root->right = build(preOrder, inOrder, index, split+1, j);

        return root;
    } 
public:
    TreeNode* buildTree(std::vector<int>& preOrder, std::vector<int>& inOrder) {
        int index = 0;
        return build(preOrder, inOrder, index, 0, preOrder.size()-1);
    }

    std::vector<int> inOrderTraversalIter(TreeNode* root)
    {
        std::vector<int> answer;
        std::stack<TreeNode*> st;
        while (!st.empty() || root)
        {
            if (root)
            {
                st.push(root);
                root = root->left;
            }
            else
            {
                root = st.top();
                st.pop();
                answer.push_back(root->val);
                root = root->right;
            }
        }
        return answer;        
    }

    void deleteTree(TreeNode* root)
    {
        if (root)
        {
            deleteTree(root->left);
            deleteTree(root->right);
            delete root;
        }
    }
};

int main() 
{
    Solution a;
    {
        std::vector<int>  preOrder = {3,9,20,15,7}, inOrder ={9,3,15,20,7};
        auto tree = a.buildTree(preOrder, inOrder);
        
        assert(inOrder == a.inOrderTraversalIter(tree));
        a.deleteTree(tree);
    }
    {
        std::vector<int>  preOrder = {3,2,1,4}, inOrder ={1,2,3,4};
        auto tree = a.buildTree(preOrder, inOrder);
        assert(inOrder == a.inOrderTraversalIter(tree));
        a.deleteTree(tree);
    }
    std::cout << "Test done" << std::endl;
    return 0;
}