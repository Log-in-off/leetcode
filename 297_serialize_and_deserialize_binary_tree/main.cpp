#include <iostream>
#include <cassert>
#include <vector>
#include <sstream>
#include <queue>


/**
 * https://leetcode.com/problems/serialize-and-deserialize-binary-tree/
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/**
 * Codec trees, that is used the LeetCode for its tasks.
 * TODO: finish deserialize
*/
class CodecLeetCode {
public:
    std::string serialize(TreeNode* root) {
        std::vector<std::string> values;
        std::queue<TreeNode*> que;
        que.push(root);
        while(!que.empty()) {
            int count = que.size();
            for(int i =0; i < count; i++) {
                TreeNode* node = que.front();
                que.pop();
                if(node) {
                    values.push_back(std::to_string(node->val));
                    que.push(node->left);
                    que.push(node->right);
                }
                else {
                    values.push_back("null");
                }
            }
        }
        while(values.back() == "null")
            values.pop_back();

        std::string answer = {"["};
        bool first = true;
        for(auto t: values) {
            if (!first)
                answer += ", ";
            first = false;
            answer += t;
        }

        answer += "]";
        return answer;
    }

    TreeNode* deserialize(std::string data) {
        std::string dat = data.substr(1, data.size()-2);
        return nullptr;
    }
};

class Codec {
    void encoder(TreeNode* root, std::ostringstream& output)
    {
        if (!root)
        {
            output << "N ";
            return;
        }

        output << root->val << " ";
        encoder(root->left, output);
        encoder(root->right, output);
    }
    TreeNode* decoder(std::istringstream& input)
    {
        std::string st;
        input >> st;
        if (st == "N")
            return nullptr;
        
        TreeNode* node = new TreeNode (std::stoi(st));
        node->left = decoder(input);
        node->right = decoder(input);
        return node;
    }
public:

    // Encodes a tree to a single string.
    std::string serialize(TreeNode* root) {
        std::ostringstream output;
        encoder(root, output);
        return output.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(std::string data) {
        std::istringstream input(data);
        return decoder(input);
    }
};

int main() 
{
    std::cout << "Test done" << std::endl;
    return 0;
}