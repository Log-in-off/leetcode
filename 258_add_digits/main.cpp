#include <iostream>
#include <cassert>
#include <vector>

/*
https://leetcode.com/problems/add-digits/description/
*/
#if 0
/**
 *  Trivial solution
 */
class Solution {
public:
    int addDigits(int num) {
        
        while(num > 9)
        {
            std::string val = std::to_string(num);
            num = 0;
            for(auto ch : val)
                num += ch- '0';
        }
        return num;
    }
};
#endif

#if 1
/**
 *  Mathematic trick
 */
class Solution {
public:
    int addDigits(int num) {
        if (num == 0)
            return 0;
        if (0 == num%9)
            return 9;
        return num%9;
    }
};
#endif

int main() 
{
    Solution a;
    {
        int num = 38;
        int answer = 2;
        assert(answer == a.addDigits(num));
    }
    {
        int num = 0;
        int answer = 0;
        assert(answer == a.addDigits(num));
    }
    {
        int num = 3265132;
        int answer = 4;
        assert(answer == a.addDigits(num));
    }
    std::cout << "Test done" << std::endl;
    return 0;
}