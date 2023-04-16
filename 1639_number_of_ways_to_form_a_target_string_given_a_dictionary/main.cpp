#include <iostream>
#include <cassert>
#include <vector>

class Solution {
public:
    int numWays(std::vector<std::string>& words, std::string target) {
        const int alphabet = 26;
        const int mod = 1000000007;
        int m = target.size(), k = words[0].size();
        std::vector cnt(alphabet, std::vector<int>(k));
        for (int j = 0; j < k; j++) {
            for (const std::string& word : words) {
                cnt[word[j] - 'a'][j]++;
            }
        }
        std::vector dp(m + 1, std::vector<long long>(k + 1));
        dp[0][0] = 1;
        for (int i = 0; i <= m; i++) {
            for (int j = 0; j < k; j++) {
                if (i < m) {
                    (dp[i + 1][j + 1] += cnt[target[i] - 'a'][j] * dp[i][j]) %= mod;
                }
                (dp[i][j + 1] += dp[i][j]) %= mod;
            }
        }
        return dp[m][k];
    }
};

int main() 
{
    Solution a;
    {
        std::vector<std::string> words = {"acca","bbbb","caca"};
        std::string target = "aba";
        int answer = 6;
        assert(answer == a.numWays(words, target));
    }
    {
        std::vector<std::string> words = {"abba","baab"};
        std::string target = "bab";
        int answer = 4;
        assert(answer == a.numWays(words, target));
    }
    std::cout << "Test done" << std::endl;
    return 0;
}   