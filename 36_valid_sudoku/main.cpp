#include <iostream>
#include <cassert>
#include <vector>

/*
https://leetcode.com/problems/valid-sudoku/description/
*/

class Solution {
public:
    bool isValidSudoku(std::vector<std::vector<char>>& board) {
        uint8_t columns[9][9] = {};        
        uint8_t squares[3][9] = {};
        for(int i = 0; i < board.size(); i++)
        {
            uint8_t row[9] = {};
            if (i %3 == 0)
                std::fill(&squares[0][0], &squares[0][0]+sizeof(squares), 0);
                
            for(int j = 0; j < board[0].size(); j++)
            {
                if (board[i][j] != '.')
                {
                    uint8_t val = board[i][j] - '1';
                    if (row[val] == 1)
                        return false;
                    else
                        row[val] = 1;

                    if(columns[j][val] == 1)
                        return false;
                    else
                        columns[j][val] = 1;

                    if (squares[j/3][val] == 1)
                        return false;
                    else
                        squares[j/3][val] = 1;
                }
            }

        }
        return true;
    }
};
int main() 
{
    Solution a;
    {
        std::vector<std::vector<char>> board = {{'5','3','.','.','7','.','.','.','.'},
                                                {'6','.','.','1','9','5','.','.','.'},
                                                {'.','9','8','.','.','.','.','6','.'},
                                                {'8','.','.','.','6','.','.','.','3'},
                                                {'4','.','.','8','.','3','.','.','1'},
                                                {'7','.','.','.','2','.','.','.','6'},
                                                {'.','6','.','.','.','.','2','8','.'},
                                                {'.','.','.','4','1','9','.','.','5'},
                                                {'.','.','.','.','8','.','.','7','9'}};
        bool answer = true;
        assert(answer == a.isValidSudoku(board));
    }
    {
        std::vector<std::vector<char>> board = {{'8','3','.','.','7','.','.','.','.'},
                                                {'6','.','.','1','9','5','.','.','.'},
                                                {'.','9','8','.','.','.','.','6','.'},
                                                {'8','.','.','.','6','.','.','.','3'},
                                                {'4','.','.','8','.','3','.','.','1'},
                                                {'7','.','.','.','2','.','.','.','6'},
                                                {'.','6','.','.','.','.','2','8','.'},
                                                {'.','.','.','4','1','9','.','.','5'},
                                                {'.','.','.','.','8','.','.','7','9'}};
        bool answer = false;
        assert(answer == a.isValidSudoku(board));
    }
    std::cout << "Test done" << std::endl;
    return 0;
}