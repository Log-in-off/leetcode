#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>

class Solution {
public:
    int getSum(std::vector<int>& satisfaction, int size)
    {
        int sum = 0;
        int count_remove_rh = 0;
        for (int i = 0; i < size; i++)
            sum += satisfaction[i]*(size-i);
        return sum;
    }
    int maxSatisfaction(std::vector<int>& satisfaction) {
        std::sort(satisfaction.begin(), satisfaction.end(), std::greater<int>());
        if (satisfaction.front() <= 0)
            return 0;
        int size = satisfaction.size();
        int curentMax = getSum(satisfaction, size);
        while(true)
        {
            int tmpMax = getSum(satisfaction, size-1);
            if (tmpMax > curentMax)
            {
                curentMax = tmpMax;
                size--;
            }
            else
            {
                break;
            }
        }
        return curentMax;        
    }
};

/*
Example 1:
Input: satisfaction = [-1,-8,0,5,-9]
Output: 14
Explanation: After Removing the second and last dish, the maximum total like-time coefficient will be equal to (-1*1 + 0*2 + 5*3 = 14).
Each dish is prepared in one unit of time.

Example 2:
Input: satisfaction = [4,3,2]
Output: 20
Explanation: Dishes can be prepared in any order, (2*1 + 3*2 + 4*3 = 20)

Example 3:
Input: satisfaction = [-1,-4,-5]
Output: 0
Explanation: People do not like the dishes. No dish is prepared.
*/

int main() 
{
    Solution a;
    {
        std::vector<int> satisfaction = {-1,-8,0,5,-9};
        int answer = 14;
        assert(answer == a.maxSatisfaction(satisfaction));
    }
    {
        std::vector<int> satisfaction = {4,3,2};
        int answer = 20;
        assert(answer == a.maxSatisfaction(satisfaction));
    }
    {
        std::vector<int> satisfaction = {-1,-4,-5};
        int answer = 0;
        assert(answer == a.maxSatisfaction(satisfaction));
    }
    {
        std::vector<int> satisfaction = {-2,5,-1,0,3,-3};
        int answer = 35;
        assert(answer == a.maxSatisfaction(satisfaction));
    }
    {
        std::vector<int> satisfaction = {2,-2,-3,1};
        int answer = 6;
        assert(answer == a.maxSatisfaction(satisfaction));
    }
    std::cout << "Test done" << std::endl;
    return 0;
}