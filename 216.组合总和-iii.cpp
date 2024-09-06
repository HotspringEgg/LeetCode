/*
 * @lc app=leetcode.cn id=216 lang=cpp
 *
 * [216] 组合总和 III
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> result;
    vector<int> path;

    void backtracking(int targetSum, int k, int sum, int startIndex)
    {
        if (path.size() == k && sum == targetSum)
        {
            result.push_back(path);
            return;
        }
        else if (path.size() < k)
        {
            for (int i = startIndex; i <= 9; i++)
            {
                sum += i;
                path.push_back(i);
                backtracking(targetSum, k, sum, i + 1);
                path.pop_back();
                sum -= i;
            }
        }
    }

    vector<vector<int>> combinationSum3(int k, int n)
    {
        backtracking(n, k, 0, 1);
        return result;
    }
};
// @lc code=end
