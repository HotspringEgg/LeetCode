#include <string>
#include <stack>
using namespace std;
/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */

// @lc code=start
class Solution
{
public:
    bool isValid(string s)
    {
        if (s.size() % 2 != 0)
        {
            return false;
        }

        stack<char> stack;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(')
            {
                stack.push(')');
            }
            else if (s[i] == '[')
            {
                stack.push(']');
            }
            else if (s[i] == '{')
            {
                stack.push('}');
            }
            else if (stack.empty() || s[i] != stack.top())
            {
                return false;
            }
            else
            {
                stack.pop();
            }
        }
        return stack.empty();
    }
};
// @lc code=end
// bool isValid(string s)
// {
//     if (s.size() % 2 != 0)
//     {
//         return false;
//     }
//     stack<char> st;
//     for (int i = 0; i < s.size(); i++)
//     {
//         if (s[i] == '(')
//         {
//             st.push(')');
//         }
//         else if (s[i] == '[')
//         {
//             st.push(']');
//         }
//         else if (s[i] == '{')
//         {
//             st.push('}');
//         }
//         else if (st.empty() || st.top() != s[i])
//         {
//             return false;
//         }
//         else
//         {
//             st.pop();
//         }
//     }
//     return st.empty();
// }