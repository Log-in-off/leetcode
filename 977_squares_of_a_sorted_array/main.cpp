#include <iostream>
#include <cassert>
#include <vector>

class Solution {
public:
    std::vector<int> sortedSquares(std::vector<int>& nums) {
		std::vector<int> answer(nums.size());
		int lh = 0, rh = nums.size()-1;
		for(int i = nums.size()-1; i >= 0; i--)
		{
			if(std::abs(nums[lh]) > std::abs(nums[rh]))
			{
				answer[i] = nums[lh]*nums[lh];
				lh++;

			}
			else
			{
				answer[i] = nums[rh]*nums[rh];
				rh--;
			}
		}
		return answer;
	};
};

#if 0
class Solution {
public:
    std::vector<int> sortedSquares(std::vector<int>& nums) {
  	std::vector<int> answer(nums.size());
  	int lh = nums.size()-1, rh = UINT32_MAX;
  	for(int i = 0; i < nums.size(); i++)
  	{
  		if (nums[i] >=0)
  		{
  			rh = i;
  			lh = rh -1;
				break;
  		}
  	}
  	for(int i = 0; i <nums.size(); i++)
  	{
  		int val = 0;
  		if(lh >= 0 && rh < nums.size())
  		{
  			if(-nums[lh] < nums[rh])
  			{
  				val = nums[lh--];
  			}
  			else
  			{
  				val = nums[rh++];
  			}
  		}
  		else if (lh >=0)
  			val = nums[lh--];
  		else
  			val = nums[rh++];
  		answer[i] = val*val;
  	}
  	return answer;
    }
};
#endif
int main() 
{
    Solution a;
    {
        std::vector<int> nums =  {-4,-1,0,3,10};
        std::vector<int> answer = {0,1,9,16,100};
        assert(answer == a.sortedSquares(nums));
    }
    {
        std::vector<int> nums =  {-7,-3,2,3,11};
        std::vector<int> answer = {4,9,9,49,121};
        assert(answer == a.sortedSquares(nums));
    }
    {
        std::vector<int> nums =  {-1};
        std::vector<int> answer = {1};
        assert(answer == a.sortedSquares(nums));
    }
    {
        std::vector<int> nums =  {-5, -4, -3, -2, -1};
        std::vector<int> answer = {1, 4, 9, 16, 25};
        assert(answer == a.sortedSquares(nums));
    }
    std::cout << "Test done" << std::endl;
    return 0;
}