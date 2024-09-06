#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=59 lang=cpp
 *
 * [59] 螺旋矩阵 II
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> generateMatrix(int n)
    {
        // 8-24
        // 初始化容器
        vector<vector<int>> matrix(n, vector<int>(n, 0));
        int left = 0, right = n - 1, top = 0, bottom = n - 1;
        int num = 1, tar = n * n;
        while (num <= tar)
        {
            for (int i = left; i <= right; i++)
            {
                matrix[top][i] = num++;
            }
            top++;
            for (int i = top; i <= bottom; i++)
            {
                matrix[i][right] = num++;
            }
            right--;
            for (int i = right; i >= left; i--)
            {
                matrix[bottom][i] = num++;
            }
            bottom--;
            for (int i = bottom; i >= top; i--)
            {
                matrix[i][left] = num++;
            }
            left++;
        }
        return matrix;
    }
};
// @lc code=end

// 第一版
// //创建二维数组，每个元素初始化为0
// vector<vector<int>> matrix(n, vector<int>(n, 0));
// //起始x下标y坐标
// int startx = 0;
// int starty = 0;

// //完整循环次数
// int loop = n / 2;
// //中心点坐标
// int center = n / 2;

// int count = 1;
// //尾部偏移量
// int offset = 1;
// //行列
// int i, j = 0;
// while (loop--)
// {
//     i = startx;
//     j = starty;

//     for (j; j < n - offset; j++)
//     {
//         matrix[i][j] = count++;
//     }

//     for (i; i < n - offset; i++)
//     {
//         matrix[i][j] = count++;
//     }

//     for (; j > starty; j--)
//     {
//         matrix[i][j] = count++;
//     }

//     for (; i > startx; i--)
//     {
//         matrix[i][j] = count++;
//     }

//     startx++;
//     starty++;
//     offset++;
// }

// if (n % 2 == 1)
// {
//     matrix [center][center] = n * n;
// }

// return matrix;
