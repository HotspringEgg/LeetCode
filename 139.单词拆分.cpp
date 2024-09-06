#include <string>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=139 lang=cpp
 *
 * [139] 单词拆分
 */

// @lc code=start
class Solution
{
public:
    // vector<string> wordDict = {"leet", "code"};

    // 我愿称之为围这箭画靶，在字符串末尾找长度为 wordDict[i] 的子串，并与wordDict[i]意义对比
    bool wordBreak(string s, vector<string> &wordDict)
    {
        // s = "leetcode";
        vector<bool> dp(s.size() + 1, false);
        dp[0] = true;
        // 遍历字符串
        for (int i = 1; i <= s.size(); i++)
        { // 遍历字典
            for (int j = 0; j < wordDict.size(); j++)
            {
                int length = wordDict[j].size();
                if (i >= length)
                {
                    // 求最后长为length的子串
                    string str = s.substr(i - length, length);
                    if (str == wordDict[j] && dp[i - length])
                    {
                        dp[i] = true;
                        // break; // 一旦找到一个匹配的单词，就可以停止内层循环
                    }
                }
            }
            // for (int j = 0; j <= s.size(); j++)
            // {
            //     cout << dp[j];
            // }
            // cout << endl;
        }
        return dp[s.size()];
    }
};
// @lc code=end
