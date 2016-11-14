//
// Created by sunguoyan on 2016/11/14.
//
#include "LeetCode.h"

int LeetCode::searchInsert(vector<int>& nums, int target){
    int mid,pos = 0,l = 0,r;
    r = nums.size() - 1;
    while(l<=r){
        mid = (l+r)>>1;
        if(nums[mid] == target) return mid;
        if(target < nums[mid]){
            r = mid - 1;
            pos = mid;
        }else if(target > nums[mid]){
            l = mid + 1;
            pos = mid + 1;
        }
    }
    return pos;
}

int main(){
    LeetCode test;
//    num =
    vector<int> num={1,3,4,5};
    int result = test.searchInsert(num,1);
    cout<<result<<endl;
}