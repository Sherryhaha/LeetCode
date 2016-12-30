//
// Created by sunguoyan on 2016/12/28.
// 贪心法，只要第二天的利益比前一天大，就卖出
//
#include "LeetCode.h"

int LeetCode::maxProfit_2(vector<int> &prices) {
    if (prices.size() <= 1) {
        return 0;
    }
    int profit = 0;
    for(int i = 1;i<prices.size();i++){
        profit+=max(0,prices[i] - prices[i-1]);
    }
    return profit;
}
