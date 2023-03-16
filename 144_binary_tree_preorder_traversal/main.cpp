/*Definition for a binary tree node.*/
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
#include <stack>
class Solution {
public:
    std::vector<int> preorderTraversal(TreeNode* root) {
        std::vector<int> answer;
        deep(root, answer);
        return answer;        
    }
    void deep(TreeNode* root, std::vector<int>& answer)
    {
        if(root)
        {
            answer.push_back(root->val);
            deep(root->left, answer);
            deep(root->right, answer);
        }
    }

    std::vector<int> preorderTraversalIter(TreeNode* root) {
        std::vector<int> answer;
        std::stack<TreeNode*> stack;
        stack.push(root);
        while(!stack.empty())
        {
            auto top = stack.top();
            stack.pop();
            if(top)
            {
                answer.push_back(top->val);
                stack.push(top->right);
                stack.push(top->left);            
            }
        }
        return answer;
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
        if (node.val != INT32_MIN)
        {
            if(index < tree.size() && tree[index].val != INT32_MIN)
                node.left = &tree[index];
            index++;

            if(index < tree.size() && tree[index].val != INT32_MIN)
                node.right = &tree[index];
            index++;
        }
    }
    return tree;
}

std::ostream& operator<< (std::ostream &out, std::vector<int> &vec)
{
    bool first = true;
    for (auto value:vec)
    {
        if(!first)
            out << " ";
        first = false;
        out << value;
    }
    out << std::endl;
    return out;
}

#include <cassert>
int main()
{
    Solution a;
    std::vector<int> test1 = {1,INT32_MIN,2,3};
    std::vector<TreeNode> tree1 = makeTree(test1);
    std::vector<int> answer1 = {1, 2, 3};
    auto vec1 = a.preorderTraversal(&tree1.front());
    std::cout << vec1;
    assert(answer1 == vec1);

    auto vec1It = a.preorderTraversalIter(&tree1.front());
    std::cout << vec1It;
    assert(answer1 == vec1It);
    
    std::cout << "Test done" << std::endl;
    return 0;
}