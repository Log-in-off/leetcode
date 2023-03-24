#include <iostream>
#include <cassert>
#include <vector>
#include <unordered_map>
#include <set>

class Solution {
public:
    void accountUselessConnectionInIndependetGraph(int vertex,
                            std::unordered_map<int, std::set<int>>& graph, 
                            std::vector<bool>& visitedVertexes)
    {
        visitedVertexes[vertex] = true;
        for(auto & value: graph[vertex])
        {
            if (false == visitedVertexes[value])
            {
                accountUselessConnectionInIndependetGraph(value, graph, visitedVertexes);
            }
        }
    }

    int makeConnected(int n, std::vector<std::vector<int>>& connections) {
        if (connections.size() < (n -1))
            return -1;

        std::unordered_map<int, std::set<int>> graph;
        
        for(auto & value : connections)
        {
            graph[value[0]].insert(value[1]);
            graph[value[1]].insert(value[0]);
        }
        int countIndependetGraph = 0;

        std::vector<bool> visitedVertexes(n, false);
        for(auto & value : graph)
        {
            if (false == visitedVertexes[value.first])
            {
                countIndependetGraph++;
                accountUselessConnectionInIndependetGraph(value.first, graph, visitedVertexes);
            }
        }

        for(auto value: visitedVertexes)
        {
            if (!value)
                countIndependetGraph++;
        }

        return countIndependetGraph-1;
    }
};

/*
Input: n = 4, connections = [[0,1],[0,2],[1,2]]
Output: 1
Explanation: Remove cable between computer 1 and 2 and place between computers 1 and 3.

Input: n = 6, connections = [[0,1],[0,2],[0,3],[1,2],[1,3]]
Output: 2

Input: n = 6, connections = [[0,1],[0,2],[0,3],[1,2]]
Output: -1
Explanation: There are not enough cables.
*/

int main() 
{
    Solution a;
    {
        std::vector<std::vector<int>> connections = {{0,1},{0,2},{1,2}};
        int n = 4;
        int answer = 1;
        assert(answer == a.makeConnected(n, connections));
    }

    {
        std::vector<std::vector<int>> connections = {{0,1},{0,2},{0,3},{1,2},{1,3}};
        int n = 6;
        int answer = 2;
        assert(answer == a.makeConnected(n, connections));
    }

    {
        std::vector<std::vector<int>> connections = {{0,1},{0,2},{0,3},{1,2}};
        int n = 6;
        int answer = -1;
        assert(answer == a.makeConnected(n, connections));
    }

    std::cout << "Test done" << std::endl;
    return 0;
}