#include <iostream>
#include <cassert>
#include <vector>

/*
https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/description/
*/

class Solution {
public:
    int findMin(std::vector<int>& nums) {
        int l = 0, r = nums.size()-1;
        if (nums[l] <= nums[r])
        	return nums[l];
        
        while(l<r)
        {
        	int mid = (l+r)/2;
        	if (nums[mid] < nums[r])
        		r = mid;
        	else
        		l = mid+1;
        }
        return nums[l];
    }
};

int main() 
{
    Solution a;
    {
        std::vector<int> nums = {3,4,5,1,2};
        int answer = 1;
        assert(answer == a.findMin(nums));
    }
    {
        std::vector<int> nums = {4,5,6,7,0,1,2};
        int answer = 0;
        assert(answer == a.findMin(nums));
    }
    {
        std::vector<int> nums = {11,13,15,17};
        int answer = 11;
        assert(answer == a.findMin(nums));
    }
    std::cout << "Test done" << std::endl;
    return 0;
}