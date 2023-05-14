#include <iostream>
#include <cassert>
#include <vector>

/**
 * https://leetcode.com/problems/copy-list-with-random-pointer/description/
 * Definition for a Node.
 */
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};


class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head)
            return head;
        std::unordered_map<Node*, Node*> buff;
        Node preHead(0);
        Node* tmp = &preHead;
        while(head)
        {
            Node* node = nullptr;
            auto it = buff.find(head);
            if (it == buff.end())
            {
                node = new Node (head->val);
                buff[head] = node;
            }
            else
            {
                node = it->second;
            }
            
            if (head->random)
            {
                it = buff.find(head->random);
                if (it == buff.end())
                {
                    node->random = new Node (head->random->val);
                    buff[head->random] = node->random;
                }
                else
                {
                    node->random = it->second;
                }
            }
            tmp->next = node;        
            head = head->next;
            tmp = node;
        }
        return preHead.next;
    }
};

int main() 
{
    std::cout << "Test done" << std::endl;
    return 0;
}