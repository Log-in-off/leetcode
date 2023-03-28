#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>
#include <unordered_set>

class Solution {
public:
    int mincostTickets(std::vector<int>& days, std::vector<int>& costs) {
        int dp[366] = {0};
        std::unordered_set<int> travelDays(days.begin(), days.end());

        for (int i = 1; i <= 365; i++) {
            if (travelDays.find(i) == travelDays.end()) {
                dp[i] = dp[i-1];
            } else {
                dp[i] = std::min(dp[i-1] + costs[0], std::min(dp[std::max(0, i-7)] + costs[1], dp[std::max(0, i-30)] + costs[2]));
            }
        }
        return dp[365];
    }
/*slow way*/
#if 0
    int req(int day, int sum, int index, std::vector<int>& days, std::vector<int>& costs)
    {
        static constexpr int duration[3] = {1, 7, 30};
        int start = days[day];
        while(day < days.size())
        {
            if (start + duration[index] - 1 < days[day])
            {
                break;
            }
            day++;
        }
         
        int localSum = sum + costs[index];
        if (day == days.size())
            return localSum;
        
        int oneStep = req(day, localSum, 0, days, costs);
        int twoStep = req(day, localSum, 1, days, costs);
        int threeStep=req(day, localSum, 2, days, costs);
        return std::min(oneStep, std::min(twoStep, threeStep));

    }
    int mincostTickets(std::vector<int>& days, std::vector<int>& costs) {
        int oneStep = req(0, 0, 0, days, costs);
        int twoStep = req(0, 0, 1, days, costs);
        int threeStep=req(0, 0, 2, days, costs);
        return std::min(oneStep, std::min(twoStep, threeStep));
    }
#endif
};

/*
Example 1:
Input: days = [1,4,6,7,8,20], costs = [2,7,15]
Output: 11
Explanation: For example, here is one way to buy passes that lets you travel your travel plan:
On day 1, you bought a 1-day pass for costs[0] = $2, which covered day 1.
On day 3, you bought a 7-day pass for costs[1] = $7, which covered days 3, 4, ..., 9.
On day 20, you bought a 1-day pass for costs[0] = $2, which covered day 20.
In total, you spent $11 and covered all the days of your travel.

Example 2:
Input: days = [1,2,3,4,5,6,7,8,9,10,30,31], costs = [2,7,15]
Output: 17
Explanation: For example, here is one way to buy passes that lets you travel your travel plan:
On day 1, you bought a 30-day pass for costs[2] = $15 which covered days 1, 2, ..., 30.
On day 31, you bought a 1-day pass for costs[0] = $2 which covered day 31.
In total, you spent $17 and covered all the days of your travel.
*/

int main() 
{
    Solution a;
    {
        std::vector<int> days = {1,4,6,7,8,20}, costs = {2,7,15};
        int answer = 11;
        assert(answer == a.mincostTickets(days, costs));
    }

    {
        std::vector<int> days = {1,2,3,4,5,6,7,8,9,10,30,31}, costs = {2,7,15};
        int answer = 17;
        assert(answer == a.mincostTickets(days, costs));
    }

    {
        std::vector<int> days = {1,2,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,20,21,
                                24,25,27,28,29,30,31,34,37,38,39,41,43,44,45,47,48,
                                49,54,57,60,62,63,66,69,70,72,74,76,78,80,81,82,83,84,85,88,89,91,93,94,97,99},
                                costs = {9,38,134};
        int answer = 423;
        assert(answer == a.mincostTickets(days, costs));
    }

    std::cout << "Test done" << std::endl;
    return 0;
}