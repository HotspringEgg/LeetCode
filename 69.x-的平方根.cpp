/*
 * @lc app=leetcode.cn id=69 lang=cpp
 *
 * [69] x 的平方根 
 */

// @lc code=start
class Solution {
public:
    int mySqrt(int x) {
        int left = 0, right = x;
        int ans = -1;
        while (left <= right)
        {
            int mid = left + (right - left)/2;
            if((long long)mid * mid > x){
                right = mid - 1;
                // cout << "1";
            }else if ((long long)mid * mid <= x)
            {
                left = mid + 1;
                ans = mid;
                // cout << "1";
            }
                // cout << mid;
        }

        return ans;
    }
};
// @lc code=end

