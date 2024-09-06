/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 */

// @lc code=start
class Solution
{
public:
    const string letterMap[10] = {
        "",     // 0
        "",     // 1
        "abc",  // 2
        "def",  // 3
        "ghi",  // 4
        "jkl",  // 5
        "mno",  // 6
        "pqrs", // 7
        "tuv",  // 8
        "wxyz", // 9
    };

    vector<string> result;

    string s;

    void backtracking(const string &digits, int index)
    {
        if (index == digits.size())
        {
            result.push_back(s);
            return;
        }

        int num = digits[index] - '0';
        for (int i = 0; i < letterMap[num].size(); i++)
        {
            s += letterMap[num][i];
            backtracking(digits, index + 1);
            s.pop_back();
        }
    }

    vector<string> letterCombinations(string digits)
    {
        if (digits.size() == 0)
        {
            return result;
        }
        backtracking(digits, 0);
        return result;
    }
};
// @lc code=end
