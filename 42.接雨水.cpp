#include <stack>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 */

// @lc code=start
class Solution
{
public:
    int trap(vector<int> &height)
    {
        stack<int> st;
        int result = 0;

        for (int i = 0; i < height.size(); i++)
        {
            // 当前高度大于栈顶柱子的高度，说明找到了一个右边界
            while (!st.empty() && height[i] > height[st.top()])
            {
                int LastTopIndex = st.top();
                st.pop();
                if (st.empty())
                {
                    break;
                }
                int NewTopIndex = st.top();
                int h = min(height[i], height[NewTopIndex]) - height[LastTopIndex];
                int w = i - NewTopIndex - 1;
                result += h * w;
            }
            st.push(i);
        }
        return result;
    }
};
// @lc code=end
