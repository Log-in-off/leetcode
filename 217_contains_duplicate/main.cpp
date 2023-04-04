#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>

class Solution {
public:
    /*bool containsDuplicate(vector<int>& nums) {
        std::set<int> buff(nums.begin(), nums.end());
        return nums.size() != buff.size();
    }
    */
    bool containsDuplicate(std::vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        int last = nums[0];
        for(int i = 1; i < nums.size(); i++)
        {
            if (last!=nums[i])
                last=nums[i];
            else
                return true;
        }
        return false;
    }
};

int main() 
{
    Solution a;
    {
        std::vector<int> nums={1,2,3,1};
        bool answer = true;
        assert(answer == a.containsDuplicate(nums));
    }
    {
        std::vector<int> nums={1,2,3,4};
        bool answer = false;
        assert(answer == a.containsDuplicate(nums));
    }
    std::cout << "Test done" << std::endl;
    return 0;
}