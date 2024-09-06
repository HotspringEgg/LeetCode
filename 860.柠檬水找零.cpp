/*
 * @lc app=leetcode.cn id=860 lang=cpp
 *
 * [860] 柠檬水找零
 */

// @lc code=start
class Solution
{
public:
    bool lemonadeChange(vector<int> &bills)
    {
        int five = 0, ten = 0, twenty = 0;
        for (int bill : bills)
        {
            //1. 收5块
            if (bill == 5)
            {
                five++;
            }
            // 2. 收10块
            if (bill == 10)
            {
                if (five <= 0)
                {
                    return false;
                }
                five--;
                ten++;
            }
            // 3. 收20块
            if (bill == 20)
            {
                if (ten >0 && five > 0)
                {
                    ten--;
                    five--;
                }
                else if (five >= 3)
                {
                    five -= 3;
                }
                else{
                    return false;
                }
            }
        }
        return true;
    }
};
// @lc code=end
