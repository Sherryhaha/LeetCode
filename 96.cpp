//
// Created by sunguoyan on 2016/12/28.
//

#include "LeetCode.h"


//**************************************
// 给一个数字n代表有n个节点，去构成一个二叉搜索树
// 令f(n)表示n个节点可以构成的二叉搜索树个数F(i,n)表示
// n个节点以i为root去构建二叉搜索树的方式有多少中
// f(n) = F(1,n)+F(2,n)+...+F(n,n).  f(0) = 1,f(1) = 1
//  F(i,n) = f(i-1)*f(n-i),??????
// f(n) = f(0)*f(n-1)+ f(1)*f(n-2)+...+f(n-1)*f(0)
//**************************************

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