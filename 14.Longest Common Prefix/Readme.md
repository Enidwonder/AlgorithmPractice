# Readme

## 	---14 Longest Common Prefix

### problem description

Design a function to search for the longest common prefix in a string array

If not exists, return empty string "".

**Example 1:**

```
Input: ["flower","flow","flight"]
Output: "fl"
```

**Example 2:**

```
Input: ["dog","racecar","car"]
Output: ""
```

**Note:**

All the inputs only include lowercase letters `a-z` 。

### My solution

​	My solution is to compare all the strings every single letter.

​	I thought of two solutions, one is getting prefix every two strings, until the whole vector got traversed during which process the longest common prefix keep changing.

 	And the other one is the one finally being used,.

​	Each loop we get on single letter and compare all the letter in the position of all strings, if one is different, this letter won't be added into the common prefix and jump out of the loop, and return the current prefix. If all the strings have the same letter in this position, this letter will be appended into the common prefix, and we continue to check the next letter.

​	But the result shows my method doesn't behave very well from the aspect of time and memory costs.

### Other solutions

1. Divide and conquer

   ​	Divide the string array into two parts, and the longest common prefix is the longest common prefix of the lcp of the two parts.
   $$
   Lcp(S_1...S_n)=Lcp(Lcp(S_1...S_k),Lcp(S_{k+1}...S_n))
   $$

2. Binary search

   ​	The longest common prefix won't be longer than the shortest string in the array, so during the interval 
   $$
   [0,minLength]
   $$
   , we can get the length of the final Lcp using binary search method.

   ​	Every time we get the middle number of the interval mid, and we decide if the prefixes of all strings in the position of mid are the same, if they are, change the interval into
   $$
   [mid,midLength]
   $$
   , otherwise we change it into 
   $$
   [0,mid]
   $$
   .

   ​	Repete the process until we get our final Lcp.

   ​	This method broadly reduce the time cost.

   

### *PS: My codes

```c++
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
            vector<string>::iterator it; 
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

```

