#include <iostream>
#include <cassert>
#include <vector>


class Solution {
public:
    struct road
    {
        int direction;
        bool status;
    };
    int count;
    void treeTraversal(int root, int parent, std::vector<std::vector<road>> &graph)
    {
        for(auto value: graph[root])
        {
            if (value.direction == parent)
                continue;
            if (value.status == true)
                count++;
            treeTraversal(value.direction, root, graph);
        }
    }
    int minReorder(int n, std::vector<std::vector<int>>& connections) {
        std::vector<std::vector<road>> graph(n);
        for (auto &value:connections)
        {
            graph[value[0]].push_back({value[1], true});
            graph[value[1]].push_back({value[0], false});
        }
        count = 0;
        treeTraversal(0, -1, graph);

        return count;
    }
};

/*
Input: n = 6, connections = [[0,1],[1,3],[2,3],[4,0],[4,5]]
Output: 3
Explanation: Change the direction of edges show in red such that each node can reach the node 0 (capital).

Input: n = 5, connections = [[1,0],[1,2],[3,2],[3,4]]
Output: 2
Explanation: Change the direction of edges show in red such that each node can reach the node 0 (capital).

Input: n = 3, connections = [[1,0],[2,0]]
Output: 0
*/

int main() 
{
    Solution a;
    {
        std::vector<std::vector<int>> connections = {{0,1},{1,3},{2,3},{4,0},{4,5}};
        int n = 6;
        int answer = 3;
        assert(answer == a.minReorder(n, connections));
    }

    {
        std::vector<std::vector<int>> connections = {{1,0},{1,2},{3,2},{3,4}};
        int n = 5;
        int answer = 2;
        assert(answer == a.minReorder(n, connections));
    }

    {
        std::vector<std::vector<int>> connections = {{1,0},{2,0}};
        int n = 3;
        int answer = 0;
        assert(answer == a.minReorder(n, connections));
    }

    std::cout << "Test done" << std::endl;
    return 0;
}