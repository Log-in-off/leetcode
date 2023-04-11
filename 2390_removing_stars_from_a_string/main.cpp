#include <iostream>
#include <cassert>
#include <vector>

/*
https://leetcode.com/problems/removing-stars-from-a-string/description/
*/

#if 1
class Solution {
public:
    std::string removeStars(std::string s) {
    	int countStars = 0;
    	int countCh = 0;
    	for(auto ch:s)
    	{
    		if (ch == '*')
    		{
    			if (countCh > 0)
    			{
    				countStars++;
    				countCh--;
    			}
    			countStars++;
    		}
    		else
    		{
    			countCh++;
    		}

    	}
    	std::string answer(s.size() - countStars, '0');

    	int countSkip = 0;
    	for(int i = s.size()-1, an = answer.size()-1; i >=0; i--)
    	{

    		if (s[i]!= '*')
    		{
    			if (countSkip == 0)
    			{
    			    answer[an] = s[i];
    				an--;
    			}
    			else
    				countSkip--;

    		}
    		else
    		{
    			countSkip++;
    		}
    	}
    	return answer;        
    }
};
#endif

/*a short way*/
#if 0
class Solution {
public:
    std::string removeStars(std::string s) {
        std::string res;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            if (s[i] == '*') {
                res.pop_back();
            }
            else {
                res += s[i];
            }
        }
        return res;
    }
};
#endif

int main() 
{
    Solution a;
    {
        std::string s = {"leet**cod*e"};
        std::string answer = {"lecoe"};
        assert(answer == a.removeStars(s));
    }
    {
        std::string s = {"erase*****"};
        std::string answer = {""};
        assert(answer == a.removeStars(s));
    }
    std::cout << "Test done" << std::endl;
    return 0;
}