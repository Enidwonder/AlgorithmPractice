/*
 * @lc app=leetcode.cn id=13 lang=cpp
 *
 * [13] 罗马数字转整数
 */

// @lc code=start

class Solution {
public:
    int find(char s){
        int value = 0;
        switch(s){
                    case 'I':{value = 1;break;}
                    case 'V':{value = 5;break;}
                    case 'X':{value = 10;break;}
                    case 'L':{value = 50;break;}
                    case 'C':{value = 100;break;}
                    case 'D':{value = 500;break;}
                    case 'M':{value = 1000;break;}
                }
            return value;
    }


    int romanToInt(string s) {
        int result = 0;

        for(int i = 0;i < s.length();i ++){
            int current = find(s[i]);
            int next = find(s[i+1]);
            if(current >= next){
                result += current;
            }
            else{
                int ad = next - current;
                result += ad;
                i = i +1;
            }
        }
        return result;

    }
};
// @lc code=end

