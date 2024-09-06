#include <string>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=516 lang=cpp
 *
 * [516] 最长回文子序列
 */

// @lc code=start
class Solution
{
public:
    int longestPalindromeSubseq(string s)
    {
        int num = s.size();
        vector<vector<int>> dp(num, vector<int>(num, false));

        for (int i = 0; i < num; i++)
        {
            dp[i][i] = 1;
        }

        for (int i = num - 1; i >= 0; i--)
        {
            for (int j = i + 1; j < num; j++)
            {
                if (s[i] == s[j])
                {
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                }
                else
                {
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[0][num - 1];
    }
};
// @lc code=end