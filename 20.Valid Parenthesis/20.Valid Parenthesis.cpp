/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */

// @lc code=start
#include<stack>
using namespace std;
class Solution {
public:

    bool match(char p, char q){
        if(p == '(' && q == ')') return true;
        if(p == '[' && q == ']') return true;
        if(p == '{' && q == '}') return true;
        return false;
    }

    bool isValid(string str) {
        stack<char> s;
        for(int i = 0;i < str.length();i ++){
            char p = str[i];
            if(p == '(' || p == '{' || p == '[') {
                //left, push into stack
                s.push(p);
            }else //right, pop to match
            {
                if(!s.empty()){
                    char q = s.top();
                    if(match(q,p)){
                        s.pop();
                    }else{
                        return false;
                    }
                }else{
                    return false;
                }
                
            }
            
        }
        if(!s.empty()) return false;
        return true;
    
    }
};
// @lc code=end

