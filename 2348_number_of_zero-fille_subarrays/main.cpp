#include <iostream>
#include <vector>
#include <cassert>
#define WATCH(x) std::cout << (#x) << " = " << (x) << std::endl;

class Solution {
public:
    long long zeroFilledSubarray(std::vector<int>& nums) {
        std::vector<int>::iterator lh = nums.begin();
        std::vector<int>::iterator rh = nums.begin();
        long long n;
        long long answer = 0;
        while(rh != nums.end())
        {
            if (0 != *lh)
            {
                lh++;
                rh++;
            }
            else
            {
                if (0 == *rh)
                {
                    rh++;
                }
                else
                {
                    n = std::distance(lh, rh);
                    answer += (n*(n+1))/2;
                    rh++;
                    lh = rh;
                }
            }
        }
        if (nums.end() != lh && 0 == *lh)
        {
            n = std::distance(lh, rh);
            answer += (n*(n+1))/2;    
        }

        return answer;
    }
};

/*
Example 1:

Input: nums = [1,3,0,0,2,0,0,4]
Output: 6
Explanation: 
There are 4 occurrences of [0] as a subarray.
There are 2 occurrences of [0,0] as a subarray.
There is no occurrence of a subarray with a size more than 2 filled with 0. Therefore, we return 6.
Example 2:

Input: nums = [0,0,0,2,0,0]
Output: 9
Explanation:
There are 5 occurrences of [0] as a subarray.
There are 3 occurrences of [0,0] as a subarray.
There is 1 occurrence of [0,0,0] as a subarray.
There is no occurrence of a subarray with a size more than 3 filled with 0. Therefore, we return 9.
Example 3:

Input: nums = [2,10,2019]
Output: 0
Explanation: There is no subarray filled with 0. Therefore, we return 0.
*/
int main() {
    Solution a;
    {
        std::vector<int> nums = {1,3,0,0,2,0,0,4};
        long long answer = 6;
        assert(answer == a.zeroFilledSubarray(nums));
    }

    {
        std::vector<int> nums = {0,0,0,2,0,0};
        long long answer = 9;
        assert(answer == a.zeroFilledSubarray(nums));
    }

    {
        std::vector<int> nums = {2,10,2019};
        long long answer = 0;
        assert(answer == a.zeroFilledSubarray(nums));
    }
    std::cout << "Test done" << std::endl;
    return 0;
}