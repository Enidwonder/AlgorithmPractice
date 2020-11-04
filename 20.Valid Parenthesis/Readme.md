# Readme

## 	---20 Valid Parenthesis

### problem description

Given a string only consists of `'(',')','[',']','{','}'`，decide if it is valid

A valid string must satisfy the following conditions:

1. the left bracket must be closed woth the same type of right bracket
2. the left bracket must be closed in a correct order

Note that an empty string can be regarded as a valid one.

**Example 2:**

```
Input: "()[]{}"
Output: true
```

**Example 4:**

```
Input: "([)]"
Output: false
```

**Example 5:**

```
Input: "{[]}"
Output: true
```

### My solution

​	By analysing the characteristics of bracket matching,  I choose to make use of the "first-in-first-out" feature of stack for storage of brackets.

​	If the input is a left bracket, it must be waiting for a right bracket to match, so we push it into stack. If the input is a right bracket, it will only make sense when it matches the nearest left bracket. So we get the top bracket from the stack and if they match, pop it out of the stack and get the next input. But if they don't match, just return false. 

​	Repeat the process until the end of input. Note that if now the stack is not empty, it means that there exists left bracket not being matched, return false then. Otherwise, return true.

### Other solutions

It seems the stack method is the most common way.

### *PS: My codes

```c++
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

```

