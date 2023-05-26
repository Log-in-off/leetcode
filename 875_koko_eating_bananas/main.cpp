#include <iostream>
#include <cassert>
#include <vector>

/*
https://leetcode.com/problems/koko-eating-bananas/description/
*/

class Solution {
public:
    int minEatingSpeed(std::vector<int>& piles, int h) {
        int low = 1;
        int high = piles[0];
        for(auto val:piles)
        {
            high = std::max(high, val);
        }
        int result = high;
        while(low <= high)
        {
            long int time = 0;
            int mid = (low+high)/2;
            for(auto val:piles)
            {
                time += (val -1)/mid +1;
            }
            if (time <= h)
            {
                high = mid-1;
                result = std::min(result, mid);
            }
            else
            {
                low = mid+1;
            }
        }
        return result;
    }
};

int main() 
{
    Solution a;
    {
        std::vector<int> piles = {3,6,7,11};
        int h = 8;
        int answer = 4;
        assert(answer == a.minEatingSpeed(piles, h));
    }
    {
        std::vector<int> piles = {30,11,23,4,20};
        int h = 5;
        int answer = 30;
        assert(answer == a.minEatingSpeed(piles, h));
    }
    {
        std::vector<int> piles = {30,11,23,4,20};
        int h = 6;
        int answer = 23;
        assert(answer == a.minEatingSpeed(piles, h));
    }
    {
        std::vector<int> piles = {3};
        int h = 8;
        int answer = 1;
        assert(answer == a.minEatingSpeed(piles, h));
    }
    {
        std::vector<int> piles = {805306368,805306368,805306368};
        int h = 1000000000;
        int answer = 3;
        assert(answer == a.minEatingSpeed(piles, h));
    }
    std::cout << "Test done" << std::endl;
    return 0;
}