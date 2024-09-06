#include <string>
using namespace std;
/*
 * @lc app=leetcode.cn id=551 lang=cpp
 *
 * [551] 学生出勤记录 I
 */

// @lc code=start
class Solution
{
public:
    bool checkRecord(string s)
    {
        int ANum = 0;
        int LNum = 0;
        int LMax = 0;

        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == 'A')
            {
                ANum++;
                LNum = 0;
            }
            else if (s[i] == 'L')
            {
                LNum++;
                LMax = max(LMax, LNum);
            }
            else
            {
                LNum = 0;
            }
        }
        return (ANum < 2) && (LMax < 3);
    }
};
// @lc code=end
