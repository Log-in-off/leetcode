#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>

/*
https://leetcode.com/problems/longest-palindromic-subsequence/description/
*/

class Solution{
    int lps(std::string& s, int i, int j, std::vector<std::vector<int>>& memo)
    {
        if (memo[i][j]!=0)
            return memo[i][j];
        
        if (i > j)
            return 0;
        
        if (i == j)
            return 1;

        if (s[i] == s[j])
            memo[i][j] = 2 + lps(s, i+1, j-1, memo);
        else
            memo[i][j] = std::max(lps(s, i+1, j, memo), lps(s, i, j-1, memo));
        return memo[i][j];
    }
public:
    int longestPalindromeSubseq(std::string s) {
        int n = s.size();
        std::vector<std::vector<int>> memo(n, std::vector<int>(n, 0));
        return lps(s, 0, n-1, memo);
    }
};

int main() 
{
    Solution a;
    {
        std::string s = {"bbbab"};
        int answer = 4;
        assert(answer == a.longestPalindromeSubseq(s));
    }
    {
        std::string s = {"cbbd"};
        int answer = 2;
        assert(answer == a.longestPalindromeSubseq(s));
    }
    {
        std::string s = {"bbaffksdksdfadfgdsfgdfbsfghfsbadadsfasdfasvaaasdfadfbab"};
        int answer = 31;
        assert(answer == a.longestPalindromeSubseq(s));
    }
    std::cout << "Test done" << std::endl;
    return 0;
}