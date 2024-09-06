/*
 * @lc app=leetcode.cn id=455 lang=cpp
 *
 * [455] 分发饼干
 */

// @lc code=start
class Solution
{
public:
    int findContentChildren(vector<int> &g, vector<int> &s)
    {
        if (s.size() == 0)
        {
            return 0;
        }

        // 小孩
        sort(g.begin(), g.end());
        // 饼干
        sort(s.begin(), s.end());

        int num = 0;
        
        for (int i = g.size() - 1; i >= 0; i--)
        {
            if (!s.empty() && s.back() >= g[i])
            {
                num++;
                s.pop_back();
            }
        }
        return num;
    }
};
// @lc code=end
