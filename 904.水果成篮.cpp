/*
 * @lc app=leetcode.cn id=904 lang=cpp
 *
 * [904] 水果成篮
 */

// @lc code=start
class Solution {
public:
    int totalFruit(vector<int>& fruits) {         

        // fruits = {0,1,2,2};  
        
        int total = 0;
        int start = 0;
        unordered_map<int, int> cnt;


        for (int end = 0; end < fruits.size(); end++){
            cnt[fruits[end]]++;

            while (cnt.size() > 2){
                auto it = cnt.find(fruits[start]);
                // int abandon = it->second--;
                it->second--;
                // cout << it->second <<endl;
                if(it->second <= 0){
                    cnt.erase(it);
                }
                start++;//start一直向前推进导致一直更新it->second，进入死循环
            }

            total = max(total, end - start + 1);
            
        }

        return total;
        
    }
};
// @lc code=end

