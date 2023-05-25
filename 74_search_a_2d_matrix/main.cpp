#include <iostream>
#include <cassert>
#include <vector>

/*
https://leetcode.com/problems/search-a-2d-matrix/description/
*/

class Solution {
public:
    bool searchMatrix(std::vector<std::vector<int>>& matrix, int target) {
        int start = 0;
        const int m = matrix[0].size();
        const int n = matrix.size();
        int end = m * n - 1;
        
        while (start <= end)
        {
        	int mid = (start+end)/2;
        	int row = mid/m;
        	int cow = mid%m;
        	if (matrix[row][cow] == target)
        		return true;
        	else if (matrix[row][cow] < target)
        		start = mid+1;
        	else
        		end = mid-1;
        	
        }
        return false;
    }
};

int main() 
{
    Solution a;
    {
        std::vector<std::vector<int>> matrix = {{1,3,5,7},{10,11,16,20},{23,30,34,60}};
        int target = 3;
        bool answer = true;
        assert(answer == a.searchMatrix(matrix, target));
    }
    {
        std::vector<std::vector<int>> matrix = {{1,3,5,7},{10,11,16,20},{23,30,34,60}};
        int target = 13;
        bool answer = false;
        assert(answer == a.searchMatrix(matrix, target));
    }
    {
        std::vector<std::vector<int>> matrix = {{1, 3}};
        int target = 3;
        bool answer = true;
        assert(answer == a.searchMatrix(matrix, target));
    }
    {
        std::vector<std::vector<int>> matrix = {{1, 2, 3}};
        int target = 3;
        bool answer = true;
        assert(answer == a.searchMatrix(matrix, target));
    }
    std::cout << "Test done" << std::endl;
    return 0;
}