#include <iostream>
#include <cassert>
#include <vector>

/*
https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/
*/

/**
 * A trivial solution
*/
#if 0
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty())
            return 0;
        int min = prices[0], max = prices[0];
        int answer = 0;
        int last = prices[0];
        for(int i = 1; i < prices.size(); i++)
        {
            if (prices[i] > last)
            {
                if (prices[i] > max)
                {
                    max = prices[i];
                    answer = std::max(answer, max-min);
                }
            }
            else if (prices[i] < last)
            {
                if (prices[i] < min)
                {
                    min = max = prices[i];
                }
            }
            last = prices[i];
        }
        return answer;
    }
};
#endif

/**
 * The two point solution (sliding window)
*/
#if 1
class Solution {
public:
    int maxProfit(std::vector<int>& prices) {
        int maxP = 0, l = 0, r = 0;
        while(r < prices.size())
        {
            if(prices[l]< prices[r])
            {
                maxP = std::max(maxP, prices[r] - prices[l]);
            }
            else
            {
                l = r;
            }
            r++;
        }
        return maxP;
    }
};
#endif

int main() 
{
    Solution a;
    {
        std::vector<int> prices = {7,1,5,3,6,4};
        int answer = 5;
        assert(answer == a.maxProfit(prices));
    }
    {
        std::vector<int> prices = {7,6,4,3,1};
        int answer = 0;
        assert(answer == a.maxProfit(prices));
    }

    std::cout << "Test done" << std::endl;
    return 0;
}