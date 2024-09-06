#include <algorithm>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=746 lang=cpp
 *
 * [746] 使用最小花费爬楼梯
 */

// @lc code=start
class Solution
{
public:
    int minCostClimbingStairs(vector<int> &cost)
    {
        int size = cost.size();
        int totalCost[size + 1];
        totalCost[0] = 0;
        totalCost[1] = 0;
        // totalCost[2] = 0;

        for (int i = 2; i <= size; i++)
        {
            totalCost[i] = min(totalCost[i - 2] + cost[i - 2], totalCost[i - 1] + cost[i - 1]);
        }

        return totalCost[size];
    }
};
// @lc code=end
