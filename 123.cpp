//
// Created by sunguoyan on 2016/12/28.
// 动态规划
//

#include "LeetCode.h"

int LeetCode::maxProfit(vector<int>& prices) {
    if(prices.size()<2){
        return 0;
    }
    vector<vector<int>> f(3,vector<int>(prices.size(),0));
    int Maxtmp;
    for(int i = 1;i<3;i++){
        Maxtmp = f[i-1][0]-prices[0];
        for(int j = 1;j<prices.size();j++){
            f[i][j] = max(f[i][j-1],Maxtmp+prices[j]);   //动态规划状态转移方程
            Maxtmp = max(f[i-1][j]-prices[j],Maxtmp);
        }
    }
    return f[2][prices.size()-1];

}