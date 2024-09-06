/*
 * @lc app=leetcode.cn id=3144 lang=cpp
 *
 * [3144] 分割字符频率相等的最少子字符串
 */

// @lc code=start
class Solution
{
public:
    int minimumSubstringsInPartition(string s)
    {
        unordered_map<char, int> freqMap;
        int count = 0;
        int distinctCharCount = 0;

        for (char c : s)
        {
            // 增加当前字符的计数
            freqMap[c]++;
            if (freqMap[c] == 1)
            {
                distinctCharCount++;
            }

            // 检查当前子字符串是否是平衡的
            bool isBalanced = true;
            int firstCharFreq = freqMap[s[0]];
            for (const auto &entry : freqMap)
            {
                if (entry.second != firstCharFreq)
                {
                    isBalanced = false;
                    break;
                }
            }

            // 如果当前子字符串是平衡的
            if (isBalanced)
            {
                count++;
                freqMap.clear();
            }
        }

        return count;
    }
};
// @lc code=end
