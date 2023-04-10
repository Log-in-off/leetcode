#include <iostream>
#include <cassert>
#include <vector>
#include <stack>
#include <unordered_map>

class Solution {
public:
    bool isValid(std::string s) {
        std::unordered_map<char, char> pairs  = {{'{','}'}, {'[',']'}, {'(',')'}};
        std::stack<char> buf;
        for(auto c:s)
        {
            if (pairs.end() != pairs.find(c))
            {
                buf.push(c);
            }
            else
            {
                if (buf.empty())
                    return false;
                
                if (c == pairs[buf.top()])
                    buf.pop();
                else
                    return false;                
            }            
        }
        return buf.empty();        
    }
};

/*
Example 1:
Input: s = "()"
Output: true

Example 2:
Input: s = "()[]{}"
Output: true

Example 3:
Input: s = "(]"
Output: false
*/
int main() 
{
    Solution a;
    {
        std::string s ={"()"};
        bool answer = true;
        assert(answer == a.isValid(s));
    }
    {
        std::string s ={"()[]{}"};
        bool answer = true;
        assert(answer == a.isValid(s));
    }
    {
        std::string s ={"(]"};
        bool answer = false;
        assert(answer == a.isValid(s));
    }
    std::cout << "Test done" << std::endl;
    return 0;
}