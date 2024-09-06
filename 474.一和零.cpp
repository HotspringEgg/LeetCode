#include <vector>
#include <string>
using namespace std;
/*
 * @lc app=leetcode.cn id=474 lang=cpp
 *
 * [474] 一和零
 */

// @lc code=start
class Solution
{
public:
    int findMaxForm(vector<string> &strs, int m, int n)
    {
        m = 3;
        n = 3;
        // 默认初始化0
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        for (int i = 0; i < strs.size(); i++)
        {
            int ZeroNum = 0;
            int OneNum = 0;
            for (char c : strs[i])
            {
                if (c == '0')
                {
                    ZeroNum++;
                }
                else
                {
                    OneNum++;
                }
            }
            for (int j = m; j >= ZeroNum; j--)
            {
                for (int k = n; k >= OneNum; k--) 
                {
                    dp[j][k] = max(dp[j][k],  dp[j - ZeroNum][k - OneNum] + 1);
                }
            }
            // for (int j = 0; j <= m; j++)
            // {
            //     for (int k = 0; k <= n; k++)
            //     {
            //         cout << dp[j][k] << " ";
            //     }
            //     cout << endl;
            // }
            // cout << endl;
        }

        return dp[m][n];
    }
};
// @lc code=end
