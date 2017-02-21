//
// Created by sunguoyan on 16/10/10.
//

#include "LeetCode.h"



int maxSubArray_sun(vector<int>& nums){
    int tsum = 0;
    int msum = INT_MIN;
    for(int i =0;i<nums.size();i++){
        tsum = max(tsum+nums[i],nums[i]);
        msum = max(tsum,msum);
    }
    return msum;
}

int main(){
   vector<int> a ={-2,1,-3,4,-1,2,1,-5,4};
    int msum = maxSubArray_sun(a);
    cout<<msum<<endl;
    return 0;
}