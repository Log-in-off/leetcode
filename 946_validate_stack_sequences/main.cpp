#include <iostream>
#include <cassert>
#include <vector>
#include <stack>

/*
https://leetcode.com/problems/validate-stack-sequences/description/
*/

class Solution {
public:
    bool validateStackSequences(std::vector<int>& pushed, std::vector<int>& popped) {
        std::stack<int> st;
        int indexPop = 0;
        for(auto val:pushed)
        {
            st.push(val);
            while(indexPop < popped.size() && !st.empty() && st.top() == popped[indexPop])
            {
                st.pop();
                indexPop++;
            }
        }
        return st.empty() && indexPop == popped.size();
    }
};

int main() 
{
    Solution a;
    {
        std::vector<int> pushed = {1,2,3,4,5};
        std::vector<int> popped = {4,5,3,2,1};
        bool answer = true;
        assert(answer == a.validateStackSequences(pushed, popped));
    }
    {
        std::vector<int> pushed = {1,2,3,4,5};
        std::vector<int> popped = {4,3,5,1,2};
        bool answer = false;
        assert(answer == a.validateStackSequences(pushed, popped));
    }
    {
        std::vector<int> pushed = {0,1,2};
        std::vector<int> popped = {2,0,1};
        bool answer = false;
        assert(answer == a.validateStackSequences(pushed, popped));
    }
    std::cout << "Test done" << std::endl;
    return 0;
}