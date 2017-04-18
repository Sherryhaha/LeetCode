//
// Created by sunguoyan on 2017/4/18.
//
// 4sum朴素的想法就是固定两个元素，然后按照2sum的方法
#include "LeetCode.h"


vector<vector<int>> fourSum(vector<int>& nums, int target) {
   vector<vector<int>> ret;
    if(nums.size()<4) return ret;
    sort(nums.begin(),nums.end());
    for(int i = 0;i < nums.size()-3;i++){
        if(i>0&&nums[i]==nums[i-1]) continue;
        for(int j = i+1;j<nums.size()-2;j++){
            if(j>i+1&&nums[j]==nums[j-1]) continue;
            int newTarget = target - nums[i] - nums[j];
            int left = j+1;
            int right = nums.size() - 1;
            while(left < right){
                int sum = nums[left]+nums[right];
                if(sum == newTarget){
                    vector<int> tmp = {nums[i],nums[j],nums[left],nums[right]};
                    ret.push_back(tmp);
                    do{
                       left++;
                    } while(left < right && nums[left] == nums[left-1]);
                     //   left ++;
                    do{
                        right--;
                    } while(left < right && nums[right]==nums[right+1]);
                     //   right--;
                }else if(sum < newTarget){
                    left++;
                }else if(sum > newTarget){
                    right--;
                }
            }
        }
    }
    return ret;
}

