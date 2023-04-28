#include <iostream>
#include <cassert>
#include <vector>
#include <list>
#include <string_view>

/*
https://leetcode.com/problems/similar-string-groups/description/
*/

class Solution {
    int countDiff(const std::string_view &word, const std::string &str)
    {
        int diff = 0;
        for(int k = 0; k < word.size(); k++)
        {
            if (word[k] != str[k])
            {
                diff++;
                if (diff > 2)
                    break;
            }
        }
        return diff;
    }
public:
    int numSimilarGroups(std::vector<std::string>& strs) {
        std::list<std::vector<std::string_view>> groups;
        for (int i = 0; i < strs.size(); i++)
        {
            bool add = false;
            std::vector<std::list<std::vector<std::string_view>>::iterator> del;
            std::list<std::vector<std::string_view>>::iterator target;
            for(auto group = groups.begin(); group != groups.end(); group++)
            {
                for(const auto& word: *group)
                {
                    int diff = countDiff(word, strs[i]);
                    if (2 == diff)
                    {
                        if (true == add)
                        {
                            for(auto val: *group)
                            {
                                target->push_back(val);
                            }
                            del.push_back(group);
                        }
                        else
                        {
                            target = group;
                            group->push_back(strs[i]);
                            add = true;
                        }
                        break;
                    }
                    else if (0 == diff)
                    {
                        add = true;
                        break;
                    }
                }                
            }
            if(!add)
            {
                groups.push_back({strs[i]});
            }
            for (auto val:del)
            {
                groups.erase(val);
            }            
        }
        return groups.size();        
    }
};


int main() 
{
    Solution a;
    {
        std::vector<std::string> strs = {"tars","rats","arts","star"};
        int answer = 2;
        assert(answer == a.numSimilarGroups(strs));
    }
    {
        std::vector<std::string> strs = {"omv","ovm"};
        int answer = 1;
        assert(answer == a.numSimilarGroups(strs));
    }
    {
        std::vector<std::string> strs = {"abc","abc"};
        int answer = 1;
        assert(answer == a.numSimilarGroups(strs));
    }
    {
        std::vector<std::string> strs = {"kccomwcgcs",
                                         "socgcmcwkc",
                                         "sgckwcmcoc",
                                         "coswcmcgkc",
                                         "cowkccmsgc",
                                         "cosgmccwkc",
                                         "sgmkwcccoc",
                                         "coswmccgkc",
                                         "kowcccmsgc",
                                         "kgcomwcccs"};
        
        int answer = 5;
        assert(answer == a.numSimilarGroups(strs));
    }
    std::cout << "Test done" << std::endl;
    return 0;
}