#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
/*
 * @lc app=leetcode.cn id=151 lang=cpp
 *
 * [151] 反转字符串中的单词
 */

// @lc code=start
class Solution
{
public:
    string reverseWords(string s)
    {
        int slow = 0;
        // s = " asdasd df f";
        // 规整字符串
        for (int fast = 0; fast < s.size(); fast++)
        {
            if (s[fast] != ' ')
            {
                // 若非第一个单词则中间留空格
                if (slow != 0)
                {
                    s[slow] = ' ';
                    slow++;
                }

                // 处理整个单词
                while (s[fast] != ' ' && fast < s.size())
                {
                    s[slow] = s[fast];
                    fast++;
                    slow++;
                }
            }
        }

        s.resize(slow);
        reverse(s.begin(), s.end());

        int start = 0;
        // reverse(s.begin() + start, s.begin() + 4);
        for (int i = 0; i <= s.size(); i++)
        {
            if (s[i] == ' ' || i == s.size())
            {
                reverse(s.begin() + start, s.begin() + i);
                start = i + 1;
            }
        }
        // cout << s <<endl;
        return s;
    }
};
// @lc code=end
// string reverseWords(string s)
// {
//     int slow = 0;
//     for (int fast = 0; fast < s.size(); fast++)
//     {
//         if (s[fast] != ' ')
//         {
//             if (slow != 0)
//             {
//                 s[slow++] = ' ';
//                 // continue;
//             }
//             while (s[fast] != ' ' && fast < s.size())
//             {
//                 s[slow] = s[fast];
//                 fast++;
//                 slow++;
//             }
//         }
//     }
//     s.resize(slow);

//     reverse(s.begin(), s.end());

//     int start = 0;
//     for (int i = 0; i <= s.size(); i++)
//     {
//         if (s[i] == ' ' || i == s.size())
//         {
//             for (int a = start, b = i - 1; a < b; a++, b--)
//             {
//                 swap(s[a], s[b]);
//             }
//             start = i + 1;
//         }
//     }

//     return s;
// }