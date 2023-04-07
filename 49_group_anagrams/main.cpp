#include <iostream>
#include <cassert>
#include <vector>
#include <unordered_map>
#include <algorithm>

/*the slow solution with big using memory*/
#if 0
class Solution {
    struct word
    {
        std::unordered_map<char, int> wordM;
        std::vector<int> indexes;
        int size;
    };
public:
    std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs) {
        std::vector<word> words;
        for(int i = 0; i< strs.size(); i++)
        {
            std::unordered_map<char, int> tmp;
            for(auto c: strs[i])
                tmp[c]++;
            bool add = false;
            for(auto &word:words)
            {
                if (word.size == strs[i].size() && 
                    word.wordM == tmp)
                    {
                        word.indexes.push_back(i);
                        add=true;
                        break;
                    }
            }
            if (!add)
            {
                word t;
                t.wordM = tmp;
                t.indexes.push_back(i);
                t.size =  strs[i].size();
                words.push_back(t);
            }
        }
        std::vector<std::vector<std::string>> answer;
        for(auto &value: words)
        {
            std::vector<std::string> t;
            for(auto i :value.indexes)
            {
                t.push_back(strs[i]);
            }
            answer.push_back(t);
        }
        return answer;
    }
};
#endif

#if 1
class Solution {
public:
    std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs) {
        std::unordered_map<std::string, std::vector<int>> buff;
        for(int i = 0; i < strs.size(); i++)
        {
            std::string tmp = strs[i];
            std::sort(tmp.begin(), tmp.end());
            auto it = buff.find(tmp);
            if (it == buff.end())
            {
                buff[tmp] = {};
            }
            buff[tmp].push_back(i);
        }
        std::vector<std::vector<std::string>> answer;
        for(auto &value: buff)
        {
            std::vector<std::string> t;
            for(auto i :value.second)
            {
                t.push_back(strs[i]);
            }
            answer.push_back(t);
        }
        return answer;       
    }
};
#endif

int main() 
{
    Solution a;
    {
        std::vector<std::string> strs = {"eat","tea","tan","ate","nat","bat"};
        std::vector<std::vector<std::string>> answer = {{"eat","tea","ate"},{"tan","nat"},{"bat"}};
        //TODO:This is an incorrect comparison.
        //assert(answer == a.groupAnagrams(strs));
    }
    {
        std::vector<std::string> strs = {""};
        std::vector<std::vector<std::string>> answer = {{""}};
        assert(answer == a.groupAnagrams(strs));
    }
    {
        std::vector<std::string> strs = {"a"};
        std::vector<std::vector<std::string>> answer = {{"a"}};
        assert(answer == a.groupAnagrams(strs));
    }

    std::cout << "Test done" << std::endl;
    return 0;
}