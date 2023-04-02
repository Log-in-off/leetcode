#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<int> successfulPairs(std::vector<int>& spells, 
                                     std::vector<int>& potions,
                                     long long success) {
        std::sort(potions.begin(), potions.end());
        std::vector<int> answer;
        for(auto spell:spells)
        {
            long long potion = success/spell;
            if (0!= success%spell)
                potion++;

            if (potion > potions.back())
            {
                answer.push_back(0);
                continue;
            }

            auto it = std::lower_bound(potions.begin(), potions.end(), potion);
            answer.push_back(std::distance(it, potions.end()));
        }
        return answer;        
    }
};

/*
Example 1:
Input: spells = [5,1,3], potions = [1,2,3,4,5], success = 7
Output: [4,0,3]
Explanation:
- 0th spell: 5 * [1,2,3,4,5] = [5,10,15,20,25]. 4 pairs are successful.
- 1st spell: 1 * [1,2,3,4,5] = [1,2,3,4,5]. 0 pairs are successful.
- 2nd spell: 3 * [1,2,3,4,5] = [3,6,9,12,15]. 3 pairs are successful.
Thus, [4,0,3] is returned.

Example 2:
Input: spells = [3,1,2], potions = [8,5,8], success = 16
Output: [2,0,2]
Explanation:
- 0th spell: 3 * [8,5,8] = [24,15,24]. 2 pairs are successful.
- 1st spell: 1 * [8,5,8] = [8,5,8]. 0 pairs are successful. 
- 2nd spell: 2 * [8,5,8] = [16,10,16]. 2 pairs are successful. 
Thus, [2,0,2] is returned.
*/

int main() 
{
    Solution a;
    {
        std::vector<int> spells = {5,1,3};
        std::vector<int> potions = {1,2,3,4,5};
        long long success = 7;
        std::vector<int> answer = {4,0,3};
        assert(answer == a.successfulPairs(spells, potions, success));
    }
    {
        std::vector<int> spells = {3,1,2};
        std::vector<int> potions = {8,5,8};
        long long success = 16;
        std::vector<int> answer = {2,0,2};
        assert(answer == a.successfulPairs(spells, potions, success));
    }
    std::cout << "Test done" << std::endl;
    return 0;
}