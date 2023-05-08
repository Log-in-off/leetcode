#include <iostream>
#include <cassert>
#include <vector>
#include <tuple>
#include <set>
#include <algorithm>

/*
https://leetcode.com/problems/3sum/description/
*/

class Solution {
public:
    std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
        std::vector<std::vector<int>> answer;
        const int n = nums.size();
        if (n < 3) {
            return answer;
        }
        std::sort(nums.begin(), nums.end());
        for(int first = 0; first < n-2; first++)
        {
            if (nums[first] > 0) {
                break;
            }
            if (first > 0 && nums[first - 1] == nums[first]) {
                continue;
            }

        	int start = first+1, end = n-1;

        	while(start < end)
        	{
        		if(nums[first] + nums[start] + nums[end] == 0)
        		{
                    answer.push_back({nums[first], nums[start], nums[end]});
                    while (start < end && nums[start] == nums[start + 1]) {
                        start++;
                    }
                    start++;

                    while (start < end && nums[end-1] == nums[end]) {
                        end--;
                    }
                    end--;
        		}
        		else if (nums[first] + nums[start] + nums[end] > 0) {
        			end--;
        		}
        		else {
        			start++;
        		}
        	}
        }
        return answer;
    }
};

int main() 
{
    Solution a;
    {
        std::vector<int> nums = {-1,0,1,2,-1,-4};
        std::vector<std::vector<int>> res = a.threeSum(nums);
        std::vector<std::vector<int>> answer = {{-1,-1,2},{-1,0,1}};
        assert(res == answer);
    }
    {
        std::vector<int> nums = {0,1,1};
        std::vector<std::vector<int>> res = a.threeSum(nums);
        std::vector<std::vector<int>> answer = {};
        assert(res == answer);
    }
    {
        std::vector<int> nums = {0,0,0};
        std::vector<std::vector<int>> res = a.threeSum(nums);
        std::vector<std::vector<int>> answer = {{0, 0, 0}};
        assert(res == answer);
    }
    std::cout << "Test done" << std::endl;
    return 0;
}