//
// Created by sunguoyan on 16/9/13.
//

#ifndef LEETCODE_LEETCODE_H
#define LEETCODE_LEETCODE_H
#include <iostream>
#include <vector>
#include <string>

using namespace std;
class LeetCode{
public:
    vector<int> twoSum(vector<int>& nums, int target);
    string longestPalindrome(string s);
    int maxSubArray(vector<int>& nums);
    int uniquePaths(int m, int n);
    int searchInsert(vector<int>& nums, int target);
    int search(vector<int>& nums, int target);
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid);
    int minPathSum(vector<vector<int>>& grid);
    int climbStairs(int n);
    int numTrees(int n);
    int minimumTotal(vector<vector<int>>& triangle);
    int maxProfit(vector<int>& prices);
    int maxProfit_2(vector<int>& prices);
    int maxProfit_3(vector<int>& prices);
    int maxProfit(int k, vector<int>& prices);

    };

#endif //LEETCODE_LEETCODE_H
