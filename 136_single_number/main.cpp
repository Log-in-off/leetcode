#include <iostream>
#include <cassert>
#include <vector>

class Solution {
public:
    int singleNumber(std::vector<int>& nums) {
        int answer = 0;
        for(auto var: nums)
            answer ^= var;
        return answer;
    }
    
};

int main() 
{
    Solution a;
    {
        std::vector<int> nums = {2,2,1};
        int answer = 1;
        assert(answer == a.singleNumber(nums));
    }
    {
        std::vector<int> nums = {4,1,2,1,2};
        int answer = 4;
        assert(answer == a.singleNumber(nums));
    }
    {
        std::vector<int> nums = {1};
        int answer = 1;
        assert(answer == a.singleNumber(nums));
    }
    {
        std::vector<int> nums = {-4,1,-2,1,-2};
        int answer = -4;
        assert(answer == a.singleNumber(nums));
    }
    std::cout << "Test done" << std::endl;
    return 0;
}