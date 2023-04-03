#include <iostream>
#include <cassert>
#include <vector>
#include <map>
#include <algorithm>

class Solution {
public:
int numRescueBoats(std::vector<int>& people, int limit) {
    std::sort(people.begin(), people.end());
    int start = 0;
    int end = people.size()-1;
    int answer=0;
    while(start <= end)
    {
        if (people[end]+people[start] <= limit)
        {
            start++;
        }
        end--;
        answer++;
    }
    return answer;
}
};

/*
Example 1:
Input: people = [1,2], limit = 3
Output: 1
Explanation: 1 boat (1, 2)

Example 2:
Input: people = [3,2,2,1], limit = 3
Output: 3
Explanation: 3 boats (1, 2), (2) and (3)

Example 3:
Input: people = [3,5,3,4], limit = 5
Output: 4
Explanation: 4 boats (3), (3), (4), (5)
*/

int main() 
{
    Solution a;
    {
        std::vector<int> people = {1,2};
        int limit =3;
        int answer =1;
        assert(answer == a.numRescueBoats(people, limit));
    }
    {
        std::vector<int> people = {3,2,2,1};
        int limit =3;
        int answer =3;
        assert(answer == a.numRescueBoats(people, limit));
    }
    {
        std::vector<int> people = {3,5,3,4};
        int limit =5;
        int answer =4;
        assert(answer == a.numRescueBoats(people, limit));
    }
    {
        std::vector<int> people = {2, 2};
        int limit =6;
        int answer =1;
        assert(answer == a.numRescueBoats(people, limit));
    }
    {
        std::vector<int> people = {3,2,3,2,2};
        int limit =6;
        int answer =3;
        assert(answer == a.numRescueBoats(people, limit));
    }
    
    std::cout << "Test done" << std::endl;
    return 0;
}