#include <vector>
#include <set>
#include <iostream>


namespace{

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> set_num(nums.begin(), nums.end());
        uint32_t max = 0;
        uint32_t current = 0;

        int last = *set_num.begin() - 1;
        for(auto num : set_num)
        {
            if (last + 1 == num)
                current++;
            else
            {
                if (current > max)
                max = current;
                current = 1;
            }
            last = num;
        }
        if (current > max)
            max = current;

        return max;
    }
};
}

int main()
{
    Solution a;
    vector<int> test1 = {100,4,200,1,3,2};
    cout << a.longestConsecutive(test1) << std::endl;

    vector<int> test2 = {0,3,7,2,5,8,4,6,0,1};
    cout << a.longestConsecutive(test2) << std::endl;
    return 0;
}

