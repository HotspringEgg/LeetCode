#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;
/*
 * @lc app=leetcode.cn id=698 lang=cpp
 *
 * [698] 划分为k个相等的子集
 */

// @lc code=start
class Solution
{
public:
    // 5433221
    // 113 2 1
    // 
    vector<int> nums;
    vector<int> result;
    int target;

    bool backtrack(int startIndex, int k, int currentSum, vector<bool> used)
    {
        if (k == 0)
            return true; // 成功创建了 k 个子集

        if (currentSum == target)
        {
            // 当前子集完成，开始创建下一个子集
            return backtrack(0, k - 1, 0, used);
        }

        for (int i = startIndex; i < nums.size(); i++)
        {
            if (used[i] || currentSum + nums[i] > target)
                continue;
            used[i] = true;
            if (backtrack(i + 1, k, currentSum + nums[i], used))
                return true;
            used[i] = false;
            if (currentSum == 0)
                break; // 避免用相同的数开始新子集
        }
        return false;
    }
    bool canPartitionKSubsets(vector<int> &nums, int k)
    {
        this->nums = nums;
        // 1. 求和
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % k != 0)
        {
            return false;
        }
        // 求目标值
        target = sum / k;

        // 2. 从大到小排序
        // 3. 排除后面大于目标值的数，(剪枝操作)
        sort(nums.rbegin(), nums.rend());
        if (nums[0] > target)
        {
            return false;
        }
        // （类似找零钱的问题？用贪心？）
        // 4. 回溯算法求解
        vector<bool> used(nums.size(), false);

        return backtrack(0, k, 0, used);
    }
};
// @lc code=end
