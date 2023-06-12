#include <iostream>
#include <cassert>
#include <vector>

/**
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
    bool isSameTree(TreeNode* p, TreeNode* q) {
  	if ((p == nullptr) ^ (q == nullptr))
  		return false;
  	
  	if (!p)
  		return true;
  	
  	if (p->val != q->val)
  		return false;
  	
  	return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};

int main() 
{
    std::cout << "Test done" << std::endl;
    return 0;
}