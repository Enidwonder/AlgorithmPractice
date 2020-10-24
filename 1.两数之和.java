/*
 * @lc app=leetcode.cn id=1 lang=java
 *
 * [1] 两数之和
 */

// @lc code=start
class Solution {
    public int find(int[]sums,int target,int self){
        for(int i =0;i < sums.length ;i ++){
            if(i == self) continue;
            if(sums[i] == target) return i;
        }
        return -1;
    }
    public int[] twoSum(int[] nums, int target) {
        int[] a = {0,0};
        for(int i =0;i < nums.length;i ++){
            int toFind = target - nums[i];
            int other = find(nums,toFind,i);
            if(other == -1) continue;
            else{
                
                a[0] = i;
                a[1] = other;
                break;
            }
        }
        return a;
    }
}
// @lc code=end

