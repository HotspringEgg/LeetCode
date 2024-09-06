/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] 组合总和
 */

// @lc code=start
class Solution
{
public:
    int targetSum;

    vector<int> path;

    vector<vector<int>> result;
   
    void backtracking(vector<int> &candidates, int targetSum, int sum, int depth)
    {
        if (sum == targetSum)
        {
            result.push_back(path);
            return;
        }
        else if (sum > targetSum)
        {
            return;
        }

        // 需要使用当前的递归深度 depth 来控制候选数字的选择，使得后续递归中只考虑当前数字及其之后的数字。
        for (int i = depth; i < candidates.size(); i++)
        {
            sum += candidates[i];
            path.push_back(candidates[i]);
            //本题可以选择重复元素，故i不用+1
            backtracking(candidates, targetSum, sum, i);
            sum -= candidates[i];
            path.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        backtracking(candidates, target, 0, 0);
        return result;
    }
};
// @lc code=end
