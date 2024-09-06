#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=552 lang=cpp
 *
 * [552] 学生出勤记录 II
 */

// @lc code=start
class Solution
{
public:
    int checkRecord(int n)
    {
        static constexpr int MOD = 1'000'000'007;
        // dp[i][j][k]第i天 一共缺席j次 连续迟到k次还能获奖的数量
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3, 0)));
        dp[0][0][0] = 1;
        for (int i = 1; i < n + 1; i++)
        {
            // 以P结尾
            // 若以P结尾，则连续迟到天数即k = 0，故求的dp[i][j][0]
            for (int j = 0; j  <2; j++)
            {
                for (int k = 0; k < 3; k++)
                {
                    dp[i][j][0] = (dp[i][j][0] + dp[i - 1][j][k]) % MOD;
                }
            }

            // 以A结尾
            // 若以A结尾，则i-1时，j只可为0，且第i天j为1，k为0
            for (int k = 0; k < 3; k++)
            {
                dp[i][1][0] = (dp[i][1][0] + dp[i - 1][0][k]) % MOD;
            }

            // 以L结尾
            // 若以L结尾，则i-1时，k可以为0或1，且第i天k至少为1
            for (int j = 0; j < 2; j++)
            {
                for (int k = 1; k < 3; k++)
                {
                    dp[i][j][k] = (dp[i][j][k] + dp[i - 1][j][k - 1]) % MOD;
                }
            }
        }

        int sum = 0;

        for (int j = 0; j < 2; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                sum = (sum + dp[n][j][k]) % MOD;
            }
        }
        return sum;
    }
};
// @lc code=end
