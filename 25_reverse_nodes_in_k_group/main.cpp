#include <iostream>
#include <cassert>
#include <vector>

/**
 * https://leetcode.com/problems/reverse-nodes-in-k-group/description/
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
    ListNode* revers(ListNode* head, ListNode* end)
    {
        ListNode* tmp = nullptr;
        while(head!= end)
        {
            ListNode* t = head;
            head = head->next;
            t->next = tmp;
            tmp = t;
        }
        return tmp;        
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode tmpHead;
        tmpHead.next = head;
        ListNode* preTmp = &tmpHead;
        while(true)
        {
            ListNode* start = head;
            for(int i = 0; i < k; i++)
            {
                if (head)
                    head = head->next;
                else
                {
                    preTmp->next = start;
                    return tmpHead.next;
                }
            }
            preTmp->next = revers(start, head);
            preTmp = start;
        }
    }
};

int main() 
{
    std::cout << "Test done" << std::endl;
    return 0;
}