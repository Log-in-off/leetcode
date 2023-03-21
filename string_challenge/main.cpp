#include <iostream>
#include <cassert>
#include <unordered_map>
#include <cmath>

std::string StringChallenge(std::string str)
{
    std::unordered_map<char, int> map;
    map['I'] = 1;
    map['V'] = 5;
    map['X'] = 10;
    map['L'] = 50;
    map['C'] = 100;
    map['D'] = 500;
    map['M'] = 1000;
    int value = 0;
    for(auto ch: str)
        value += map[ch];
    
    int thousands = value / map['M'];
    value %=  map['M'];

    std::string answer(thousands, 'M');
    std::string nines[] = {"CM", "XC", "IX"};
    std::string fours[] = {"CD", "XL", "IV"};
    std::string fifths[] = {"D", "L", "V"};
    char ones[] = {'C', 'X', 'I'};

    for(int i = 0; i < 3; i++)
    {
        int factor = std::pow(10, 2-i);

        int tmp = value/factor;
        if (tmp == 9)
        {
            answer += nines[i];
        }
        else if (tmp == 4)
        {
            answer += fours[i];
        } 
        else
        {
            if (tmp >= 5)
            {
                answer+= fifths[i];
                tmp -= 5;
                
            }
            answer += std::string(tmp, ones[i]);
        }        
        value %= factor;
    }
    return answer;
}

int main() 
{
    using namespace std::string_literals;
    {
        std::string test = {"XXXVVIIIIIIIIII"};
        assert ("L"s == StringChallenge(test));
    }

    {
        std::string test = {"DDLL"};
        assert ("MC"s == StringChallenge(test));
    }

    {
        std::string test = {"VIIII"};
        assert ("IX"s == StringChallenge(test));
    }

    {
        std::string test = {"DCCCCLXXXXVIIII"};
        assert ("CMXCIX"s == StringChallenge(test));
    }

    {
        std::string test = {"IIII"};
        assert ("IV"s == StringChallenge(test));
    }

    {
        std::string test = {"CCCCXXXXIIII"};
        assert ("CDXLIV"s == StringChallenge(test));
    }
    
    std::cout << "Test done" << std::endl;
    return 0;
}