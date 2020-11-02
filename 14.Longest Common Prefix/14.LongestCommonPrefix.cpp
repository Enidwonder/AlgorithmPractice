/*
 * @lc app=leetcode.cn id=14 lang=cpp
 *
 * [14] 最长公共前缀
 */

// @lc code=start
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string pre = "";
        int index = 0;
        if(strs.size() == 0) return pre;
        string str0 = strs[0];
        
        

        while(true){
            char char0 = str0[index];
            if(char0 < 97 || char0 > 122) break;
            vector<string>::iterator it;//声明一个迭代器，来访问vector容器，作用：遍历或者指向vector容器的元素 
            for(it=strs.begin()+1;it!=strs.end();it++)
            {
                string str = *it;
                char t = str[index];
                if(t != char0) return pre;
            }
            pre.append(1,char0);
            index ++;
        }

        return pre;
    }
};
// @lc code=end

