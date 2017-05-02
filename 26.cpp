//
// Created by sunguoyan on 2017/5/2.
//
#include "LeetCode.h"

int removeDuplicates(vector<int>& nums) {

    int i = 0;
    for(int n:nums){   //不可以先定义n哎，必须在这里int n:nums，不然会说找不到:
        if(!i || n>nums[i-1]){
            nums[i++] = n;
        }
    }
    return i;
}