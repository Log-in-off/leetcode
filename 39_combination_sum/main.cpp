#include <iostream>
#include <cassert>
#include <vector>

/*
https://leetcode.com/problems/combination-sum/description/
*/

class Solution {
    void dp(std::vector<int>& candidates, int target, std::vector<int>& tmp, int start, int sum, std::vector<std::vector<int>> &answer)
    {
        if (sum > target)
            return;

        if(sum == target)
        {
            answer.push_back(tmp);
            return;
        }
        for(int i = start; i < candidates.size(); i++)
        {
            tmp.push_back(candidates[i]);
            dp(candidates, target, tmp, i, sum + candidates[i], answer);
            tmp.pop_back();
        }
    }
public:
    std::vector<std::vector<int>> combinationSum(std::vector<int>& candidates, int target) {
        std::vector<int> tmp;
        std::vector<std::vector<int>> answer;
        //std::sort(candidates.begin(), candidates.end());
        dp(candidates, target, tmp, 0, 0, answer);
        return answer;              
    }
};

int main() 
{
    Solution a;
    {
        std::vector<int> candidates = {2,3,6,7};
        int target = 7;
        std::vector<std::vector<int>> answer = {{2,2,3},{7}};
        assert(answer == a.combinationSum(candidates, target));
    }
    {
        std::vector<int> candidates = {2,3,5};
        int target = 8;
        std::vector<std::vector<int>> answer = {{2,2,2,2},{2,3,3},{3,5}};
        assert(answer == a.combinationSum(candidates, target));
    }
    {
        std::vector<int> candidates = {2};
        int target = 1;
        std::vector<std::vector<int>> answer = {};
        assert(answer == a.combinationSum(candidates, target));
    }
    std::cout << "Test done" << std::endl;
    return 0;
}