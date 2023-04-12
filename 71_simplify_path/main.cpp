#include <iostream>
#include <cassert>
#include <vector>
#include <stack>

/*
https://leetcode.com/problems/simplify-path/description/
*/

class Solution {
public:
    std::string simplifyPath(std::string path) {
        std::stack<std::string> folders;
        for (int i = 0; i < path.size(); i++)
        {
            if ('/' == path[i])
                continue;

            std::string temp = "";
            while(i < path.size() && path[i] != '/')
            {
                temp += path[i];
                i++;
            }

            if (temp == ".")
                continue;

            if (temp == "..")
            {
                if (!folders.empty())
                    folders.pop();
            }
            else
            {
                folders.push(temp);
            }            
        }

        if (folders.empty())
            return "/";

        std::string answer = "";
        while(!folders.empty())
        {
            answer = "/" + folders.top() + answer;
            folders.pop();
        }
        return answer;
    }
};

int main() 
{
    Solution a;
    {
        std::string path = {"/home/"};
        std::string answer = {"/home"};
        assert(answer == a.simplifyPath(path));
    }
    {
        std::string path = {"/../"};
        std::string answer = {"/"};
        assert(answer == a.simplifyPath(path));
    }
    {
        std::string path = {"/home//foo/"};
        std::string answer = {"/home/foo"};
        assert(answer == a.simplifyPath(path));
    }
    {
        std::string path = {"/a/./b/../../c/"};
        std::string answer = {"/c"};
        assert(answer == a.simplifyPath(path));
    }
    std::cout << "Test done" << std::endl;
    return 0;
}