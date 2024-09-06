#include <string>
using namespace std;
/*
 * @lc app=leetcode.cn id=3146 lang=cpp
 *
 * [3146] 两个字符串的排列差
 */

// @lc code=start
class Solution
{
public:
    // 关键点1: 字符串字符不重复
    int findPermutationDifference(string s, string t)
    {
        int result = 0;
        int range[26];

        // 记录每个字母在字符串s中的所在位置
        for (int i = 0; i < s.size(); i++)
        {
            range[s[i] - 'a'] = i;
        }

        for (int i = 0; i < t.size(); i++)
        {
            result += abs(range[t[i] - 'a'] - i);
        }

        return result;
    }
};
// @lc code=end
