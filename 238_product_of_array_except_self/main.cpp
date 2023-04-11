#include <iostream>
#include <cassert>
#include <vector>
/*
https://leetcode.com/problems/product-of-array-except-self/description/
*/

/*trivial O(n^2)*/
#if 0
class Solution {
public:
    std::vector<int> productExceptSelf(std::vector<int>& nums) {
    std::vector<int> answer(nums.size(), 1);
    for (int i = 0; i < nums.size(); i++)
    {
        for(int j = 0; j < answer.size();j++)
        {
            if (j != i)
                answer[j]*=nums[i];
        }
    }
    return answer;        
    }
};
#endif
/*the right solution with O(n) and without a division */
#if 0
class Solution {
public:
    std::vector<int> productExceptSelf(std::vector<int>& nums) {
    int size = nums.size();
    std::vector<int> leftProduct(size, 1);
    std::vector<int> rightProduct(size, 1);
    for(int i = 1; i < size; i++)
    {
        leftProduct[i] = leftProduct[i-1]*nums[i-1];
        rightProduct[size-1 - i] = rightProduct[size - i]*nums[size - i];
    }

    std::vector<int> answer(size);
    for (int i = 0; i < size; i++)
    {
        answer[i] = leftProduct[i]*rightProduct[i];
    }
    return answer;

    }
};
#endif

/*update solution with lower memory*/
#if 1
class Solution {
public:
    std::vector<int> productExceptSelf(std::vector<int>& nums) {
        int n = nums.size();
        std::vector<int> rightProduct(n, 1);
        for(int i = n - 2; i >=0; i--)
        {
            rightProduct[i] = rightProduct[i+1]*nums[i+1];
        }
        int product = 1;
        std::vector<int> answer(n);
        for(int i = 0; i < n; i++)
        {
            answer[i] = product*rightProduct[i];
            product *= nums[i];
        }
        return answer;
    }
};
#endif

int main() 
{
    Solution a;
    {
        std::vector<int> nums = {1,2,3,4};
        std::vector<int> answer = {24,12,8,6};
        assert(answer == a.productExceptSelf(nums));
    }
    {
        std::vector<int> nums = {-1,1,0,-3,3};
        std::vector<int> answer = {0,0,9,0,0};
        assert(answer == a.productExceptSelf(nums));
    }
    std::cout << "Test done" << std::endl;
    return 0;
}