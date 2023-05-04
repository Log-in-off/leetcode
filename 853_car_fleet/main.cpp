#include <iostream>
#include <cassert>
#include <vector>
#include <map>
#include <limits>

/*
https://leetcode.com/problems/car-fleet/description/
*/

class Solution {
public:
    int carFleet(int target, std::vector<int>& position, std::vector<int>& speed) {
    	std::map<int, int> pos;
    	for(int i = 0; i < position.size(); i++)
    	{
    		pos[position[i]] = speed[i];
    	}
    	double slowestTime = 0;
    	int answer = 0;
    	for(auto it = pos.rbegin(); it != pos.rend(); it++)
    	{
    		double time = (double)(target-it->first)/it->second;
    		if (time - slowestTime > std::numeric_limits<double>::epsilon())
    		//if (time > slowestTime)
    		{
    			slowestTime = time;
    			answer++;
    		}
    	}
    	return answer;
    }
};

int main() 
{
    Solution a;
    {
        int target = 12;
        std::vector<int> position = {10,8,0,5,3};
        std::vector<int> speed = {2,4,1,1,3};
        int answer = 3;
        assert(answer = a.carFleet(target, position, speed));
    }
    {
        int target = 10;
        std::vector<int> position = {3};
        std::vector<int> speed = {3};
        int answer = 1;
        assert(answer = a.carFleet(target, position, speed));
    }
    {
        int target = 100;
        std::vector<int> position = {0,2,4};
        std::vector<int> speed = {4,2,1};
        int answer = 1;
        assert(answer = a.carFleet(target, position, speed));
    }
    std::cout << "Test done" << std::endl;
    return 0;
}