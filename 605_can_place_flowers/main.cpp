#include <iostream>
#include <vector>

class Solution {
public:
    bool canPlaceFlowers(std::vector<int>& flowerbed, int n) {
        if (0 == n)
            return true;
        
        if (1 == flowerbed.size())
        {
            if (1 == n && 0 == flowerbed[0])
                return true;
            else
                return false;
        }
        
        std::vector<int>::iterator lh = flowerbed.begin();
        std::vector<int>::iterator mh = next(flowerbed.begin(), 1);
        std::vector<int>::iterator rh = next(flowerbed.begin(), 2);
        if (0 == *lh && 0 == *mh)
        {
            *lh = 1;
            n--;
        }
        while (n > 0 && rh != flowerbed.end())
        {
            if (0 == *lh && 0 == *mh && 0 == *rh)
            {
                *mh = 1;
                n--;
            }
            lh++;
            mh++;
            rh++;
        }
        if (n == 0)
            return true;        

        if (n == 1 && 0 == *lh && 0 == *mh)
            return true;

        return false;
    }
};

#include <cassert>
int main()
{
    Solution a;
    {
        std::vector<int> flowerbed = {1,0,0,0,1};
        int n = 1;
        bool answer = true;
        assert(answer == a.canPlaceFlowers(flowerbed, n));
    }

    {
        std::vector<int> flowerbed = {1,0,0,0,1};
        int n = 2;
        bool answer = false;
        assert(answer == a.canPlaceFlowers(flowerbed, n));
    }

    {
        std::vector<int> flowerbed = {1};
        int n = 1;
        bool answer = false;
        assert(answer == a.canPlaceFlowers(flowerbed, n));
    }

    {
        std::vector<int> flowerbed = {0};
        int n = 1;
        bool answer = true;
        assert(answer == a.canPlaceFlowers(flowerbed, n));
    }

    
    std::cout << "Test done" << std::endl;
    return 0;
}