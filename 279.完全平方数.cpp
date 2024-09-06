#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=279 lang=cpp
 *
 * [279] 完全平方数
 */

// @lc code=start
class Solution
{
public:
    int numSquares(int n)
    {
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;

        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= n; j++)
            {
                if (j >= (i * i) && dp[j - (i * i)] != INT_MAX)
                {
                    dp[j] = min(dp[j], dp[j - (i * i)] + 1);
                }
            }
        }

        if (dp[n] != INT_MAX)
        {
            return dp[n];
        }

        return 0;
    }
};
// @lc code=end
