//
// Created by sunguoyan on 2017/5/3.
//
#include "LeetCode.h"

int removeElement(vector<int>& nums, int val) {
    sort(nums.begin(),nums.end());
    int i = 0;
    for(int n : nums){
        if(n!=val){
            nums[i++] = n;
        }
    }
    return i;
}


int main(){
    vector<int> nums = {2,2,1,4,5,7,4,3,5};
    //sort(nums.begin(),nums.end());
    int result = removeElement(nums,2);
    cout<<"result: "<<result<<endl;
    for(int i = 0;i<result;i++){
        cout<<nums[i]<<" ";
    }
    cout<<endl;
    return 0;
}

