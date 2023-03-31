#include <iostream>
#include <cassert>
#include <vector>
#include <string_view>
#include <unordered_map>

class Solution {
public:
    std::unordered_map<std::string, bool> buff;
    bool isScrambleView(std::string_view s1, std::string_view s2)
    {
        using namespace std::string_literals;   
        using namespace std::string_view_literals;       
        
        int n = s1.size();
        
        if (s1.size() != s2.size())
            return false;
        
        if (s1 == s2)
            return true;
        
        if (1 == n)
            return false;

        std::string key(s1);
        key += ""s;
        key += s2;

        auto it = buff.find(key);
        if (buff.end() != it)
            return (*it).second;
        

        for (int i = 1; i < n; i++)
        {
            bool withoutSwap = isScrambleView(s1.substr(0, i), s2.substr(0, i)) &&
                               isScrambleView(s1.substr(i),    s2.substr(i));
            if(withoutSwap)
            {
                buff[key] = true;
                return true;
            }

            bool withSwap = isScrambleView(s1.substr(0, i), s2.substr(n-i)) &&
                            isScrambleView(s1.substr(i),    s2.substr(0, n-i));
            if(withSwap)
            {
                buff[key] = true;
                return true;
            }
        }        

        buff[key] = false;
        return false;
    }


    bool isScramble(std::string s1, std::string s2)
    {
        return isScrambleView(s1, s2);
    }
};

/*
Example 1:
Input: s1 = "great", s2 = "rgeat"
Output: true
Explanation: One possible scenario applied on s1 is:
"great" --> "gr/eat" // divide at random index.
"gr/eat" --> "gr/eat" // random decision is not to swap the two substrings and keep them in order.
"gr/eat" --> "g/r / e/at" // apply the same algorithm recursively on both substrings. divide at random index each of them.
"g/r / e/at" --> "r/g / e/at" // random decision was to swap the first substring and to keep the second substring in the same order.
"r/g / e/at" --> "r/g / e/ a/t" // again apply the algorithm recursively, divide "at" to "a/t".
"r/g / e/ a/t" --> "r/g / e/ a/t" // random decision is to keep both substrings in the same order.
The algorithm stops now, and the result string is "rgeat" which is s2.
As one possible scenario led s1 to be scrambled to s2, we return true.

Example 2:
Input: s1 = "abcde", s2 = "caebd"
Output: false

Example 3:
Input: s1 = "a", s2 = "a"
Output: true
*/

int main() 
{
    Solution a;
    {
        std::string str1("great");
        std::string str2("rgeat");
        assert(true == a.isScramble(str1, str2));
    }
    {
        std::string str1("abcde");
        std::string str2("caebd");
        assert(false == a.isScramble(str1, str2));
    }
    {
        std::string str1("a");
        std::string str2("a");
        assert(true == a.isScramble(str1, str2));
    }
    {
        std::string str1("abcdbdacbdac");
        std::string str2("bdacabcdbdac");
        assert(true == a.isScramble(str1, str2));
    }
    std::cout << "Test done" << std::endl;
    return 0;
}