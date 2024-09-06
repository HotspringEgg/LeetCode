/*
 * @lc app=leetcode.cn id=844 lang=cpp
 *
 * [844] 比较含退格的字符串
 */

// @lc code=start
class Solution {
public:
    bool backspaceCompare(string s, string t) {
        // s = "ab#c";
        // t = "ad#c";
        // cout << s;
        int signS = 0, signT = 0;//'#'的数目
        int i = s.size() - 1, j = t.size() - 1;

        while (i >= 0 || j >= 0)
        {
            while (i >= 0){
                if(s[i] == '#'){
                    signS++;
                    i--;
                }else if(signS != 0){
                    signS--;
                    i--;
                }else{
                    break;
                }
            }//遍历保留下来的S里的元素

            while (j >= 0){
                if(t[j] == '#'){
                    signT++;
                    j--;
                }else if(signT != 0){
                    signT--;
                    j--;
                }else{
                    break;
                }
            }//遍历保留下来的T里的元素

            if(i >= 0 && j >= 0){
                if(s[i] != t[j]){
                    // cout << '1';
                    return false;//尾元素不相同
                }
            }else{
                if (i >= 0 || j >= 0){
                    // cout << '2' << endl << s[i] << t[j];
                    return false;//其一已空，另一个还有
                }
            }

            i--;
            j--;
            
        }
        
        return true;
        
    }
};
// @lc code=end

