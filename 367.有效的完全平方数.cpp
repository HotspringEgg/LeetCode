/*
 * @lc app=leetcode.cn id=367 lang=cpp
 *
 * [367] 有效的完全平方数
 */

// @lc code=start
class Solution {
public:
    bool isPerfectSquare(int num) {
        int l = 0, r = num;
        while (l <= r)
        {
            int mid = l + (r - l) / 2;
            if ((long long)mid * mid > num)
            {
                r = mid - 1;
            }else if ((long long)mid * mid < num)
            {
                l = mid + 1;
            }else return true;
        }
        return false;
    }
};
// @lc code=end

