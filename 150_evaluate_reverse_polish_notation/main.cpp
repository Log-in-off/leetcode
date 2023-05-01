#include <iostream>
#include <cassert>
#include <vector>
#include <stack>
#include <unordered_map>
#include <functional>

/*
https://leetcode.com/problems/evaluate-reverse-polish-notation/
*/


/**
 * a trivial solution
 */
#if 0
class Solution {
    void getNums(std::stack<int> &nums, int& one, int& two)
    {
        two = nums.top();
        nums.pop();
        one = nums.top();
        nums.pop();
    }
public:
    int evalRPN(std::vector<std::string>& tokens) {
        std::stack<int> nums;
        int one, two;
        for(std::string& value : tokens)
        {
            if ("+" == value)
            {            
                getNums(nums, one, two);
                nums.push(one+two);
            }
            else if ("-" == value)
            {
                getNums(nums, one, two);
                nums.push(one-two);
            }
            else if ("*" == value)
            {
                getNums(nums, one, two);
                nums.push(one*two);
            }
            else if ("/" == value)
            {
                getNums(nums, one, two);
                nums.push(one/two);
            }
            else
            {
                nums.push(atoi(value.c_str()));
            }
        }
        return nums.top();
    }
};
#endif

#if 1
class Solution {
 public:
  int evalRPN(std::vector<std::string>& tokens) {
    std::stack<int> stack;
    const std::unordered_map<std::string, std::function<int(int, int)>> op{
        {"+", std::plus<int>()},
        {"-", std::minus<int>()},
        {"*", std::multiplies<int>()},
        {"/", std::divides<int>()}};

    for (const std::string& token : tokens)
      if (op.count(token)) {
        const int b = stack.top();
        stack.pop();
        const int a = stack.top();
        stack.pop();
        stack.push(op.at(token)(a, b));
      } else {
        stack.push(std::stoi(token));
      }

    return stack.top();
  }
};
#endif

int main() 
{
    Solution a;
    {
        std::vector<std::string> tokens = {"2","1","+","3","*"};
        int answer = 9;
        assert(answer == a.evalRPN(tokens));
    }
    {
        std::vector<std::string> tokens = {"4","13","5","/","+"};
        int answer = 6;
        assert(answer == a.evalRPN(tokens));
    }
    {
        std::vector<std::string> tokens = {"2","1","+","3","*"};
        int answer = 9;
        assert(answer == a.evalRPN(tokens));
    }
    std::cout << "Test done" << std::endl;
    return 0;
}