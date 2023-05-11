#include <iostream>
#include <cassert>
#include <vector>

/**
 * https://leetcode.com/problems/merge-two-sorted-lists/description/
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    	ListNode* answer = {};
    	if(list1 && list2)
    	{
    		if(list1->val < list2->val)
    		{
    			answer = list1;
    			list1 = list1->next;
    		}
    		else
    		{
    			answer = list2;
    			list2 = list2->next;
    		}
    	}
    	else if (list1)
    		return list1;
    	else
    		return list2;
    		
    	ListNode* tmp = answer;
        while (list1 || list2)
        {
        	if (list1 && list2)
        	{
        		if (list1->val < list2->val)
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
        	else if (list1)
        	{
        		tmp->next = list1;
        		break;
		}
		else
		{
			tmp->next = list2;
			break;
		}
        }
        return answer;
    }
};

int main() 
{
    std::cout << "Test done" << std::endl;
    return 0;
}