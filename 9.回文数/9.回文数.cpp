/*
 * @lc app=leetcode.cn id=9 lang=cpp
 *
 * [9] 回文数
 */

// @lc code=start
class Solution {
public:
    bool isPalindrome(int x) {
        //negative numbers are definitely not 
        if(x < 0) return false;
        if(x == 0) return true;
        int reverse = 0;
        int save_x = x;
        while(x != 0){
            int t = x % 10;
            if(reverse > INT_MAX/10 || (reverse == INT_MAX / 10 && t > 7)) return false;

            x /= 10;
            reverse = reverse * 10 + t;
        }
        if(reverse == save_x) return true;
        else return false;
    

    }
};
// @lc code=end

