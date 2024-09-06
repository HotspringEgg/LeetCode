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
        s = "the sky is blue";
        int slow = 0;
        for (int fast = 0; fast < s.size(); fast++)
        {
            if (s[fast] != ' ')
            {
                if (slow != 0)
                {
                    s[slow++] = ' ';
                    // continue;
                }
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
        for (int i = 0; i <= s.size(); i++)
        {
            if (s[i] == ' ' || i == s.size())
            {
                for (int a = start, b = i - 1; a < b; a++, b--)
                {
                    swap(s[a], s[b]);
                }
                start = i + 1;
            }
            
        }

        return s;
    }
};

int main()
{
    Solution solution;

    std::cout << solution.reverseWords(" ");
}
// @lc code=end
