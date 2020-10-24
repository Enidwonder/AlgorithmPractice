/*
 * @lc app=leetcode.cn id=7 lang=cpp
 *
 * [7] 整数反转
 */

// @lc code=start
class Solution {
public:
    int reverse(int x) {
        bool flag = true;
        
        if(x < 0) {
            if(x == INT_MIN) return 0;
            flag = false;
            x = 0-x;
        }

        int count = 0;
        int a[20];
        do{
            a[count] = x % 10;
            count ++;
            x = x / 10;
        }while(x != 0);
        int result = 0;
        for(int i = 0;i < count;i ++){
            long t = pow(10,count-i-1);
            long long add = a[i] * t;
            if(add > INT_MAX) return 0;
            result += (a[i] * t);
        }
        if(!flag) {
            result = 0 - result;
            if(result > 0) return 0;
         }
         else{
             if(result < 0) return 0;
         }
        return result;

    }
};
// @lc code=end

