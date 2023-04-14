#include <iostream>
#include <cassert>
#include <vector>

/*
https://leetcode.com/problems/reverse-string/
*/
/*
the recursion solution 
*/
#if 0
class Solution {
    void rev(std::vector<char>& s, int begin, int end)
    {
        if (begin >= end)
            return;
        std::swap(s[begin], s[end]);
        rev(s, begin+1, end - 1);        
    }
public:
    void reverseString(std::vector<char>& s) {
        rev(s, 0, s.size()-1);
    }
};
#endif

/*
the iteration solution
*/
#if 1
class Solution {
public:
    void reverseString(std::vector<char>& s) {
        for (int f = 0, b = s.size() - 1; f < b; f++, b--) {
            std::swap(s[f], s[b]);
        }
    }
};
#endif

int main() 
{
    Solution a;
    {
        std::vector<char> s = {'h','e','l','l','o'};
        std::vector<char> answer = {'o','l','l','e','h'};
        a.reverseString(s);
        assert(s == answer);
    }
    {
        std::vector<char> s = {'H','a','n','n','a','h'};
        std::vector<char> answer = {'h','a','n','n','a','H'};
        a.reverseString(s);
        assert(s == answer);
    }
    std::cout << "Test done" << std::endl;
    return 0;
}