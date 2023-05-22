#include <iostream>
#include <cassert>
#include <vector>
#include <unordered_set>

/*
https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
*/

class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        std::unordered_set<char> buf;
        int r = 0, l = 0;
        int answer = 0;
        while(r < s.size())
        {
        	if(buf.empty() || buf.find(s[r]) == buf.end())
        	{
        		buf.insert(s[r]);		
        	}
        	else
        	{
        		answer = std::max(answer, r - l);
        		while(s[l] != s[r])
        		{
        			buf.erase(s[l]);
        			l++;
        		}
        		if (l != r)
        			l++;
        	}
        	r++;
        }
        return std::max(answer, r - l);
    }
};

int main() 
{
    Solution a;
    {
        std::string s = {"abcabcbb"};
        int answer = 3;
        assert(answer == a.lengthOfLongestSubstring(s));
    }
    {
        std::string s = {"bbbbb"};
        int answer = 1;
        assert(answer == a.lengthOfLongestSubstring(s));
    }
    {
        std::string s = {"pwwkew"};
        int answer = 3;
        assert(answer == a.lengthOfLongestSubstring(s));
    }
    {
        std::string s = {" "};
        int answer = 1;
        assert(answer == a.lengthOfLongestSubstring(s));
    }
    std::cout << "Test done" << std::endl;
    return 0;
}