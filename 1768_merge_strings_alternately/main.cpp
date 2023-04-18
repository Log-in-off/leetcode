#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>

/*
https://leetcode.com/problems/merge-strings-alternately/description/
*/

class Solution {
public:
    std::string mergeAlternately(std::string word1, std::string word2) {
        int minSize = std::min(word1.size(), word2.size());
        std::string answer;
        answer.reserve(word1.size()+word2.size());
        int i = 0;
        for(;i < minSize; i++)
        {
            answer.push_back(word1[i]);
            answer.push_back(word2[i]);
        }
        if (word1.size() == word2.size())
            return answer;
        else if (word1.size() > word2.size())
        {
            answer += word1.substr(i, word1.size()-i);
        }
        else
        {
            answer += word2.substr(i, word2.size()-i);
        }
        return answer;
    }
};

int main() 
{
    Solution a;
    {
        std::string word1 = {"abc"};
        std::string word2 = {"pqr"};
        std::string answer = {"apbqcr"};
        assert(answer == a.mergeAlternately(word1, word2));
    }
    {
        std::string word1 = {"ab"};
        std::string word2 = {"pqrs"};
        std::string answer = {"apbqrs"};
        assert(answer == a.mergeAlternately(word1, word2));
    }
    {
        std::string word1 = {"abcd"};
        std::string word2 = {"pq"};
        std::string answer = {"apbqcd"};
        assert(answer == a.mergeAlternately(word1, word2));
    }
    std::cout << "Test done" << std::endl;
    return 0;
}