/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

#include <vector>
#include <iostream>
class Solution {
public:
    bool isCompleteTree(TreeNode* root) {
        std::vector<TreeNode*> buff;
        buff.push_back(root);
        putNodes(buff);
        bool answer = true;
        bool isLastValueFalse = false;
        for(auto node: buff)
        {
            if (node == nullptr)
            {
                isLastValueFalse = true;
            }
            else if (isLastValueFalse)
            {
                answer = false;
                break;
            }
        }
        return answer;        
    }
    void putNodes(std::vector<TreeNode*>& buff)
    {
        uint32_t index = 0;
        while(index < buff.size())
        {
            auto root = buff[index];
            if (nullptr != root)
            {
                buff.push_back(root->left);
                buff.push_back(root->right);
            }
            index++;
        }        
    }
};

std::vector<TreeNode> makeTree(std::vector<int> &nodes)
{
    std::vector<TreeNode> tree;
    for(auto node:nodes)
    {
        tree.emplace_back(node);
    }

    uint32_t index = 1;
    for(auto & node: tree)
    {   
        if(index < tree.size() && tree[index].val != INT32_MIN)
            node.left = &tree[index];
        index++;

        if(index < tree.size() && tree[index].val != INT32_MIN)
            node.right = &tree[index];
        index++;
    }
    return tree;
}

#include <cassert>
int main()
{
    Solution a;
    std::vector<int> test1 = {1,2,3,4,5,6};
    std::vector<TreeNode> tree1 = makeTree(test1);
    assert(true == a.isCompleteTree(&tree1.front()));

    /* I use INT32_MIN for a case like this [1,2,3,4,5,null,7] */
    std::vector<int> test2 = {1,2,3,4,5,INT32_MIN,7};
    std::vector<TreeNode> tree2 = makeTree(test2);
    assert(false == a.isCompleteTree(&tree2.front()));
    std::cout << "Test done" << std::endl;
    return 0;
}