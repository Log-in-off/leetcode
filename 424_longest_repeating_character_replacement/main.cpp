#include <iostream>
#include <cassert>
#include <vector>

/*
The trivial solution - n^2
*/
#if 0
class Solution {
public:
    int characterReplacement(std::string s, int k) {
    	int r = 0, l = 0, max = 0, tmp = k, tmp_max = 0;
    	while(r < s.size())
    	{
    		if(s[r] == s[l])
    		{
    			tmp_max++;
    			
    		}
    		else if (tmp > 0)
    		{
    			tmp--;
    			tmp_max++;
    		}
    		else
    		{
    			max = std::max(max, tmp_max);
    			tmp_max = 1;
    			tmp = k;
    			while(s[l] == s[l+1])
    				l++;
    			l++;
                r = l;
    		}
    		r++;
    	}
        if (tmp> 0)
        {
            tmp_max = std::min((int)s.size(), tmp + tmp_max);
        }
    	return max = std::max(max, tmp_max);
    }
};
#endif

class Solution {
public:
    int characterReplacement(std::string s, int k) {
        int buf[26] = {};
        int l = 0, r = 0, max = 0;
        int answer = 0;
        while(r < s.size())
        {
            buf[s[r] - 'A']++;
            max = std::max(max, buf[s[r] - 'A']);
            if (r -l + 1 - max > k)
            {
                buf[s[l] - 'A']--;
                l++;
            }
            answer = std::max(answer, r-l+1);
            r++;
        }
        return answer;
    }
};

int main() 
{
    Solution a;
    {
        std::string s = {"ABAB"};
        int k = 2;
        int answer = 4;
        assert(answer == a.characterReplacement(s, k));
    }
    {
        std::string s = {"AABABBA"};
        int k = 1;
        int answer = 4;
        assert(answer == a.characterReplacement(s, k));
    }
    {
        std::string s = {"ABABFFIGKSFGLGIJOKDJFIGILKJJJFLIJGLF"};
        int k = 4;
        int answer = 8;
        assert(answer == a.characterReplacement(s, k));
    }
    {
        std::string s = {"ABBB"};
        int k = 2;
        int answer = 4;
        assert(answer == a.characterReplacement(s, k));
    }
    std::cout << "Test done" << std::endl;
    return 0;
}