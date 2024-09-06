#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=135 lang=cpp
 *
 * [135] 分发糖果
 */

// @lc code=start
class Solution
{
public:
    int candy(vector<int> &ratings)
    {
        int result = 0;
        int nums = ratings.size();
        vector<int> candyVec(nums, 1);
        for (int i = 1; i < ratings.size(); i++)
        {
            if (ratings[i] > ratings[i - 1])
            {
                candyVec[i] = candyVec[i - 1] + 1;
                // result++;
            }
        }

        for (int i = ratings.size() - 2; i >= 0; i--)
        {
            if (ratings[i] > ratings[i + 1])
            {
                candyVec[i] = max(candyVec[i], candyVec[i + 1] + 1);
                // result++;
            }
        }
        for (int candys : candyVec)
        {
            result += candys;
        }
        return result;
    }
};
// @lc code=end
