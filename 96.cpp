//
// Created by sunguoyan on 2016/12/28.
//

#include "LeetCode.h"

int LeetCode::numTrees(int n) {
    vector<int> f(n+1,0);
    f[0] = 1;
    f[1] = 1;
    for(int i = 2;i<n+1;i++){
        for(int j = 1;j<i+1;j++) {
            f[i] += f[j-1]*f[i-j];
        }
    }
    return f[n];
}