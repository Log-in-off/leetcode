#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>

class Solution {
    void backtrack(std::vector<int>& nums, int start, std::vector<int>& cur, std::vector<std::vector<int>>& answer) {
        if (start == nums.size())
        {
            answer.push_back(cur);
            return;
        }
       
        cur.push_back(nums[start]);
        backtrack(nums, start +1, cur, answer);
        cur.pop_back();

        while(start + 1 < nums.size() && nums[start] == nums[start+1])
        {
            start++;
        }
        backtrack(nums, start +1, cur, answer);
    }
public:
    std::vector<std::vector<int>> subsetsWithDup(std::vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        std::vector<int> cur;
        std::vector<std::vector<int>> answer;
        backtrack(nums, 0, cur, answer);
        return answer;
    }
};

int main() 
{
    Solution a;
    {
        std::vector<int> nums = {1,2,2};
        std::vector<std::vector<int>> answer = {{1,2,2},{1,2},{1},{2,2},{2},{}};
        assert(answer == a.subsetsWithDup(nums));
    }
    {
        std::vector<int> nums = {0};
        std::vector<std::vector<int>> answer = {{0},{}};
        assert(answer == a.subsetsWithDup(nums));
    }
    std::cout << "Test done" << std::endl;
    return 0;
}