#include <iostream>
#include <cassert>
#include <vector>

#include <unordered_map>
#include <map>
#include <set>
#include <stack>
/*classic Dijkstra algorithm*/
#if 0
class Solution {
public:
    int minScore(int n, std::vector<std::vector<int>>& roads) {
        std::unordered_map<int, std::map<int, int>> graph;
        for(int i = 1; i < n+1; i++)
            graph[i] = {};
        for(auto & value: roads)
        {
            graph[value[0]][value[2]] = value[1];
            graph[value[1]][value[2]] = value[0];
        }

        std::vector<int> vertexes(n+1, INT32_MAX);
        std::set<int> visited_vertex;
        int start = 1;
        vertexes[start] = 0;
        while(true)
        {
            for(auto & value : graph[start])
            {
                if (visited_vertex.end() == visited_vertex.find(value.second))
                {
                    if (vertexes[value.second] > value.first+vertexes[start])
                    {
                        vertexes[value.second] = value.first+vertexes[start];
                    }
                }
            }
            visited_vertex.insert(start);
            int min = INT32_MAX; 
            const int last = start;
            for (int i = 2; i < vertexes.size(); i++)
            {
                if (vertexes[i] < min && (visited_vertex.end() == visited_vertex.find(i)))
                {
                    min = vertexes[i];
                    start = i;
                }
            }
            if (last == start)
                break;
        }
        return vertexes[n];
    }
};
#endif

class Solution {
public:
    int minScore(int n, std::vector<std::vector<int>>& roads) {
        std::unordered_map<int, std::map<int, int>> graph;
        for(int i = 1; i < n+1; i++)
            graph[i] = {};
        for(auto & value: roads)
        {
            graph[value[0]][value[2]] = value[1];
            graph[value[1]][value[2]] = value[0];
        }

        std::stack<int> vertexes;
        std::set<int> visited_vertex;
        int start = 1;

        int answerMin = INT32_MAX;
        while(true)
        {
            for(auto & value : graph[start])
            {
                if (visited_vertex.end() == visited_vertex.find(value.second))
                {
                    if (value.first < answerMin)
                            answerMin = value.first;
                    vertexes.push(value.second);
                }
            }
            visited_vertex.insert(start);
            int min = INT32_MAX; 
            const int last = start;
            while (!vertexes.empty())
            {
                int tmp = vertexes.top();
                vertexes.pop();
                if (visited_vertex.end() == visited_vertex.find(tmp))
                {
                    start = tmp;
                    break;
                }
            }            

            if (last == start)
                break;
        }
        return answerMin;
    }
};

/*
Input: n = 4, roads = [[1,2,9],[2,3,6],[2,4,5],[1,4,7]]
Output: 5
Explanation: The path from city 1 to 4 with the minimum score is: 1 -> 2 -> 4. The score of this path is min(9,5) = 5.
It can be shown that no other path has less score.

Input: n = 4, roads = [[1,2,2],[1,3,4],[3,4,7]]
Output: 2
Explanation: The path from city 1 to 4 with the minimum score is: 1 -> 2 -> 1 -> 3 -> 4. The score of this path is min(2,2,4,7) = 2.
*/
int main() 
{
    Solution a;
    {
        std::vector<std::vector<int>> roads = {{1,2,9},{2,3,6},{2,4,5},{1,4,7}};
        int n = 4;
        int answer = 5;
        assert(answer == a.minScore(n, roads));
    }

    {
        std::vector<std::vector<int>> roads = {{1,2,2},{1,3,4},{3,4,7}};
        int n = 4;
        int answer = 2;
        assert(answer == a.minScore(n, roads));
    }

    {
        std::vector<std::vector<int>> roads = {{18,20,9207},{14,12,1024},{11,9,3056},{8,19,416},{3,18,5898},{17,3,6779},{13,15,3539},{15,11,1451},{19,2,3805},{9,8,2238},{1,16,618},{16,14,55},{17,7,6903},{12,13,1559},{2,17,3693}};
        int n = 20;
        int answer = 55;
        assert(answer == a.minScore(n, roads));
    }

    std::cout << "Test done" << std::endl;
    return 0;
}