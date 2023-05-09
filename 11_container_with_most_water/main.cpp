#include <iostream>
#include <cassert>
#include <vector>

/*
https://leetcode.com/problems/container-with-most-water/description/
*/

class Solution {
public:
    int maxArea(std::vector<int>& height) {
        int start = 0, end = height.size()-1;
        int answer = 0;
        while(start < end)
        {
            int shortest_height = std::min(height[start], height[end]);
            answer =std::max(answer , shortest_height * (end - start));

            while(start < end && shortest_height >= height[end])
                end--;
            
            while(start < end && shortest_height >= height[start])
                start++;

        }
        return answer;
    }
};

int main() 
{
    Solution a;
    {
        std::vector<int> height{1,8,6,2,5,4,8,3,7};
        int answer = 49;
        assert(answer == a.maxArea(height));
    }
    {
        std::vector<int> height{1,1};
        int answer = 1;
        assert(answer == a.maxArea(height));
    }
    {
        std::vector<int> height{1,8,6,2,5,4,8,90,1,3,7};
        int answer = 63;
        assert(answer == a.maxArea(height));
    }
    std::cout << "Test done" << std::endl;
    return 0;
}