#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<bool> kidsWithCandies(std::vector<int>& candies, int extraCandies) {
        auto max = std::max_element(candies.begin(), candies.end());
        std::vector<bool> answer;
        answer.reserve(candies.size());
        for (auto value : candies)
        {
            if (value + extraCandies >= *max)
                answer.push_back(true);
            else
                answer.push_back(false);
        }
        return answer;
    }
};

int main() 
{
    Solution a;
    {
        std::vector<int> candies = {2,3,5,1,3};
        int extraCandies = 3;
        std::vector<bool> answer = {true,true,true,false,true};
        assert(answer == a.kidsWithCandies(candies, extraCandies));
    }
    {
        std::vector<int> candies = {4,2,1,1,2};
        int extraCandies = 1;
        std::vector<bool> answer = {true,false,false,false,false};
        assert(answer == a.kidsWithCandies(candies, extraCandies));
    }
    {
        std::vector<int> candies = {12,1,12};
        int extraCandies = 1;
        std::vector<bool> answer = {true,false,true};
        assert(answer == a.kidsWithCandies(candies, extraCandies));
    }
    std::cout << "Test done" << std::endl;
    return 0;
}