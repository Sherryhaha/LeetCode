//
// Created by sunguoyan on 2016/12/28.
//
#include "LeetCode.h"

//**********************************
// ?????????????????????
// ?n?????????????f(n) = f(n-1)+f(n-2)??
//**********************************
int LeetCode::climbStairs(int n) {
    vector<int> d(n);
    d[0] = 1;
    d[1] = 2;
    for(int i = 2;i < n;i++){
        d[i] = d[i-1]+d[i-2];
    }
    return d[n-1];
}