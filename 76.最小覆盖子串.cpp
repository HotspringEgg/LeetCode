/*
 * @lc app=leetcode.cn id=76 lang=cpp
 *
 * [76] 最小覆盖子串
 */

// @lc code=start

// cout << subs << endl;

bool isExist(string subs, string t){
    for (int i = 0; i < t.size(); i++){
        // cout << t[i] << endl;

        if(subs.find(t[i]) == -1){
            // cout << "b";
            return false;
        }else {
            subs.erase(subs.find(t[i]),1);
            // cout << subs << endl;
        }

    }
    // cout << "a";
    return true;
}

class Solution {
public:
    string minWindow(string s, string t) {
        
        int start = 0;
        string answer = s;

        if(isExist(s, t) == false){
            return "";
        }

        // s = "ADOBECODEBANC", t = "ABC";
        // isExist(s, t);
        
        for (int end = 0; end < s.size(); end++){

            while ( isExist( s.substr(start, end - start + 1) , t) ){
                string sub = s.substr(start, end - start + 1);

                if(sub.size() <= answer.size()){
                    answer = sub;
                }
                
                start++;

            }

        }

        return answer;
    }
};
// @lc code=end

