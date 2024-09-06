#include <stack>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=84 lang=cpp
 *
 * [84] 柱状图中最大的矩形
 */

// @lc code=start
class Solution
{
public:
    int largestRectangleArea(vector<int> &height)
    {
        stack<int> st;
        int result = 0;
        // 首位+0
        height.insert(height.begin(), 0);
        height.push_back(0);
        st.push(0);

        // 找右边第一个小于自己的
        for (int i = 1; i < height.size(); i++)
        {
            while (!st.empty() && height[i] < height[st.top()])
            {
                int LastTopIndex = st.top();
                st.pop();
                int NewTopIndex = st.top();
                int h = height[LastTopIndex];
                int w = i - NewTopIndex - 1;
                result = max(h * w, result);
            }
            st.push(i);

            // 此处不需要维持特殊情况
            // 当当前元素小于栈顶元素时，可知栈内元素都小于等于栈顶元素
            // 因为栈内记录的是下标，所以两个相等的相邻元素求的矩形宽度不同
            //                 X
            //         X   X   X
            //         X   X   X
            //         X   X   X       X
            // X       X   X   X   X   X
            // X   X   X   X   X   X   X
            // 0   1   2   3   4   5   6
            // 当i = 5时，弹出4元素，高度为6宽度为1得面积为6
            //           弹出3元素，高度为5宽度为2得面积为10
            //           (对于该元素可知，除了当前元素i = 5，栈顶所有元素都>=该元素)
            //           弹出2元素，高度为5宽度为3得面积为15
        }
        return result;
    }
};
// @lc code=end
