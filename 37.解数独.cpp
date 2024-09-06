#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=37 lang=cpp
 *
 * [37] 解数独
 */

// @lc code=start
class Solution
{
public:
    // vector<vector<char>> board;

    bool isValid(int i, int j, char k, vector<vector<char>> &board)
    {
        // 遍历同行
        for (int col = 0; col < 9; col++)
        {
            if (board[i][col] == k)
            {
                return false;
            }
        }
        // 遍历同列
        for (int row = 0; row < 9; row++)
        {
            if (board[row][j] == k)
            {
                return false;
            }
        }
        // 遍历所在的3*3方格
        // 确定在第几个方格
        int startRow = (i / 3) * 3;
        int startCol = (j / 3) * 3;

        for (int row = startRow; row < startRow + 3; row++)
        {
            for (int col = startCol; col < startCol + 3; col++)
            {
                if (board[row][col] == k)
                {
                    return false;
                }
            }
        }
        return true;
    }

    bool backtracking(vector<vector<char>> &board)
    {
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] == '.')
                {
                    for (char k = '1'; k <= '9'; k++)
                    {
                        if (isValid(i, j, k, board))
                        {
                            board[i][j] = k;
                            if (backtracking(board))
                            {
                                return true;
                            }
                            board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        // 遍历完没有返回false，说明找到了合适棋盘位置了
        return true;
    }

    void solveSudoku(vector<vector<char>> &board)
    {
        backtracking(board);
    }
};
// @lc code=end
