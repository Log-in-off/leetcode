#include <iostream>
#include <cassert>
#include <vector>
#include <unordered_set>
/**
 * Definition for singly-linked list.
*/
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

/*trivial*/
#if 0
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        std::unordered_set<ListNode *> buff;
        while (head)
        {
            if(buff.end() != buff.find(head))
            {
                return head;
            }
            buff.insert(head);
            head = head->next;
        }
        return nullptr;
    }
};
#endif

/*low mem, but big time*/
#if 0
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(!head)
            return nullptr;

        ListNode* oneStep = head;
        ListNode* twoStep = head->next;
        while (twoStep)
        {
            if (twoStep == oneStep)
                break;

            oneStep = oneStep->next;
            for(int i = 0; i < 2; i++)
            {
                if (twoStep)
                    twoStep = twoStep->next;
            }
        }
        if (!twoStep)
            return nullptr;
        
        if (oneStep == oneStep->next)
            return oneStep;
        

        twoStep = twoStep->next;
        while(head!=twoStep && head != oneStep)
        {
            while(twoStep!=oneStep && twoStep != head)
                twoStep = twoStep->next;
            
            if (twoStep == head)
                break;

            twoStep = twoStep->next;
            head=head->next;
        }
        return head;
    }
};
#endif

/*optimal*/
#if 1
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (!head)
            return nullptr;
        ListNode* oneStep = head;
        ListNode* twoStep = head->next;
        while(twoStep)
        {
            if (oneStep == twoStep)
                break;

            oneStep=oneStep->next;
            for(int i = 0; i <2; i++)
            {
                if (twoStep)
                    twoStep = twoStep->next;
            }
        }
        if (!twoStep)
            return nullptr;
        
        std::unordered_set<ListNode*> buff;
        buff.insert(twoStep);
        twoStep = twoStep->next;

        while(twoStep!=oneStep)
        {
            buff.insert(twoStep);
            twoStep = twoStep->next;
        }

        while(true)
        {
            if (buff.find(head) == buff.end())
                head = head->next;
            else
                break;
        }
        return head;
    }
};
#endif

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
        assert(&head[1] == a.detectCycle(&head.front()));
    }
    {
        auto head = makeList({1, 0});
        assert(&head[0] == a.detectCycle(&head.front()));
    }
    {
        auto head = makeList({INT32_MAX});
        assert(nullptr == a.detectCycle(&head.front()));
    }
    std::cout << "Test done" << std::endl;
    return 0;
}