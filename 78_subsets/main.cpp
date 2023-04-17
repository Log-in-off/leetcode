#include <iostream>
#include <cassert>
#include <vector>

/*
https://leetcode.com/problems/subsets/description/
*/

class Solution {
    void dp(std::vector<int>& nums, int i, std::vector<std::vector<int>>& answer, std::vector<int> &tmp)
    {
        if( i == nums.size())
        {
            answer.push_back(tmp);
            return;
        }
        tmp.push_back(nums[i]);
        dp(nums, i+1, answer, tmp);
        tmp.pop_back();
        dp(nums, i+1, answer, tmp);
    }
public:
    std::vector<std::vector<int>> subsets(std::vector<int>& nums) {
        std::vector<std::vector<int>> answer;
        std::vector<int> tmp = {};
        dp(nums, 0, answer, tmp);
        return answer;
    }
};

int main() 
{
    Solution a;
    {
        std::vector<int> nums = {1,2,3};
        std::vector<std::vector<int>> answer = {{1,2,3}, {1,2}, {1,3}, {1}, {2,3}, {2}, {3}, {}};
        assert(answer == a.subsets(nums));
    }
     {
        std::vector<int> nums = {0};
        std::vector<std::vector<int>> answer = {{0}, {}};
        assert(answer == a.subsets(nums));
    }
    std::cout << "Test done" << std::endl;
    return 0;
}