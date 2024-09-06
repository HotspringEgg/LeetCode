#include<string>
using namespace std;
/*
 * @lc app=leetcode.cn id=1047 lang=cpp
 *
 * [1047] 删除字符串中的所有相邻重复项
 */

// @lc code=start
class Solution {
public:
    string removeDuplicates(string S) {
        string result;
        for(char s : S)
        {
            if (result == "" || result.back() != s)
            {
                result.push_back(s);
            }
            else
            {
                result.pop_back();
            }
        }
        return result;
    }
};
// @lc code=end

