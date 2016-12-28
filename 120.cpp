//
// Created by sunguoyan on 2016/12/28.
//动态规划方法，动归方程d[i][j] = min{d[i+1][j],d[i+1][j+1]}+value[i][j]
//d[i][j]代表在位置(i,j)的最小路径值
//

#include "LeetCode.h"

int minimumTotal(vector<vector<int>>& triangle) {
    vector<vector<int>> path(triangle);
    for(int i = triangle.size()-2;i>=0;i--){
        for(int j = 0;j<triangle[i].size();j++){
            path[i][j] = min(path[i+1][j],path[i+1][j+1])+triangle[i][j];
        }
    }
    return path[0][0];
}

