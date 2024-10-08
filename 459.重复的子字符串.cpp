#include <string>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=459 lang=cpp
 *
 * [459] 重复的子字符串
 */

// @lc code=start
class Solution
{
public:
    void getNext(vector<int> &next, string &s)
    {
        int j = 0;
        for (int i = 1; i < s.size(); i++)
        {
            while (j > 0 && s[j] != s[i])
            {
                j = next[j - 1];
            }
            if (s[j] == s[i])
            {
                j++;
            }
            next[i] = j;
        }
    }

    bool repeatedSubstringPattern(string s)
    {
        vector<int> next(s.size());
        getNext(next, s);
        int len = s.size();
        if (next[len - 1] != 0 && len % (len - next[len - 1]) == 0)
        {
            return true;
        }
        return false;
    }
};
// @lc code=end
// void getNext(vector<int> &next, string &s)
// {
//     int j = 0;
//     for (int i = 1; i < s.size(); i++)
//     {
//         while (j > 0 && s[j] != s[i])
//         {
//             j = next[j - 1];
//         }
//         if (s[j] == s[i])
//         {
//             j++;
//         }
//         next[i] = j;
//     }
// }

// bool repeatedSubstringPattern(string s)
// {
//     vector<int> next(s.size());
//     getNext(next, s);
//     int len = s.size();
//     if (next[len - 1] != 0 && len % (len - (next[len - 1])) == 0)
//     {
//         return true;
//     }
//     return false;
// }