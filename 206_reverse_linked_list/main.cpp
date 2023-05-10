#include <iostream>
#include <cassert>
#include <vector>

/**
 * https://leetcode.com/problems/reverse-linked-list/description/
 * Definition for singly-linked list.
 */ 
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* newHead = nullptr;
        while(head)
        {
            ListNode* tmp = head->next;
            head->next = newHead;
            newHead = head;
            head = tmp;
        }
        return newHead;
    }
};

int main() 
{
    std::cout << "Test done" << std::endl;
    return 0;
}