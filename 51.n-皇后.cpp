/*
 * @lc app=leetcode.cn id=51 lang=cpp
 *
 * [51] N 皇后
 */

// @lc code=start
class Solution
{
public:
    vector<vector<string>> result;
    vector<string> path;

    bool isValid(int row, int col, int n)
    {
        // 检查同列
        for (int i = 0; i < row; i++)
        {
            if (path[i][col] == 'Q')
            {
                return false;
            }
        }
        

        // 检查右上角
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++)
        {
            if (path[i][j] == 'Q')
            {
                return false;
            }
        }

        // 检查左上角
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
        {
            if (path[i][j] == 'Q')
            {
                return false;
            }
        }
        return true;
    }

    void backtracking(int n, int row)
    {
        if (row == n)
        {
            result.push_back(path);
            return;
        }

        for (int col = 0; col < n; col++)
        {
            if (isValid(row, col, n))
            {
                path[row][col] = 'Q';
                backtracking(n, row + 1);
                path[row][col] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n)
    {
        path = vector<string>(n, string(n, '.'));
        backtracking(n, 0);
        return result;
    }
};
// @lc code=end
