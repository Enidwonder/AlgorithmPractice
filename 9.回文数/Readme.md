# Readme

## 	---9. 回文数

### Problem description

判断一个整数是否是回文数。回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数。

### My solution

我的思路：

​	利用了第7题整数反转的思路，首先负数由于存在符号必定不是回文数，对于正数，将原始数反转后做比，如果相同则是回文数，不同则不是，同时，如果反转过程中溢出也不是回文数

### Other solutions

由于完全反转可能会存在溢出问题

那么，反转一半呢？

​	仍用取余再×10的方法实现将原数字后半段反转

关键问题：如何判断已经反转了一半？

​	当原始数小于等于反转结果时，即可知道已经反转一半了

​	注意奇数的时候要对中间的数字进行处理

### *PS: My codes

```c++
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
```

