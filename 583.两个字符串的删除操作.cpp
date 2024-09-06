#include <string>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=583 lang=cpp
 *
 * [583] 两个字符串的删除操作
 */

// @lc code=start
class Solution
{
public:
    int minDistance(string word1, string word2)
    {
        int num1 = word1.size();
        int num2 = word2.size();
        // dp[i][j] 使两字符串 word1[i-1] word2[j-1]相同的最小操作数
        vector<vector<int>> dp(num1 + 1, vector<int>(num2 + 1, 0));

        // 初始化
        for (int i = 0; i <= num1; i++)
        {
            dp[i][0] = i;
        }

        for (int j = 0; j <= num2; j++)
        {
            dp[0][j] = j;
        }

        for (int i = 1; i <= num1; i++)
        {
            for (int j = 1; j <= num2; j++)
            {
                if (word1[i - 1] == word2[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else
                {
                    // 对于dp表而言，只有dp[i][j] = dp[i - 1][j - 1]时，数值不发生变动，单独向下or向右都会+1
                    // 所以dp[i - 1][j - 1] + 2 一定是dp[i - 1][j] + 1, dp[i][j - 1] + 1其一
                    dp[i][j] = min(dp[i - 1][j] + 1, dp[i][j - 1] + 1);
                }
            }
        }
        return dp[num1][num2];

        // dp[i][j] 两字符串最长公共部分
        // vector<vector<int>> dp(num1 +1, vector<int>(num2 + 1, 0));

        // for (int i = 1; i <= num1; i++)
        // {
        //     for (int j = 1; j <= num2; j++)
        //     {
        //         if (word1[i - 1] == word2[j - 1])
        //         {
        //             dp[i][j] = dp[i - 1][j - 1] + 1;
        //         }
        //         else
        //         {
        //             dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        //         }
        //     }
        // }

        // return num1 - dp[num1][num2] + num2 - dp[num1][num2];
    }
};
// @lc code=end
