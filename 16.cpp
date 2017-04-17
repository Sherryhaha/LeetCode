//
// Created by sunguoyan on 2017/4/17.
//
#include "LeetCode.h"
int threeSumClosest(vector<int>& nums, int target) {
    if(nums.size() < 3){
        return 0;
    }
    sort(nums.begin(),nums.end());
    int closeSum = 0; int diffMin = INT_MAX;
    for(int i = 0;i < nums.size();i++) {
        int left = i + 1;
        int right = nums.size() - 1;
        while (left < right) {
            int sum;
            sum = nums[i] + nums[left] + nums[right];
            int diff = abs(sum - target);
            if (diff < diffMin) {
                diffMin = diff;
                closeSum = sum;
            }

            if (sum > target) {
                right--;
            } else if (sum < target) {
                left++;
            } else {
                return sum;
            }
        }
    }
    return closeSum;
}

int main(){
    vector<int> a = {1,1,-1};
    int target = 2;
    int result = threeSumClosest(a,target);
    cout<<result<<endl;
    return 0;
}