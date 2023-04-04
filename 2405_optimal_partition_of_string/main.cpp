#include <iostream>
#include <cassert>
#include <vector>
#include <unordered_set>

class Solution {
public:
    int partitionString(std::string s) {
        int answer = 0;
        std::unordered_set<char> buff;
        for(auto l:s)
        {
            if (buff.find(l)!=buff.end())
            {
                answer++;
                buff.clear();
            }
            buff.insert(l);
        }
        if (!buff.empty())
            answer++;
        return answer;
    }
};

/*
Example 1:
Input: s = "abacaba"
Output: 4
Explanation:
Two possible partitions are ("a","ba","cab","a") and ("ab","a","ca","ba").
It can be shown that 4 is the minimum number of substrings needed.

Example 2:
Input: s = "ssssss"
Output: 6
Explanation:
The only valid partition is ("s","s","s","s","s","s").
*/

int main() 
{
    Solution a;
    {
        std::string s = {"abacaba"};
        int answer = 4;
        assert(answer == a.partitionString(s));
    }
    {
        std::string s = {"ssssss"};
        int answer = 6;
        assert(answer == a.partitionString(s));
    }
    std::cout << "Test done" << std::endl;
    return 0;
}