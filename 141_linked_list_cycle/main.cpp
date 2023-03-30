#include <iostream>
#include <cassert>
#include <vector>

/**
 * Definition for singly-linked list.
 */ 
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };
 
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (!head)
            return false;
        ListNode* nextOneStep = head;
        ListNode* nextTwoStep = head;
        nextTwoStep = nextTwoStep->next;
        while(nextTwoStep)
        {
            if(nextOneStep == nextTwoStep)
                return true;
            
            nextOneStep = nextOneStep->next;
            for(int i = 0; i < 2; i++)
            {
                if (nextTwoStep)
                    nextTwoStep = nextTwoStep->next;
            }            
        }
        return false;
    }
};

/**
 * @brief Make list with a set way
 * @param indexes index next elements for i node
 * @example [1, 2, 3] the element with index 0 points to the element with index 1, 
 *                    the element with index 1 points to the element with index 2, etc
 *                    this list doesn't have a cycle
 * @example [1, 2, 3, 1] the element with index 0 points to the element with index 1,
 *                       the element with index 1 points to the element with index 2,
 *                       the element with index 2 points to the element with index 3,
 *                       the element with index 3 points to the element with index 1 => this is a cycle
 * @note value INT32_MAX for a case when we don't want to set value for field next
 *       like for a case a list with one element
*/
std::vector<ListNode> makeList(std::vector<int> indexes)
{
    std::vector<ListNode> list(indexes.size(), {0});
    for(int i = 0; i < indexes.size(); i++)
    {
        if (INT32_MAX != indexes[i])
            list[i].next = &list[indexes[i]];
    }
    return list;
}

int main() 
{
    Solution a;
    {
        auto head = makeList({1, 2, 3, 1});
        assert(true == a.hasCycle(&head.front()));
    }
    {
        auto head = makeList({1, 0});
        assert(true == a.hasCycle(&head.front()));
    }
    {
        auto head = makeList({INT32_MAX});
        assert(false == a.hasCycle(&head.front()));
    }
    std::cout << "Test done" << std::endl;
    return 0;
}