#include <iostream>
#include <cassert>
#include <stack>

std::string SearchingChallenge(std::string &str)
{
    using namespace std::string_literals;
    std::stack<char> st;
    bool fail = false;
    int count  = 0;
    for(auto ch:str)
    {
        if ( '(' == ch || '[' == ch)
        {
            st.push(ch);
        }
        else if (')' == ch || ']' == ch)
        {
            if (st.empty())
            {
                fail = true;
                break;
            }

            if ((')' == ch && st.top() != '(') || (']' == ch && st.top() != '['))
            {
                fail = true;
                break;
            }
            else
            {
                st.pop();
                count++;
            }            
        }
    }

    if (fail)
        return "0"s;
    
    if (0 == count)
        return "1"s;
    
    std::string answer = {"1 "};
    return answer + std::to_string(count);
    

}

int main() 
{
    using namespace std::string_literals;
    {
        std::string test = {"(coder)[byte])"};
        assert("0"s == SearchingChallenge(test)); 
    }

    {
        std::string test = {"(c([od]er))b(yt[e])"};
        assert("1 5"s == SearchingChallenge(test)); 
    }

    {
        std::string test = {"(hello[word])(!)"};
        assert("1 3"s == SearchingChallenge(test)); 
    }

    std::cout << "Test done" << std::endl;
    return 0;
}