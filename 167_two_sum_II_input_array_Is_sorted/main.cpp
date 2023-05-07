#include <iostream>
#include <cassert>
#include <vector>

/*
https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/description/
*/

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& numbers, int target) {
        int start = 0, end = numbers.size()-1;
        while(start<end)
        {
            if (numbers[start]+numbers[end] == target)
            {
                break;
            }
            else if (numbers[start]+numbers[end] > target)
                end--;
            else
                start++;
        }
        return {start+1, end+1};
    }
};

int main() 
{
    Solution a;
    {
        std::vector<int> numbers = {2,7,11,15};
        int target = 9;
        std::vector<int> answer = {1,2};
        assert(answer == a.twoSum(numbers, target));
    }
    {
        std::vector<int> numbers = {2,3,4};
        int target = 6;
        std::vector<int> answer = {1, 3};
        assert(answer == a.twoSum(numbers, target));
    }
    {
        std::vector<int> numbers = {-1,0};
        int target = -1;
        std::vector<int> answer = {1,2};
        assert(answer == a.twoSum(numbers, target));
    }
    std::cout << "Test done" << std::endl;
    return 0;
}