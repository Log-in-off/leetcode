#include <iostream>
#include <cassert>
#include <vector>

class Solution {
public:
    int search(std::vector<int>& nums, int target) {
        int start = 0;
        int end = nums.size()-1;
        int middle = (end+start)/2;
        while(start <= end)
        {
            if (nums[middle] == target)
            {
                return middle;
            }
            else if (nums[middle] < target)
            {
                start = middle + 1;
            }
            else
            {
                end = middle - 1;
            }
            middle = (end+start)/2;
        }
        return -1;
    }
};

/*
Example 1:
Input: nums = [-1,0,3,5,9,12], target = 9
Output: 4
Explanation: 9 exists in nums and its index is 4

Example 2:
Input: nums = [-1,0,3,5,9,12], target = 2
Output: -1
Explanation: 2 does not exist in nums so return -1
*/

int main() 
{
    Solution a;
    {
        std::vector<int> nums = {-1,0,3,5,9,12};
        int target = 9;
        int answer = 4;
        assert(answer == a.search(nums, target));
    }
    {
        std::vector<int> nums = {-1,0,3,5,9,12};
        int target = 2;
        int answer = -1;
        assert(answer == a.search(nums, target));
    }
    {
        std::vector<int> nums = {-1};
        int target = 2;
        int answer = -1;
        assert(answer == a.search(nums, target));
    }
    {
        std::vector<int> nums = {-1};
        int target = -1;
        int answer = 0;
        assert(answer == a.search(nums, target));
    }
    

    std::cout << "Test done" << std::endl;
    return 0;
}