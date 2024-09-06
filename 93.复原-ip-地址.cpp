/*
 * @lc app=leetcode.cn id=93 lang=cpp
 *
 * [93] 复原 IP 地址
 */

// @lc code=start
class Solution
{
public:
    vector<string> result;
    string path;
    // 自己写的
    //  bool isValid(string &s, int start, int end)
    //  {
    //      int len = end - start + 1;
    //      if (len >= 4 || len == 0)
    //      {
    //          return false;
    //      }

    //     string substr = s.substr(start, len);
    //     if (substr[0] == '0' && len != 1)
    //     {
    //         return false;
    //     }

    //     if (stoi(substr) > 255)
    //     {
    //         return false;
    //     }

    //     return true;
    // }

    bool isValid(string &s, int start, int end)
    {
        // 回溯算法中有i+2，所以start可能会大于end
        if (start > end)
        {
            return false;
        }
        if (s[start] == '0' && start != end)
        { // 0开头的数字不合法
            return false;
        }
        int num = 0;
        for (int i = start; i <= end; i++)
        {
            if (s[i] > '9' || s[i] < '0')
            { // 遇到非数字字符不合法
                return false;
            }
            num = num * 10 + (s[i] - '0');
            if (num > 255)
            { // 如果大于255了不合法
                return false;
            }
        }
        return true;
    }

    void backtracking(string &s, int startIndex, int dotNum)
    {
        if (dotNum >= 3)
        {
            // 判断最后一段是否合法
            if (isValid(s, startIndex, s.size() - 1))
            {
                result.push_back(s);
            }
            return;
        }
        for (int i = startIndex; i < s.size(); i++)
        {
            // 判断即将被分割的部分是否合法
            if (isValid(s, startIndex, i))
            {
                s.insert(s.begin() + i + 1, '.');
                dotNum++;
                // 递归深度+1，再算上'.'，所以此处+2
                backtracking(s, i + 2, dotNum);
                dotNum--;
                s.erase(s.begin() + i + 1);
            }
            // 中间一段不满足即整根枝条都不满足
            // eg:1921|68|0|0
            else
            {
                break;
            }
        }
    }

    vector<string> restoreIpAddresses(string s)
    {
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] > '9' || s[i] < '0')
            {
                return result;
            }
        }

        backtracking(s, 0, 0);
        return result;
    }
};
// @lc code=end
