#include <string>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=131 lang=cpp
 *
 * [131] 分割回文串
 */

// @lc code=start

// 这段代码通过填充一个布尔矩阵来预计算字符串的所有子串是否为回文。
// 倒序计算保证了在计算 isPalindrome[i][j] 时，
// isPalindrome[i + 1][j - 1] 已经计算好了，
// 从而可以正确判断较长子串是否为回文
//  void computePalindrome(const string& s) {
//      // isPalindrome[i][j] 代表 s[i:j](双边包括)是否是回文字串
//      isPalindrome.resize(s.size(), vector<bool>(s.size(), false)); // 根据字符串s, 刷新布尔矩阵的大小
//      for (int i = s.size() - 1; i >= 0; i--) {
//          // 需要倒序计算, 保证在i行时, i+1行已经计算好了
//          for (int j = i; j < s.size(); j++) {
//              if (j == i) {isPalindrome[i][j] = true;}
//              else if (j - i == 1) {isPalindrome[i][j] = (s[i] == s[j]);}
//              else {isPalindrome[i][j] = (s[i] == s[j] && isPalindrome[i+1][j-1]);}
//          }
//      }
//  }

// 此题举例“aabaa”
class Solution
{
public:
    vector<string> path;
    vector<vector<string>> result;

    // 判断子字符串是否为回文字符串
    bool isPalindrome(const string &s, int startIndex, int endIndex)
    {
        for (int i = startIndex, j = endIndex; i < j; i++, j--)
        {
            if (s[i] != s[j])
            {
                return false;
            }
        }
        return true;
    }

    void backtracking(const string &s, int startIndex)
    {
        // 终止条件，分割线大于字符串长度
        if (startIndex >= s.size())
        {
            result.push_back(path);
            return;
        }

        for (int i = startIndex; i < s.size(); i++)
        {
            // 如果子字符串是回文字符串
            if (isPalindrome(s, startIndex, i))
            {
                // i为子串的末尾
                string substr = s.substr(startIndex, i - startIndex + 1);
                path.push_back(substr);
            }
            else
            {
                continue;
            }

            // 下半部分如果子字符串不是回文字符串，会直接跳过
            backtracking(s, i + 1);
            path.pop_back();
        }
    }

    vector<vector<string>> partition(string s)
    {
        backtracking(s, 0);
        return result;
    }
};
// @lc code=end
