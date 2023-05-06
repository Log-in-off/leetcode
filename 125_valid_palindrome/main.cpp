#include <iostream>
#include <cassert>
#include <vector>

/*
https://leetcode.com/problems/valid-palindrome/description/
*/

class Solution {
public:
    bool isPalindrome(std::string s) {
        int start = 0, end = s.size()-1;
        while(start < end)
        {
            while(!std::isalnum(s[start]) && start < end)
            {
                start++;
            }
            while(!std::isalnum(s[end]) && start < end)
            {
                end--;
            }
            
            if (std::tolower(s[start]) != std::tolower(s[end]))
                return false;
            
            start++;
            end--;
        }
        return true;
    }
};

int main() 
{
    Solution a;
    {
        std::string s = {"A man, a plan, a canal: Panama"};
        bool answer = true;
        assert(answer == a.isPalindrome(s));
    }
    {
        std::string s = {"race a car"};
        bool answer = false;
        assert(answer == a.isPalindrome(s));
    }
    {
        std::string s = {" "};
        bool answer = true;
        assert(answer == a.isPalindrome(s));
    }
    {
        std::string s = {"0P"};
        bool answer = false;
        assert(answer == a.isPalindrome(s));
    }
    std::cout << "Test done" << std::endl;
    return 0;
}