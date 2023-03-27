#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>

/*fast way*/
#if 1
class Solution {
public:
    int minPathSum(std::vector<std::vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        for (int i = 1; i < m; i++) {
            grid[i][0] += grid[i-1][0];
        }
        
        for (int j = 1; j < n; j++) {
            grid[0][j] += grid[0][j-1];
        }
        
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                grid[i][j] += std::min(grid[i-1][j], grid[i][j-1]);
            }
        }
        
        return grid[m-1][n-1];
    }
};
#endif

/*my slow way*/
#if 0
class Solution {
public:
    struct edge
    {
        int target;
        int wight;
    };
    int minPathSum(std::vector<std::vector<int>>& grid) {
        const int n = grid.size()* grid[0].size();
        std::vector<std::vector<edge>> graph(n+1);
        int columnAmount = grid[0].size();
        int rowAmount = grid.size();
        int numberCell = 0;
        for(auto itRow = grid.begin(); itRow != std::prev(grid.end(), 1); itRow++)
        {
            for(auto itCell = (*itRow).begin(); itCell != std::prev((*itRow).end(), 1); itCell++)
            {
                graph[numberCell].push_back({numberCell+1, *itCell});
                graph[numberCell].push_back({numberCell+columnAmount, *itCell});
                numberCell++;
            }
            graph[numberCell].push_back({numberCell+columnAmount, (*itRow).back()});
            numberCell++;
        }

        for(auto itCell = grid.back().begin(); itCell != grid.back().end(); itCell++)
        {
            graph[numberCell].push_back({numberCell+1, *itCell});
            numberCell++;
        }

        std::vector<int> vertexes(n+1, INT32_MAX);
        std::vector<int> visited(n+1, false);
        int start = 0;
        vertexes[start] = 0;
        while(true)
        {
            for(auto & value : graph[start])
            {
                if (false == visited[value.target])
                {
                    if (vertexes[start]+value.wight < vertexes[value.target])
                    {
                        vertexes[value.target] = vertexes[start]+value.wight;
                    }
                }
            }
            visited[start] = true;
            int min = INT32_MAX; 
            const int last = start;
            for (int i = 1; i < vertexes.size(); i++)
            {
                if (vertexes[i] < min && (false == visited[i]))
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

/*
Input: grid = [[1,3,1],[1,5,1],[4,2,1]]
Output: 7
Explanation: Because the path 1 → 3 → 1 → 1 → 1 minimizes the sum.

Input: grid = [[1,2,3],[4,5,6]]
Output: 12
*/

int main() 
{
    Solution a;
    {
        std::vector<std::vector<int>> grid = {{1,3,1},{1,5,1},{4,2,1}};
        int answer = 7;
        assert(answer == a.minPathSum(grid));
    }

    {
        std::vector<std::vector<int>> grid =  {{1,2,3},{4,5,6}};
        int answer = 12;
        assert(answer == a.minPathSum(grid));
    }

    std::cout << "Test done" << std::endl;
    return 0;
}