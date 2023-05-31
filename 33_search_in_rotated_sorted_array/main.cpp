#include <iostream>
#include <cassert>
#include <vector>

/*
*/

class Solution {
public:
    int search(std::vector<int>& nums, int target) {
        int l = 0, r = nums.size()-1;
        while(l <=r)
        {
        	int mid = (l+r)/2;
        	if (nums[mid] == target)
        		return mid;

					if(nums[l] <= nums[mid])
					{
						if (nums[l] <= target && target <= nums[mid])
						{
							r = mid-1;
						}
						else
							l = mid+1;
					}
					else
					{
						if (nums[l] <= target || nums[mid] > target)
						{
							r = mid-1;
						}
						else
						{
							l = mid+1;
						}
					}
    }
		return -1;
	}
};

int main() 
{
    Solution a;
    {
        std::vector<int> nums = {4,5,6,7,0,1,2};
        int target = 0;
        int answer = 4;
        assert(answer == a.search(nums, target));
    }
    {
        std::vector<int> nums = {4,5,6,7,0,1,2};
        int target = 3;
        int answer = -1;
        assert(answer == a.search(nums, target));
    }
    {
        std::vector<int> nums = {1};
        int target = 0;
        int answer = -1;
        assert(answer == a.search(nums, target));
    }
    {
        std::vector<int> nums = {1,3};
        int target = 3;
        int answer = 1;
        assert(answer == a.search(nums, target));
    }
    std::cout << "Test done" << std::endl;
    return 0;
}