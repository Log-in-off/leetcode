#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>

/*
https://leetcode.com/problems/generate-parentheses/description/
*/

class Solution {
    void dp(std::vector<std::string>& answer, std::string& tmp, int l, int r)
    {
        if (l == 0 && r == 0)
        {
            answer.push_back(tmp);
            return;
        }
        
        if (l > 0)
        {
            tmp.push_back('(');
            dp(answer, tmp, l-1, r);
            tmp.pop_back();
        }
        if (r > l)
        {
            tmp.push_back(')');
            dp(answer, tmp, l, r-1);
            tmp.pop_back();
        }
    }
public:
    std::vector<std::string> generateParenthesis(int n) {
        std::vector<std::string> answer;
        std::string tmp = "(";
        dp(answer, tmp, n-1, n);
        return answer;
    }
};

int main() 
{
    Solution a;
    {
        int n = 3;
        std::vector<std::string> output = {"((()))","(()())","(())()","()(())","()()()"};
        std::vector<std::string> answer = a.generateParenthesis(n);
        std::sort(output.begin(), output.end());
        std::sort(answer.begin(), answer.end());
        assert(answer == output);
    }
    {
        int n = 1;
        std::vector<std::string> output = {"()"};
        std::vector<std::string> answer = a.generateParenthesis(n);
        std::sort(output.begin(), output.end());
        std::sort(answer.begin(), answer.end());
        assert(answer == output);
    }
    std::cout << "Test done" << std::endl;
    return 0;
}