#include <vector>
#include <string>
#include <algorithm>
using namespace std;
/*
 * @lc app=leetcode.cn id=763 lang=cpp
 *
 * [763] 划分字母区间
 */

// @lc code=start
class Solution
{
public:
    vector<int> partitionLabels(string s)
    {
        // 创建并初始化字母hash表
        int hash[27] = {0};
        for (int i = 0; i < s.size(); i++)
        {
            hash[s[i] - 'a'] = i;
        }
        vector<int> result;
        int right = 0;
        int left = 0;

        for (int i = 0; i < s.size(); i++)
        {
            /* code */
            right = max(hash[s[i] - 'a'], right);
            if (i == right)
            {
                result.push_back(right - left + 1);
                left = right + 1;
            }
        }
        return result;
    }
};
// @lc code=end
