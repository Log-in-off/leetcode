#include <iostream>
#include <cassert>

int ArrayChallenge(std::string strArr[2])
{
    int answer = 0;
    for (auto i = 0; i < strArr[0].size(); i++ )
    {
        if (strArr[0][i] != strArr[1][i])
            answer++;
    }
    return answer;
}

int main() 
{
    {
        std::string test[] = {"10011", "10100"};
        assert(3 == ArrayChallenge(test));
    }

    {
        std::string test[] = {"helloworld", "worldhello"};
        assert(8 == ArrayChallenge(test));
    }
    std::cout << "Test done" << std::endl;

    return 0;
}