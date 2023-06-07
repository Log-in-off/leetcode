#include <iostream>
#include <cassert>
#include <vector>
#include <deque>

/*
https://leetcode.com/problems/sliding-window-maximum/
*/

class Solution {
public:
    std::vector<int> maxSlidingWindow(std::vector<int>& nums, int k) {
        std::vector<int> answer;
        std::deque<int> deq;
        int l = 0, r = 0;
        while(r < nums.size())
        {
            while(!deq.empty() && nums[deq.back()] < nums[r]) {
                deq.pop_back();
            }

            deq.push_back(r);

            if (l > deq.front())
                deq.pop_front();

            if (r +1 >= k)
            {
                answer.push_back(nums[deq.front()]);
                l++;
            }
            r++;
        }
        return answer;
    }
};

int main() 
{
    Solution a;
    {
        std::vector<int> nums = {1,3,-1,-3,5,3,6,7};
        int k = 3;
        std::vector<int> answer = {3,3,5,5,6,7};
        assert(answer == a.maxSlidingWindow(nums, k));
    }
    {
        std::vector<int> nums = {1};
        int k = 1;
        std::vector<int> answer = {1};
        assert(answer == a.maxSlidingWindow(nums, k));
    }
    {
        std::vector<int> nums = {1,3,1,2,0,5};
        int k = 3;
        std::vector<int> answer = {3,3,2,5};
        assert(answer == a.maxSlidingWindow(nums, k));
    }
    
    
    std::cout << "Test done" << std::endl;
    return 0;
}