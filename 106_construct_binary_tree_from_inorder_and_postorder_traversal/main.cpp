/* Definition for a binary tree node. */
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
#include <algorithm>
#include <set>
#include <stack>
#include <cassert>

class Solution {
public:
    void deleteTree(TreeNode* root)
    {
        if (root)
        {
            deleteTree(root->left);
            deleteTree(root->right);
            delete root;
        }
    }

    std::vector<int> inOrderTraversalIter(TreeNode* root)
    {
        std::vector<int> answer;
        std::stack<TreeNode*> stack;
        while(!stack.empty() || root != nullptr)
        {
            if (nullptr != root )
            {
                stack.push(root);
                root = root->left;
            }
            else
            {
                root = stack.top();
                stack.pop();
                answer.push_back(root->val);
                root = root->right;
            }
        }        
        return answer;
    }

    std::vector<int> inOrderTraversal(TreeNode* root)
    {
        std::vector<int> answer;
        deep(answer, root);
        return answer;
    }

    void deep(std::vector<int>& answer, TreeNode *root)
    {
        if (root)
        {
            deep(answer, root->left);
            answer.push_back(root->val);
            deep(answer, root->right);
        }
    }


    TreeNode* buildTree(std::vector<int>& inOrder, std::vector<int>& postOrder) {
        return recursive(inOrder.begin(), inOrder.end(), postOrder.begin(), postOrder.end());
    }

    TreeNode* recursive( std::vector<int>::iterator inOrderedBegin, std::vector<int>::iterator inOrderedEnd,
                         std::vector<int>::iterator postorderBegin, std::vector<int>::iterator postorderEnd)
    {
        if (inOrderedBegin == inOrderedEnd || postorderBegin == postorderEnd)
            return nullptr;

        TreeNode* root = new TreeNode(*(postorderEnd-1));
        auto leftInOrderedBegin = inOrderedBegin;
        auto leftInOrderedEnd = std::find(inOrderedBegin, inOrderedEnd, root->val);
        std::set<int> left(leftInOrderedBegin, leftInOrderedEnd);

        std::vector<int>::iterator leftPostOrderEnd;
        for(auto it = postorderBegin, endIt = postorderEnd; it != endIt; it++)
        {
            if (!left.empty())
            {
                left.erase(*it);
            }
            else
            {
                leftPostOrderEnd = it;
                break;
            }
        }        
        auto leftPostOrderBegin = postorderBegin;
        root->left  = recursive(leftInOrderedBegin, leftInOrderedEnd, leftPostOrderBegin, leftPostOrderEnd);
        auto rightInOrderedBegin = leftInOrderedEnd+1;
        auto rightInOrderedEnd   = inOrderedEnd;
        auto rightPostOrderBegin = leftPostOrderEnd;
        auto rightPostOrderEnd   = postorderEnd-1;
        root->right = recursive(rightInOrderedBegin, rightInOrderedEnd, rightPostOrderBegin, rightPostOrderEnd);

        return root;
    }
};

template<typename T>
std::ostream& operator<<(std::ostream &out, std::vector<T> vector)
{
    bool first = true;
    for(auto &val: vector)
    {
        if (!first)
            std::cout << " ";
        first = false;
        std::cout << val;
    }
    std::cout << std::endl;
    return out;
}

int main() {
    Solution a;
    std::vector<int> inOrder ={9,3,15,20,7}, postorder = {9,15,7,20,3};
    auto tree = a.buildTree(inOrder, postorder);
    auto answer = a.inOrderTraversal(tree);
    auto answerIter = a.inOrderTraversalIter(tree);
    assert(inOrder == answer);
    assert(inOrder == answerIter);
    a.deleteTree(tree);
    std::cout << "Test done" << std::endl;
    return 0;
}