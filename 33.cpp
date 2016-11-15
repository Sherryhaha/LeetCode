//
// Created by sunguoyan on 2016/11/15.
//
#include "LeetCode.h"

int LeetCode::search(vector<int>& nums, int target) {
    if(nums.empty()||nums.size()==0){
        return -1;
    }
    int mid,l,r;
    l = 0;r = nums.size()-1;
    while(l<=r){
        mid = (l+r)>>1;
        if(nums[mid] == target) return mid;
        if(nums[mid]<nums[r]){
            if(target>nums[mid]&&target<=nums[r])
                l = mid+1;
            else
                r = mid -1;
        }else{
            if(target<nums[mid]&&target>=nums[l])
                r = mid - 1;
            else
                l = mid + 1;
        }
    }
    return -1;
}