#include <iostream>
#include <cassert>
#include <vector>
#include <unordered_map>
#include <map>
/*
https://leetcode.com/problems/top-k-frequent-elements/description/
*/
class Solution {
public:
    std::vector<int> topKFrequent(std::vector<int>& nums, int k) {
        std::unordered_map<int, int> freq;
        for(auto num:nums)
        {
            freq[num]++;
        }
        std::map<int, std::vector<int>> max;
        for(auto &value:freq)
        {
            max[value.second].push_back(value.first);
        }
        std::vector<int> answer;
        for(auto rIt = max.rbegin(); rIt != max.rend(); rIt++)
        {
            for(auto value:rIt->second)
            {
                if (k > 0)
                {
                    answer.push_back(value);
                    k--;
                }
                else                
                    break;
            }
        }
        return answer;        
    }
};

/*
Example 1:
Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]

Example 2:
Input: nums = [1], k = 1
Output: [1]
*/

int main() 
{
    Solution a;
    {
        std::vector<int> nums = {1,1,1,2,2,3};
        int k = 2;
        std::vector<int> answer = {1, 2};
        assert(answer == a.topKFrequent(nums, k));
    }
    {
        std::vector<int> nums = {1};
        int k = 1;
        std::vector<int> answer = {1};
        assert(answer == a.topKFrequent(nums, k));
    }
    std::cout << "Test done" << std::endl;
    return 0;
}