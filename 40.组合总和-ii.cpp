/*
 * @lc app=leetcode.cn id=40 lang=cpp
 *
 * [40] 组合总和 II
 */

// @lc code=start
class Solution
{
public:
    int targetSum;

    vector<int> path;

    vector<vector<int>> result;

    void backtracking(vector<int> &candidates, int targetSum, int sum, int startIndex)
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
        for (int i = startIndex; i < candidates.size() && sum + candidates[i] <= targetSum; i++)
        {
            //此处为去重操作
            //eg:对于集合[1 1 1 2]求3
            //首次取1时，111，12集合均被记入过，故不需要遍历二号1和三号1
            if (i > startIndex && candidates[i] == candidates[i - 1])
            {
                continue;
            }

            sum += candidates[i];
            path.push_back(candidates[i]);
            // 本题可以选择重复元素，故i不用+1
            backtracking(candidates, targetSum, sum, i + 1);
            sum -= candidates[i];
            path.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        sort(candidates.begin(), candidates.end());
        backtracking(candidates, target, 0, 0);
        return result;
    }
};
// @lc code=end
