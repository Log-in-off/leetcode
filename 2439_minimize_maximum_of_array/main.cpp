#include <iostream>
#include <cassert>
#include <vector>
#include <map>
#include <unordered_set>
/*slow way*/
#if 0
class Solution {
public:
    int minimizeArrayValue(std::vector<int>& nums) {
        std::vector<int> indexesMax;
        while(true)
        {
            int max = nums[0];
            for(int i = 1; i < nums.size(); i++)
            {
                if (max <= nums[i])
                {
                    if (max < nums[i])
                        indexesMax.clear();
                    max = nums[i];
                    indexesMax.push_back(i);
                } 
            }
            if (nums[0] >= max)
                return nums[0];
            int ch = 0;
            for(auto index:indexesMax)
            {
                if (nums[index-1]+1<=max)
                {
                    nums[index]--;
                    nums[index-1]++;
                    ch++;
                }
            }
            if (ch!=indexesMax.size())
                return max;
        }
    }
};
#endif

class Solution {
public:
    int minimizeArrayValue(std::vector<int>& nums) {
        long long answer = 0;
        long long sum = 0;
        for(int index = 0; index < nums.size(); index++)
        {
            sum += nums[index];
            answer = std::max(answer, (sum+index)/(index+1));
        }
        return answer;
    }
};

int main() 
{
    Solution a;
    {
        std::vector<int> nums = {3,7,1,6};
        int answer = 5;
        assert(answer == a.minimizeArrayValue(nums));
    }
    {
        std::vector<int> nums = {10,1};
        int answer = 10;
        assert(answer == a.minimizeArrayValue(nums));
    }
    {
        std::vector<int> nums = {13,13,20,0,8,9,9};
        int answer = 16;
        assert(answer == a.minimizeArrayValue(nums));
    }
    {
        std::vector<int> nums = {13,13,20,0,8,9,50};
        int answer = 17;
        assert(answer == a.minimizeArrayValue(nums));
    }
    std::cout << "Test done" << std::endl;
    return 0;
}