//
// Created by sunguoyan on 2016/12/28.
//
#include "LeetCode.h"
int LeetCode::climbStairs(int n) {
    vector<int> d(n);
    d[0] = 1;
    d[1] = 2;
    for(int i = 2;i < n;i++){
        d[i] = d[i-1]+d[i-2];
    }
    return d[n-1];
}