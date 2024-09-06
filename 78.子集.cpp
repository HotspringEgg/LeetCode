/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> result;
    vector<int> path;

    void backtracking(vector<int> &nums, int startIndex)
    {
        result.push_back(path);
        // 本题为收集所有子集，要收集所有节点，而不是只针对叶子节点
        if (startIndex >= nums.size())
        {
            return;
        }
        for (int i = startIndex; i < nums.size(); i++)
        {
            path.push_back(nums[i]);
            backtracking(nums, i + 1);
            path.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int> &nums)
    {
        backtracking(nums, 0);
        return result;
    }
};
// @lc code=end
