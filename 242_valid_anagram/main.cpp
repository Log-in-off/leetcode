#include <iostream>
#include <cassert>
#include <vector>
#include <unordered_map>

/*slow way*/
#if 0
class Solution {
public:
    bool isAnagram(std::string s, std::string t) {
        std::sort(s.begin(), s.end());
        std::sort(t.begin(), t.end());
        return s == t;
    }
};
#endif

class Solution {
public:
    bool isAnagram(std::string s, std::string t) {

        if (s.size()!=t.size())
            return false;
        std::unordered_map<char, int> buf;
        int size = buf.size();
        for(auto i:s)
        {
            buf[i]++;
        }
        for(auto c:t)
        {
            auto it = buf.find(c);
            if (it!=buf.end())
            {
                if ((*it).second > 0)
                {
                    (*it).second--;
                }
                else
                    return false;
            }
            else
            {
                return false;
            }
        }
        return true;
    }
};

int main() 
{
    Solution a;
    {
        std::string s = {"anagram"};
        std::string t = {"nagaram"};
        bool answer = true;
        assert(answer == a.isAnagram(s, t));
    }
    {
        std::string s = {"rat"};
        std::string t = {"car"};
        bool answer = false;
        assert(answer == a.isAnagram(s, t));
    }
    std::cout << "Test done" << std::endl;
    return 0;
}