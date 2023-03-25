#include <iostream>
#include <cassert>
#include <vector>

class Solution {
public:
    int travelTree(int root, std::vector<std::vector<int>> &graph, std::vector<bool> &visited)
    {
        int count = 0;
        for(auto value:graph[root])
        {
            if (false == visited[value])
            {
                count++;
                visited[value] = true;
                if (!graph[value].empty())
                {
                    count += travelTree(value, graph, visited);
                }
            }
        }
        return count;
    }

    long long countPairs(int n, std::vector<std::vector<int>>& edges) {
        std::vector<std::vector<int>> graph(n);
        for(auto &value :edges)
        {
            graph[value[0]].push_back(value[1]);
            graph[value[1]].push_back(value[0]);
        }
        std::vector<bool> visited(n, false);
        std::vector<int> independentGraphs;
        for(int i = 0; i < n; i++ )
        {
            if (false == visited[i])
            {
                visited[i] = true;
                int size = 1;
                if (!graph[i].empty())
                    size += travelTree(i, graph, visited);
                independentGraphs.push_back(size);
            }
        }
        if (independentGraphs.size()<=1)
            return 0;
        
        long long answer = 0;
        /*slow way*/
        //for(auto it = independentGraphs.begin(); it != independentGraphs.end(); it++)
        //{
        //    for (auto jt = next(it, 1); jt != independentGraphs.end(); jt++)
        //        answer += ((long long)(*it))*(*jt);
        //}
        /*speed way*/
        int countedNodes = 0;
        for(int i = 0;i<independentGraphs.size();i++){
            answer+=(long)((long)independentGraphs[i]*(long)(n-countedNodes-independentGraphs[i]));
            countedNodes+=independentGraphs[i];
        }
        return answer;
    }
};


/*
Input: n = 3, edges = [[0,1],[0,2],[1,2]]
Output: 0
Explanation: There are no pairs of nodes that are unreachable from each other. Therefore, we return 0.

Input: n = 7, edges = [[0,2],[0,5],[2,4],[1,6],[5,4]]
Output: 14
Explanation: There are 14 pairs of nodes that are unreachable from each other:
[[0,1],[0,3],[0,6],[1,2],[1,3],[1,4],[1,5],[2,3],[2,6],[3,4],[3,5],[3,6],[4,6],[5,6]].
Therefore, we return 14.
*/
int main() 
{
    Solution a;
    //{
    //    std::vector<std::vector<int>> edges = {{0,1},{0,2},{1,2}};
    //    int n = 3;
    //    long long answer = 0;
    //    assert( answer == a.countPairs(n, edges));
    //}
    //{
    //    std::vector<std::vector<int>> edges = {{0,2},{0,5},{2,4},{1,6},{5,4}};
    //    int n = 7;
    //    long long answer = 14;
    //    assert( answer == a.countPairs(n, edges));
    //}

    {
        std::vector<std::vector<int>> edges = {{0,1},{2,3},{4,5}};
        int n = 6;
        long long answer = 12;
        assert( answer == a.countPairs(n, edges));
    }

    {
        std::vector<std::vector<int>> edges = {};
        int n = 10000;
        long long answer = 49995000;
        assert( answer == a.countPairs(n, edges));
        //std::cout <<  a.countPairs(n, edges) << std::endl;
    }

    std::cout << "Test done" << std::endl;
    return 0;
}