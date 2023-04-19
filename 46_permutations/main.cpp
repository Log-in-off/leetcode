#include <iostream>
#include <cassert>
#include <vector>
#include <unordered_set>

/*
https://leetcode.com/problems/permutations/description/
*/

#if 0
class Solution {
public:
    std::vector<std::vector<int>> permute(std::vector<int>& nums) {
        std::vector<std::vector<int>> result;
        dfs(nums, 0, result);
        return result;
    }
private:
    void dfs(std::vector<int>& nums, int start, std::vector<std::vector<int>>& result) {
        if (start == nums.size()) {
            result.push_back(nums);
            return;
        }
        for (int i = start; i < nums.size(); i++) {
            std::swap(nums[i], nums[start]);
            dfs(nums, start + 1, result);
            std::swap(nums[i], nums[start]);
        }
    }
};
#endif

/*my solution*/
#if 1
class Solution {
    void dp(std::vector<int>& nums, std::unordered_set<int> &use, std::vector<int> &tmp,  std::vector<std::vector<int>>& answer)
    {
        if (tmp.size() == nums.size())
        {
            answer.push_back(tmp);
            return;
        }

        for(int i = 0; i < nums.size(); i++)
        {
            if (use.find(i) == use.end())
            {
                use.insert(i);
                tmp.push_back(nums[i]);
                dp(nums, use, tmp, answer);
                tmp.pop_back();
                use.erase(i);
            }
        }
    }
public:
    std::vector<std::vector<int>> permute(std::vector<int>& nums) {
        std::vector<std::vector<int>> answer;
        std::unordered_set<int> use;
        std::vector<int> tmp;
        dp(nums, use, tmp, answer);
        return answer;
    }
};
#endif

/**
 * @note different solutions return answers with different orders vectors 
*/
int main() 
{
    Solution a;
    {
        std::vector<int> nums = {1,2,3};
        std::vector<std::vector<int>> answer = {{1,2,3},{1,3,2},{2,1,3},{2,3,1},{3,1,2},{3,2,1}};
        assert(answer == a.permute(nums));
    }
    {
        std::vector<int> nums = {0,1};
        std::vector<std::vector<int>> answer = {{0,1},{1,0}};
        assert(answer == a.permute(nums));
    }
    {
        std::vector<int> nums = {1};
        std::vector<std::vector<int>> answer = {{1}};
        assert(answer == a.permute(nums));
    }
    std::cout << "Test done" << std::endl;
    return 0;
}