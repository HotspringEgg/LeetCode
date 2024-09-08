#include <string>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=28 lang=cpp
 *
 * [28] 找出字符串中第一个匹配项的下标
 */

// @lc code=start

//    j
//        i
// ABACABAB
// 00101232
// 00101232
class Solution
{
public:
    void getNext(string &needle, vector<int> &next)
    {
        int j = 0;
        for (int i = 1; i < needle.size(); i++)
        {
            while (j > 0 && needle[i] != needle[j])
            {
                j = next[j - 1];
            }
            if (needle[i] == needle[j])
            {
                j++;
            }
            next[i] = j;
        }
    }

    int strStr(string haystack, string needle)
    {
        if (needle.size() == 0)
        {
            return 0;
        }

        // needle = "ABACABAB";
        vector<int> next(needle.size(), 0);
        getNext(needle, next);

        int j = 0;
        for (int i = 0; i < haystack.size(); i++)
        {
            while (j > 0 && haystack[i] != needle[j])
            {
                j = next[j - 1];
            }
            if (haystack[i] == needle[j])
            {
                j++;
            }
            if (j == needle.size())
            {
                return i - j + 1;
            }
        }

        return -1;
    }
};
// @lc code=end
// void getNext(int *next, string &s)
// {
//     int j = 0;
//     next[0] = 0;
//     for (int i = 1; i < s.size(); i++)
//     {
//         while (j > 0 && s[i] != s[j])
//         {
//             j = next[j - 1];
//         }
//         if (s[i] == s[j])
//         {
//             j++;
//         }
//         next[i] = j;
//     }
// }

// int strStr(string haystack, string needle)
// {
//     if (needle.size() == 0)
//     {
//         return 0;
//     }

//     vector<int> next(needle.size());

//     getNext(&next[0], needle);
//     int j = 0;
//     for (int i = 0; i < haystack.size(); i++)
//     {
//         while (j > 0 && haystack[i] != needle[j])
//         {
//             j = next[j - 1];
//         }
//         if (haystack[i] == needle[j])
//         {
//             j++;
//         }
//         if (j == needle.size())
//         {
//             return (i - needle.size() + 1);
//         }
//     }
//     return -1;
// }