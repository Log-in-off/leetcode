#include <iostream>
#include <cassert>
#include <vector>

/*
https://leetcode.com/problems/find-the-duplicate-number/description/
*/

class Solution {
public:
    int findDuplicate(std::vector<int>& nums) {
    	int slow = nums[0];
			int fast = nums[nums[0]];
			while(fast!=slow)
			{
				fast = nums[nums[fast]];
				slow = nums[slow];
			}
			slow = 0;
			while(slow != fast)
			{
				slow = nums[slow];
				fast = nums[fast];
			}
			return slow;
    }
};

int main() 
{
    Solution a;
    {
        std::vector<int> nums = {1,3,4,2,2};
        int answer = 2;
        assert(answer == a.findDuplicate(nums));
    }
    {
        std::vector<int> nums = {3,1,3,4,2};
        int answer = 3;
        assert(answer == a.findDuplicate(nums));
    }

    std::cout << "Test done" << std::endl;
    return 0;
}