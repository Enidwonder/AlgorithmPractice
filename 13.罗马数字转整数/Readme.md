# Readme

## 	---13 罗马数字转整数

### problem description

罗马数字包含以下七种字符: `I`， `V`， `X`， `L`，`C`，`D` 和 `M`。

```
字符          数值
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
```

例如， 罗马数字 2 写做 `II` ，即为两个并列的 1。12 写做 `XII` ，即为 `X` + `II` 。 27 写做 `XXVII`, 即为 `XX` + `V` + `II` 。

通常情况下，罗马数字中小的数字在大的数字的右边。但也存在特例，例如 4 不写做 `IIII`，而是 `IV`。数字 1 在数字 5 的左边，所表示的数等于大数 5 减小数 1 得到的数值 4 。同样地，数字 9 表示为 `IX`。这个特殊的规则只适用于以下六种情况：

- `I` 可以放在 `V` (5) 和 `X` (10) 的左边，来表示 4 和 9。
- `X` 可以放在 `L` (50) 和 `C` (100) 的左边，来表示 40 和 90。 
- `C` 可以放在 `D` (500) 和 `M` (1000) 的左边，来表示 400 和 900。

给定一个罗马数字，将其转换成整数。输入确保在 1 到 3999 的范围内。

**示例 1:**

```
输入: "III"
输出: 3
```

**示例 2:**

```
输入: "IV"
输出: 4
```

**示例 3:**

```
输入: "IX"
输出: 9
```

**示例 4:**

```
输入: "LVIII"
输出: 58
解释: L = 50, V= 5, III = 3.
```

**示例 5:**

```
输入: "MCMXCIV"
输出: 1994
解释: M = 1000, CM = 900, XC = 90, IV = 4.
```

 

**提示：**

- 题目所给测试用例皆符合罗马数字书写规则，不会出现跨位等情况。
- IC 和 IM 这样的例子并不符合题目要求，49 应该写作 XLIX，999 应该写作 CMXCIX 。

### My solution

通过手动模拟转换过程，我发现只需要按序遍历字符串，比较当前数字及其下一位数字的大小，如果后一位比当前位大，说明出现了特殊情况罗马数组合，这个时候将其作为一个整体，求下一位数与当前数的差加入求和结果，并跨过当前数的下一位数继续遍历；否则直接将当前数值加入求和结果，继续遍历当前数的下一位数

由于对C++数据结构长时间不复习，尝试了键值对方法，走了一点弯路，后来将罗马数与整数的对应封装了个find函数将问题解决

### Other solutions

感觉其他方法差不多思路，我的思路复杂度还是比较低的

### *PS: My codes

```c++
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

```

