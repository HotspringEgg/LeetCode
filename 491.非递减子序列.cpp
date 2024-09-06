/*
 * @lc app=leetcode.cn id=491 lang=cpp
 *
 * [491] 非递减子序列
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> result;
    vector<int> path;

    void backtracking(vector<int> &nums, int startIndex)
    {
        // 本题为收集所有子集，要收集所有节点，而不是只针对叶子节点
        if (path.size() > 1)
        {
            result.push_back(path);
        }
        // 该集合用来记录哪些元素已经被横向遍历过
        // 如果被横向遍历过就跳过
        unordered_set<int> uset;

        for (int i = startIndex; i < nums.size(); i++)
        {
            // 如果path不为空，并且下一个数小于path末尾的数，则跳过该数
            // 如果下一个数在本层被用过，跳过该数
            if ((!path.empty() && nums[i] < path.back()) || uset.find(nums[i]) != uset.end())
            {
                continue;
            }

            uset.insert(nums[i]);
            path.push_back(nums[i]);
            backtracking(nums, i + 1);
            path.pop_back();
        }
    }
    vector<vector<int>> findSubsequences(vector<int> &nums)
    {
        backtracking(nums, 0);
        return result;
    }
};
// @lc code=end
