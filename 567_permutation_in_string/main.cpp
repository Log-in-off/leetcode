#include <iostream>
#include <cassert>
#include <vector>
#include <unordered_map>

/*
https://leetcode.com/problems/permutation-in-string/description/
*/

/**
 * The universal solution
 */
#if 1
class Solution {
public:
    bool checkInclusion(std::string s1, std::string s2) {
        if(s2.size() < s1.size())
            return false;
        std::unordered_map<char, int> s1buf;
        for(auto ch:s1)
            s1buf[ch]++;

        std::unordered_map<char, int> s2buf;
        for(int i = 0; i < s1.size()-1; i++)
            s2buf[s2[i]]++;
        
        int l = 0, r = s1.size()-1;

        while(r < s2.size())
        {
            s2buf[s2[r]]++;
            auto lf = s1buf.find(s2[l]);
            auto rf = s1buf.find(s2[r]);
            if (lf != s1buf.end() && rf != s1buf.end())
            {
                if(s1buf == s2buf)
                    return true;
            }
            s2buf[s2[l]]--;
            if (s2buf[s2[l]] == 0)
                s2buf.erase(s2[l]);
            l++;
            r++;
            
        }
        return false;
    }
};
#endif

/**
 * The solution without hash_map
 */
#if 0
class Solution {
public:
    bool checkInclusion(std::string s1, std::string s2) {
        int m = s1.size();
        int n = s2.size();
        if (m > n) {
            return false;
        }
        
        std::vector<int> count(26);
        for (int i = 0; i < m; i++) {
            count[s1[i] - 'a']++;
            count[s2[i] - 'a']--;
        }
        if (isPermutation(count)) {
            return true;
        }
        
        for (int i = m; i < n; i++) {
            count[s2[i] - 'a']--;
            count[s2[i - m] - 'a']++;
            if (isPermutation(count)) {
                return true;
            }
        }
        
        return false;
    }
private:
    bool isPermutation(std::vector<int>& count) {
        for (int i = 0; i < 26; i++) {
            if (count[i] != 0) {
                return false;
            }
        }
        return true;
    }
};
#endif

int main() 
{
    Solution a;
    {
        std::string s1 = {"ab"};
        std::string s2 = {"eidbaooo"};
        bool answer =true;
        assert(answer == a.checkInclusion(s1, s2));
    }
    {
        std::string s1 = {"ab"};
        std::string s2 = {"eidboaoo"};
        bool answer = false;
        assert(answer == a.checkInclusion(s1, s2));
    }
    {
        std::string s1 = {"abc"};
        std::string s2 = {"eidcbaooo"};
        bool answer = true;
        assert(answer == a.checkInclusion(s1, s2));
    }
    {
        std::string s1 = {"ab"};
        std::string s2 = {"eidbpaooa"};
        bool answer = false;
        assert(answer == a.checkInclusion(s1, s2));
    }
    {
        std::string s1 = {"abc"};
        std::string s2 = {"eidbcaooo"};
        bool answer = true;
        assert(answer == a.checkInclusion(s1, s2));
    }
    {
        std::string s1 = {"dinitrophenylhydrazine"};
        std::string s2 = {"dimethylhydrazine"};
        bool answer = false;
        assert(answer == a.checkInclusion(s1, s2));
    }
    std::cout << "Test done" << std::endl;
    return 0;
}