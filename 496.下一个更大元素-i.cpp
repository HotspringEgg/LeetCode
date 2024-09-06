#include <unordered_map>
#include <vector>
#include <stack>
using namespace std;
/*
 * @lc app=leetcode.cn id=496 lang=cpp
 *
 * [496] 下一个更大元素 I
 */

// @lc code=start
class Solution
{
public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
    {
        stack<int> st;
        vector<int> result(nums1.size(), -1);
        unordered_map<int, int> map;

        for (int i = 0; i < nums1.size(); i++)
        {
            map[nums1[i]] = i;
        }

        for (int i = 0; i < nums2.size(); i++)
        {
            while (!st.empty() && nums2[i] > nums2[st.top()])
            {
                int topIndex = st.top();
                st.pop();

                auto it = map.find(nums2[topIndex]);
                if (it != map.end())
                {
                    result[map[nums2[topIndex]]] = nums2[i];
                }
            }
            st.push(i);
        }
        return result;
    }
};
// @lc code=end
