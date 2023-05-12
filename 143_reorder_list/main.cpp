#include <iostream>
#include <cassert>
#include <vector>

/**
 * https://leetcode.com/problems/reorder-list/description/
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
    ListNode* reversList(ListNode* head)
    {
        ListNode* newHead = nullptr;
        while(head)
        {
            ListNode* next = head->next;
            head->next = newHead;
            newHead = head;
            head = next;
        }
        return newHead;
    }
public:
    void reorderList(ListNode* head) {
        if(!head || !head->next || !head->next->next)
            return;
        ListNode* oneS = head;
        ListNode* twoS = head;
        ListNode* tmp;
        while(twoS)
        {
            tmp = oneS;
            oneS = oneS->next;
            for(int i = 0; i < 2; i++)
                if(twoS)
                    twoS = twoS->next;
        }
        tmp->next = nullptr;
        ListNode* newList = reversList(oneS);
        while(newList)
        {
            tmp = head->next;
            head->next = newList;
            newList = newList->next;
            head->next->next = tmp;
            head = tmp;
        }
    }
};

int main() 
{
    std::cout << "Test done" << std::endl;
    return 0;
}