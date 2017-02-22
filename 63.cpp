//
// Created by sunguoyan on 2016/12/28.
//

#include "LeetCode.h"


//*****************************************************************
// 求有多少路径可以从左上角到达右下角，路径中带有障碍，0表示无障碍，1表示有障碍
//*****************************************************************
int LeetCode::uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();
    vector<vector<int>> result(m+1);
    for(int i = 0;i<m+1;i++){
        result[i].resize(n+1);
    }
    result[1][1] = obstacleGrid[0][0]==1?0:1;
    for(int i = 2;i<n+1;i++){
        result[1][i] = obstacleGrid[0][i-1]==1?0:result[1][i-1];
    }
    for(int i = 2;i < m+1;i++){
        result[i][1] = obstacleGrid[i-1][0] ==1?0:result[i-1][1];
    }
    for(int i = 2;i<m+1;i++){
        for(int j = 2;j<n+1;j++){
            result[i][j] = obstacleGrid[i-1][j-1]==1?0:result[i-1][j]+result[i][j-1];
        }
    }
    return result[m][n];
}