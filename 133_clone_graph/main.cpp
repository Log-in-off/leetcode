#include <iostream>
#include <cassert>
#include <vector>
#include <unordered_map>

/*
// Definition for a Node.
*/
class Node {
public:
    int val;
    std::vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = std::vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = std::vector<Node*>();
    }
    Node(int _val, std::vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};


class Solution {
    Node* dfs(Node* node, std::unordered_map<Node*, Node*> &visited)
    {
        if (!node)
            return nullptr;

        Node* tmp;
        if (visited.find(node) == visited.end())
        {
            tmp = new Node (node->val);
            visited[node] = tmp;
        }
        else
        {
            return visited[node];
        }
        for(auto nod:node->neighbors)
        {
            auto t = dfs(nod, visited);
            tmp->neighbors.push_back(t);
        }
        return tmp;
    }
public:
    Node* cloneGraph(Node* node) {
        std::unordered_map<Node*, Node*> visited;
        return dfs(node, visited);        
    }
};

int main() 
{
    std::cout << "Test done" << std::endl;
    return 0;
}