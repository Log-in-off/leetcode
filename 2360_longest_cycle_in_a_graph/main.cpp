#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>

class Solution {
public:
    bool travelGraph(int root, std::vector<int>& cycle, 
                               std::vector<int>& edges, 
                               std::vector<bool>& visited)
    {
        if (false == visited[root])
        {
            visited[root]= true;
            if (-1 != edges[root])
            {
                cycle.push_back(root);
                return travelGraph(edges[root], cycle, edges, visited);
            }
        }
        else
        {
            cycle.push_back(root);
            return true;
        }

        return false;
    }
    int longestCycle(std::vector<int>& edges) {
        std::vector<bool> visited(edges.size(), false);
        int max = -1;
        for(int i = 0; i < edges.size(); i++)
        {
            std::vector<int> cycle;
            if (false == visited[i])
            {
                bool end = travelGraph(i, cycle, edges, visited);
                if (end && cycle.size() > 1)
                {
                    auto it= std::find(cycle.begin(), cycle.end(), cycle.back());
                    if (it == (cycle.end()-1))
                        continue;

                    int dist = std::distance(it, (cycle.end()-1));
                    if (dist > max)
                        max = dist;
                }
            }
        }
        return max;
        
    }
};

/*
Input: edges = [3,3,4,2,3]
Output: 3
Explanation: The longest cycle in the graph is the cycle: 2 -> 4 -> 3 -> 2.
The length of this cycle is 3, so 3 is returned.

Input: edges = [2,-1,3,1]
Output: -1
Explanation: There are no cycles in this graph.
*/


int main() 
{
    Solution a;
    {
        std::vector<int> edges = {3,3,4,2,3};
        int answer = 3;
        assert( answer == a.longestCycle(edges));
    }
    
    {
        std::vector<int> edges = {2,-1,3,1};
        int answer = -1;
        assert( answer == a.longestCycle(edges));
    }

    {
        std::vector<int> edges = {3,4,0,2,-1,2};
        int answer = 3;
        assert( answer == a.longestCycle(edges));
    }
    std::cout << "Test done" << std::endl;
    return 0;
}