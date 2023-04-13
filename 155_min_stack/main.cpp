#include <iostream>
#include <cassert>
#include <vector>
#include <map>
#include <stack>

/*
https://leetcode.com/problems/min-stack/description/
*/

/*a trivial solution */
#if 0
class MinStack {
public:
    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);
        min[val]++;
        
    }
    
    void pop() {
        int val = st.top();
        st.pop();
        min[val]--;
        if (0 == min[val])
            min.erase(val);
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return min.begin()->first;
    }
    private:
    std::stack<int> st;
    std::map<int, int> min;
};
#endif

/*It is a more elegant solution*/
#if 1
class MinStack {
    std::stack<int> st, min;
public:    
    MinStack() {
        
    }
    
    void push(int val) {
        if (min.empty() || min.top() >= val)
            min.push(val);
        st.push(val);
        
    }
    
    void pop() {
        if (min.top() == st.top())
            min.pop();
        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return min.top();
    }
};
#endif

int main() 
{
    {
        MinStack* minStack = new MinStack();
        minStack->push(-2);
        minStack->push(0);
        minStack->push(-3);
        assert(-3 == minStack->getMin());
        minStack->pop();
        assert(0 == minStack->top());
        assert(-2 == minStack->getMin());
        delete minStack;
    }
    std::cout << "Test done" << std::endl;
    return 0;
}