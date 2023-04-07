#include <iostream>
#include <cassert>
#include <vector>
class Solution {
int m;
int n;
void dfs(std::vector<std::vector<int>>& grid, int i, int j)
{
	if (i < 0||i >= m||j < 0||j>=n||grid[i][j]==0)
		return;
	grid[i][j] = 0;

	dfs(grid,i ,j+1);
	dfs(grid,i ,j-1);
	dfs(grid,i+1 ,j);
	dfs(grid,i-1 ,j);
}
public:
    int numEnclaves(std::vector<std::vector<int>>& grid) {
  	m = grid.size();
  	n = grid[0].size();
    for(int i = 0; i < m; i++)
    {
        dfs(grid, i, 0);
        dfs(grid, i, n-1);
    }
    for(int j = 0; j < n; j++)
    {
        dfs(grid, 0,   j);        
        dfs(grid, m-1, j);
    }

  	int answer = 0;
  	for(int i = 0; i <m; i++)
  	{
  		for(int j = 0; j <n; j++)
  		{
  			if (grid[i][j]==1)
  			{
                answer++;
  			}
  		}
  	}
  	return answer;
    }
};
int main() 
{
    Solution a;
    {
        std::vector<std::vector<int>> grid = {{0,0,0,0},
                                              {1,0,1,0},
                                              {0,1,1,0},
                                              {0,0,0,0}};
        int answer = 3;
        assert(answer == a.numEnclaves(grid));
    }
    {
        std::vector<std::vector<int>> grid = {{0,0,0,1,1,1,0,1,0,0},
                                              {1,1,0,0,0,1,0,1,1,1},
                                              {0,0,0,1,1,1,0,1,0,0},
                                              {0,1,1,0,0,0,1,0,1,0},
                                              {0,1,1,1,1,1,0,0,1,0},
                                              {0,0,1,0,1,1,1,1,0,1},
                                              {0,1,1,0,0,0,1,1,1,1},
                                              {0,0,1,0,0,1,0,1,0,1},
                                              {1,0,1,0,1,1,0,0,0,0},
                                              {0,0,0,0,1,1,0,0,0,1}};
        int answer = 3;
        assert(answer == a.numEnclaves(grid));
    }
    std::cout << "Test done" << std::endl;
    return 0;
}