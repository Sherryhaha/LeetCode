//
// Created by sunguoyan on 2017/4/8.
//

#include "LeetCode.h"

vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> ret;
    ret.clear();
    if(nums.size()<3){
        return ret;
    }
    sort(nums.begin(),nums.end());
    for(int i = 0;i<nums.size();i++){
        if(i>0&&nums[i]==nums[i-1])
            continue;
        int head,tail;
        head = i+1;
        tail = nums.size()-1;
        while(head < tail){
            if(head > i+1 && nums[head] == nums[head-1]){
                head++;
                continue;
            }
            if(tail < nums.size()-1 && nums[tail] == nums[tail+1]){
                tail--;
                continue;
            }
            int sum = nums[i]+nums[head]+nums[tail];
            if(sum<0){
                head++;
            }else if(sum>0){
                tail--;
            }else{
                vector<int> tmp;
                tmp.push_back(nums[i]);
                tmp.push_back(nums[head]);
                tmp.push_back(nums[tail]);
                ret.push_back(tmp);
                head++;
            }
        }
    }
    return ret;
}

