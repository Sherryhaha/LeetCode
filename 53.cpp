//
// Created by sunguoyan on 16/10/13.
//

#include "LeetCode.h"


//************************************************
// ???????????????????????????????????????
//************************************************
int LeetCode::maxSubArray(vector<int>& nums){
    int tsum = 0;
    int msum = INT_MIN;
    for(int i = 0;i<nums.size();i++){
        tsum = max(tsum+nums[i],nums[i]);
        msum = max(msum,tsum);
    }
    return msum;
}

int main(){
    LeetCode test;
    int n[10]= {-2,1,-3,4,-1,2,1,-5,4};
    vector<int> num(n,n+9) ;

    int sum = test.maxSubArray(num);
    cout<<sum<<endl;
    return 0;
}
