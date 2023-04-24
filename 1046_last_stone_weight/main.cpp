#include <iostream>
#include <cassert>
#include <vector>
#include <map>

/*
https://leetcode.com/problems/last-stone-weight/
*/

class Solution {
public:
    int lastStoneWeight(std::vector<int>& stones) {
        std::map<int, int> st;
        for(auto stone:stones)
            st[stone]++;

        while(!st.empty())
        {
            auto rb = st.rbegin();
            if (rb->second > 2)
            {
                rb->second -=2;
            }
            else if (rb->second == 2)
            {
                st.erase(rb->first);
            }
            else
            {
                auto rbNext = std::next(rb, 1);
                if (st.rend() == rbNext)
                {
                    return rb->first;
                }
                else
                {
                    int newStone = rb->first-rbNext->first;
                    if (rbNext->second > 1)
                        rbNext->second--;
                    else
                        st.erase(rbNext->first);
                    st.erase(rb->first);
                    st[newStone]++;
                }
            }
        }
        return 0;
    }
};

int main() 
{
    Solution a;
    {
        std::vector<int> stones = {2,7,4,1,8,1};
        int answer = 1;
        assert(answer == a.lastStoneWeight(stones));
    }
    {
        std::vector<int> stones = {1};
        int answer = 1;
        assert(answer == a.lastStoneWeight(stones));
    }
    {
        std::vector<int> stones = {1,3};
        int answer = 2;
        assert(answer == a.lastStoneWeight(stones));
    }
    std::cout << "Test done" << std::endl;
    return 0;
}