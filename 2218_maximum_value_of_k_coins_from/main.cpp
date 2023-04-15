#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>

class Solution {
public:
    int maxValueOfCoins(std::vector<std::vector<int>>& piles, int k) {
        int n = piles.size();
        std::vector dp(n + 1, std::vector<int>(k + 1));
        for (int i = 1; i <= n; i++) {
            for (int coins = 0; coins <= k; coins++) {
                int currentSum = 0;
                for (int currentCoins = 0; currentCoins <= std::min((int)piles[i - 1].size(), coins); currentCoins++) {
                    if (currentCoins > 0) {
                        currentSum += piles[i - 1][currentCoins - 1];
                    }
                    dp[i][coins] = std::max(dp[i][coins], dp[i - 1][coins - currentCoins] + currentSum);
                }
            }
        }
        return dp[n][k];
    }
};

int main() 
{
    Solution a;
    {
        std::vector<std::vector<int>> piles = {{1,100,3},{7,8,9}};
        int k = 2;
        int answer = 101;
        assert(answer == a.maxValueOfCoins(piles, k));
    }
    {
        std::vector<std::vector<int>> piles = {{100},{100},{100},{100},{100},{100},
                                                {1,1,1,1,1,1,700}};
        int k = 7;
        int answer = 706;
        assert(answer == a.maxValueOfCoins(piles, k));
    }
    std::cout << "Test done" << std::endl;
    return 0;
}