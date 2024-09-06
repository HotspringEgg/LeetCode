#include <vector>
#include <unordered_map>
using namespace std;
/*
 * @lc app=leetcode.cn id=454 lang=cpp
 *
 * [454] 四数相加 II
 */

// @lc code=start
class Solution
{
public:
    int fourSumCount(vector<int> &A, vector<int> &B, vector<int> &C, vector<int> &D)
    {
        int count = 0;
        int n = A.size();
        // 前两个数组相加之和出现的频次
        unordered_map<int, int> map;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                map[A[i] + B[j]]++;
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                count += map[0 - C[i] - D[j]];
            }
        }
        return count;
    }
};
// @lc code=end
// int fourSumCount(vector<int> &A, vector<int> &B, vector<int> &C, vector<int> &D)
// {
//     int count = 0;
//     unordered_map<int, int> map;
//     for (int a : A)
//     {
//         for (int b : B)
//         {
//             map[a + b]++;
//         }
//     }

//     for (int c : C)
//     {
//         for (int d : D)
//         {
//             if (map.find(-(c + d)) != map.end())
//             {
//                 count += map[-(c + d)];
//             }
//         }
//     }

//     return count;
// }