//
// Created by sunguoyan on 2016/12/28.
//动态规划
//

#include "LeetCode.h"

int LeetCode::maxProfit(vector<int>& prices) {
    if(prices.size()<=1){
        return 0;
    }
    int min_p = prices[0];
    int max_p = 0;
    for(int i = 1;i<prices.size();i++){
        max_p = max(max_p,prices[i]-min_p);
        min_p = min(min_p,prices[i]);
    }
    return max_p;
}