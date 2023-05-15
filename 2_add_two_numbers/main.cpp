#include <iostream>
#include <cassert>
#include <vector>

/**
 * https://leetcode.com/problems/add-two-numbers/description/
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode preHead;
        ListNode* tmp = &preHead;
        int dec = 0;
        while(l1 || l2 || 0 != dec)
        {
            int l1Val = l1 ? l1->val: 0;
            int l2Val = l2 ? l2->val: 0;
            int res = dec+l1Val + l2Val;
            dec = 0;
            if (res > 9)
            {
                dec = 1;
                res %=10;
            }
            tmp->next = new ListNode (res);
            tmp = tmp->next;
            if(l1)
                l1 = l1->next;
            
            if(l2)
                l2 = l2->next;
        }
        return preHead.next;
    }
};

int main() 
{
    std::cout << "Test done" << std::endl;
    return 0;
}