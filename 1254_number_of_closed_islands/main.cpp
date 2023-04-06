#include <iostream>
#include <cassert>
#include <vector>
#include <unordered_set>
#include <unordered_map>

class Solution {
    int m;
    int n;

void dfs(std::vector<std::vector<int>>& grid, int i, int j)
{
    if (i < 0 || i >=m || j < 0 || j >= n || grid[i][j] == 1)
        return;
    
    grid[i][j] = 1;

    dfs(grid, i,j-1);    
    dfs(grid, i,j+1);
    dfs(grid, i-1,j);
    dfs(grid, i+1,j);    
}
public:

    int closedIsland(std::vector<std::vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        for(int i = 0; i < m; i++)
        {
            dfs(grid, i, 0);
            dfs(grid, i, n-1);
        }

        for (int j = 0; j < n; j++)
        {
            dfs(grid, 0  ,j);
            dfs(grid, m-1,j);
        }
        int count = 0;
        for(int i = 1; i < m-1; i++)
        {
            for(int j = 1; j<n-1; j++)
            {
                if (grid[i][j] == 0)
                {
                    count++;
                    dfs(grid, i, j);
                }
            }
        }
        return count;
    }
};


int main() 
{
    Solution a;
    {
        std::vector<std::vector<int>> grid = {{1,1,1,1,1,1,1,0},
                                              {1,0,0,0,0,1,1,0},
                                              {1,0,1,0,1,1,1,0},
                                              {1,0,0,0,0,1,0,1},
                                              {1,1,1,1,1,1,1,0}};
        int answer = 2;
        assert(answer == a.closedIsland(grid));
    }
    {
        std::vector<std::vector<int>> grid = {{0,0,1,0,0},
                                              {0,1,0,1,0},
                                              {0,1,1,1,0}};
        int answer = 1;
        assert(answer == a.closedIsland(grid));
    }
    {
        std::vector<std::vector<int>> grid = {{1,1,1,1,1,1,1},
                                              {1,0,0,0,0,0,1},
                                              {1,0,1,1,1,0,1},
                                              {1,0,1,0,1,0,1},
                                              {1,0,1,1,1,0,1},
                                              {1,0,0,0,0,0,1},
                                              {1,1,1,1,1,1,1}};
        int answer = 2;
        assert(answer == a.closedIsland(grid));
    }
    

    

    std::cout << "Test done" << std::endl;
    return 0;
}