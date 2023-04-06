#include <iostream>
#include <cassert>
#include <vector>
#include <set>
#include <algorithm>
#include <iterator>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::vector<int> buf= nums;
        std::sort(buf.begin(), buf.end());
        int lh = 0, rh = buf.size()-1;
        while(lh < rh)
        {
            if (buf[lh]+buf[rh]> target)
                rh--;
            else if (buf[lh]+buf[rh] < target)
                lh++;
            else
                break;
        }
        auto lIt = std::find(nums.begin(), nums.end(),buf[lh]);
        auto rIt = std::find(nums.begin(), nums.end(),buf[rh]);
        if (rIt == lIt)
            rIt = std::find(next(rIt, 1), nums.end(),buf[rh]);
        int a = std::distance(nums.begin(), lIt);
        int b = std::distance(nums.begin(), rIt);
        return {a, b};
    }
};

int main() 
{
    Solution a;
    {
        std::vector<int> nums = {2,7,11,15};
        int target = 9;
        std::vector<int> answer = {0,1};
        assert(answer == a.twoSum(nums, target));
    }
    {
        std::vector<int> nums = {3,2,4};
        int target = 6;
        std::vector<int> answer = {1,2};
        assert(answer == a.twoSum(nums, target));
    }
    {
        std::vector<int> nums = {3,3};
        int target = 6;
        std::vector<int> answer = {0,1};
        assert(answer == a.twoSum(nums, target));
    }
    std::cout << "Test done" << std::endl;
    return 0;
}