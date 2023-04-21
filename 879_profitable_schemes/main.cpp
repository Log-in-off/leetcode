#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>

/*
https://leetcode.com/problems/profitable-schemes/description/
*/

class Solution {
public:
    int mod=1e9+7;
    int profitableSchemes(int n, int minProfit, std::vector<int>& group, std::vector<int>& profit) {
        std::vector<std::vector<int>> dp(n + 1, std::vector<int>(minProfit + 1, 0));
        dp[0][0] = 1;
        for (int k = 1; k <= group.size(); k++) {
            int g = group[k - 1];
            int p = profit[k - 1];
            for (int i = n; i >= g; i--) {
                for (int j = minProfit; j >= 0; j--) {
                    dp[i][j] = (dp[i][j] + dp[i - g][std::max(0, j - p)]) % mod;
                }
            }
        }
        int sum = 0;
        for (int i = 0; i <= n; i++) {
            sum = (sum + dp[i][minProfit]) % mod;
        }
        return sum;
    }
};

int main() 
{
    Solution a;
    {
        int n = 5;
        int minProfit = 3;
        std::vector<int> group = {2,2}, profit = {2,3};
        int answer = 2;
        assert(answer = a.profitableSchemes(n, minProfit,group, profit));
    }
    {
        int n = 10;
        int minProfit = 5;
        std::vector<int> group = {2,3,5}, profit = {6,7,8};
        int answer = 7;
        assert(answer = a.profitableSchemes(n, minProfit,group, profit));
    }
    std::cout << "Test done" << std::endl;
    return 0;
}