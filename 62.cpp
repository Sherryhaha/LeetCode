//
// Created by sunguoyan on 16/10/15.
//
#include "LeetCode.h"

int LeetCode::uniquePaths(int m, int n) {
    vector< vector<int> > d(m);  //这边一开始写的d[m]
    for(int i = 0;i < m;i++){
        d[i].resize(n);
    }
    for(int i = 0;i < m;i++){
        d[i][0] = 1;
    }
    for(int i = 0;i < n;i++){
        d[0][i] = 1;
    }
    for(int i = 1;i < m;i++){
        for(int j = 1;j<n;j++){
            d[i][j] = d[i-1][j] + d[i][j-1];
        }
    }
    return d[m-1][n-1];
}

int main(){
    LeetCode test;
    int result = test.uniquePaths(3,7);
    cout<<result<<endl;
    return 0;
}