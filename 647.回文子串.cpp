#include <string>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=647 lang=cpp
 *
 * [647] 回文子串
 */

// @lc code=start
class Solution
{
public:
    int countSubstrings(string s)
    {
        int num = s.size();
        vector<vector<bool>> dp(num, vector<bool>(num, false));

        int result = 0;

        for (int i = num - 1; i >= 0; i--)
        {
            for (int j = i; j < num; j++)
            {
                if (s[i] == s[j])
                {
                    if (j - i <= 1)
                    {
                        dp[i][j] = true;
                        result++;
                    }
                    else if (dp[i + 1][j - 1] == true)
                    {
                        dp[i][j] = true;
                        result++;
                    }
                }
            }
        }
        return result;
    }
};
// @lc code=end
