#include <iostream>
#include <cassert>
#include <vector>
#include <stack>

/*
https://leetcode.com/problems/daily-temperatures/description/
*/

class Solution {
public:
    std::vector<int> dailyTemperatures(std::vector<int>& temperatures) {
  	std::vector<int> answer(temperatures.size(), 0);
  	std::stack<int> st;
  	for(int i = temperatures.size()-1; i >=0; i--)
  	{
		while(!st.empty() and temperatures[st.top()] <= temperatures[i])
		{
            st.pop();
        }

		if (!st.empty())
		{
		  answer[i] = st.top()-i;
		}
		st.push(i);
  	}
  	return answer;
    }
};

int main() 
{
    Solution a;
    {
        std::vector<int> temperatures = {73,74,75,71,69,72,76,73};
        std::vector<int> answer = {1,1,4,2,1,1,0,0};
        assert(answer == a.dailyTemperatures(temperatures));
    }
    {
        std::vector<int> temperatures = {30,40,50,60};
        std::vector<int> answer = {1,1,1,0};
        assert(answer == a.dailyTemperatures(temperatures));
    }
    {
        std::vector<int> temperatures = {30,60,90};
        std::vector<int> answer = {1,1,0};
        assert(answer == a.dailyTemperatures(temperatures));
    }
    std::cout << "Test done" << std::endl;
    return 0;
}