#include <iostream>
#include <cassert>
#include <vector>

/**
 * https://leetcode.com/problems/merge-k-sorted-lists/description/
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
	ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
		ListNode head;
		ListNode* tmp = &head;
		
		while(list1  && list2)
		{
			if(list1->val < list2->val)
			{
				tmp->next = list1;
				list1 = list1->next;
			}
			else
			{
				tmp->next = list2;
				list2 = list2->next;
			}
			tmp = tmp->next;
		}
		
		if(list1)
			tmp->next=list1;
		if(list2)
			tmp->next=list2;
		return head.next;
	}
public:
    ListNode* mergeKLists(std::vector<ListNode*>& lists) {
    	int n = lists.size();
			if (n == 0) {
            return nullptr;
      }
    	while(n > 1)
    	{
        	for(int i = 0; i < n/2; i++)
        	{
        		lists[i] = mergeTwoLists(lists[i], lists[n-i-1]);
        	}
        	n = (n+1)/2;
        }
        return lists.front();        
    }
};

int main() 
{
    std::cout << "Test done" << std::endl;
    return 0;
}