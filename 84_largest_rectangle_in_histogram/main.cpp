#include <iostream>
#include <cassert>
#include <vector>
#include <stack>
#include <map>
#include <algorithm>

/*
https://leetcode.com/problems/largest-rectangle-in-histogram/description/
*/

class Solution {
public:
    int largestRectangleArea(std::vector<int>& heights) {
        int max = 0;
        const int n = heights.size();
        std::stack<std::pair<int, int>> st;
        for(int i = 0; i < n; i++)
        {
            if (st.empty() || (!st.empty() &&st.top().second < heights[i]))
            {
                st.push({i, heights[i]});
            }
            else if (st.top().second > heights[i])
            {
                std::pair<int, int> tmp;
                while(!st.empty() && st.top().second > heights[i])
                {
                    int area = st.top().second* (i-st.top().first);
                    if (area > max)
                        max = area;
                    tmp = st.top();
                    st.pop();
                }
                st.push({tmp.first, heights[i]});
            }
        }
        while(!st.empty())
        {
        	int area = st.top().second* (n-st.top().first);
		    if (area > max)
			    max = area;
			st.pop();
        }
        return max;
    }
};

int main() 
{
    Solution a;
    {
        std::vector<int> heights = {2,1,5,6,2,3};
        int answer = 10;
        assert(answer = a.largestRectangleArea(heights));
    }
    {
        std::vector<int> heights = {2,4};
        int answer = 2;
        assert(answer = a.largestRectangleArea(heights));
    }
    {
        std::vector<int> heights = {2,2,1,2,3,5,6,2,8,18,2,3};
        int answer = 18;
        assert(answer = a.largestRectangleArea(heights));
    }
    std::cout << "Test done" << std::endl;
    return 0;
}