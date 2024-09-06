#include <vector>
#include <stack>
using namespace std;
/*
 * @lc app=leetcode.cn id=503 lang=cpp
 *
 * [503] 下一个更大元素 II
 */

// @lc code=start
class Solution
{
public:
    vector<int> nextGreaterElements(vector<int> &nums)
    {
        stack<int> st;
        vector<int> result(nums.size(), -1);
        
        // 模拟遍历两边nums，注意一下都是用i % nums.size()来操作
        for (int i = 0; i < nums.size() * 2; i++)
        {
            while (!st.empty() && nums[i % nums.size()] > nums[st.top()])
            {
                int topIndex = st.top();
                result[topIndex] = nums[i % nums.size()];
                st.pop();
            }
            st.push(i % nums.size());
        }
        return result;
    }
};
// @lc code=end
