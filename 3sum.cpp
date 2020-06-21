/*

给你一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，
使得 a + b + c = 0 ？请你找出所有满足条件且不重复的三元组。
注意：答案中不可以包含重复的三元组。

实例
给定数组 nums = [-1, 0, 1, 2, -1, -4]，

满足要求的三元组集合为：
[
  [-1, 0, 1],
  [-1, -1, 2]
]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/3sum

*/



class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int size = nums.size();
        vector<vector<int>> res;
        if(size < 3) return res;
        sort(nums.begin(),nums.end());

        for(int i = 0;i < size-2 ;i++){
            if(nums[i] > 0) break;
            if(i > 0 && nums[i] == nums[i-1]) continue;
            
            int p = i+1;
            int s = size -1;

            while(p < s){
                if(nums[s] < 0) break;
                int t = nums[i]+nums[s]+nums[p];
                if( t == 0){
                    res.push_back({nums[i],nums[p],nums[s]});
                    while(p<s && nums[s] == nums[--s]);
                    while(p<s && nums[p] == nums[++p]);
                }
                else if(t < 0) p++;
                else s--;
            }
        }
        return res;
    }
};