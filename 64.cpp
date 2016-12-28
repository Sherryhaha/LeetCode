//
// Created by sunguoyan on 2016/12/28.
//

#include "LeetCode.h"
int LeetCode::minPathSum(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>> result(m);
    for(int i = 0;i<n;i++){
        result[i].resize(n,0);
    }
    result[0][0] = grid[0][0];
    for(int i = 1;i<m;i++){
        result[0][i] = result[0][i-1] + grid[0][i];
    }
    for(int i = 1;i<m;i++){
        result[i][0] = result[i-1][0]+grid[i][0];
    }
    for(int i = 1;i<m;i++){
        for(int j = 1;j<n;j++){
            result[i][j] = min(result[i][j-1],result[i-1][j])+grid[i][j];
        }
    }
    return result[m-1][n-1];
}