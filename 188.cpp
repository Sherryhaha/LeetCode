//
// Created by sunguoyan on 2016/12/30.
//
#include "LeetCode.h"

int LeetCode::maxProfit(int k, vector<int> &prices) {
    if (prices.size() < 2) {
        return 0;
    }
    if (k > prices.size() / 2) {
        int maxProfit = 0;
        for (int i = 1; i < prices.size(); i++) {
            maxProfit += max(0, prices[i] - prices[i - 1]);   //贪心
        }
        return maxProfit;
    }
    int Maxtmp = 0;
    vector<vector<int>> f(k + 1, vector<int>(prices.size(), 0));
    for (int i = 1; i < k + 1; i++) {
        Maxtmp = f[i - 1][0] - prices[0];
        for (int j = 1; j < prices.size(); j++) {
            f[i][j] = max(f[i][j - 1], Maxtmp + prices[j]); //卖或者不卖 动归
            Maxtmp = max(Maxtmp, f[i - 1][j] - prices[j]); //买进或者不买
        }
    }
    return f[k][prices.size() - 1];
}
