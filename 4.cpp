//
// Created by sunguoyan on 2017/2/23.
//

#include "LeetCode.h"

//求两个有序数组的中位数，两个有序数组的长度不一样
double findkth(vector<int> &nums1, int s1, vector<int> &nums2, int s2, int k) {
    int m = nums1.size() - s1,n = nums2.size() - s2;
    //假设nums1的长度小于nums2
    if (m > n) return findkth(nums2, s2, nums1, s1, k);
    else if (m == 0) return nums2[s2 + k - 1];
    else if (k == 1) return min(nums1[s1], nums2[s2]);
    else {
        int pa = min (k / 2, m);
        int pb = k - pa;
        if (nums1[s1 + pa - 1] < nums2[s2 + pb - 1]) {
            return findkth(nums1, s1 + pa, nums2, s2, k - pa);
        } else if (nums1[s1 + pa - 1] > nums2[s2 + pb - 1]) {
            return findkth(nums1, s1, nums2, s2 + pb, k - pb);
        } else {
            return nums1[s1 + pa - 1];
        }
    }

}
//求两个有序数组的中位数，这题可以这样思考，求第k小数
//可以考虑，认为数组A的长度小于数组B，这样考虑A[k/2-1]和B[k/2-1]的大小，每次丢弃k/2个数
double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
    int m = nums1.size();
    int n = nums2.size();
    int k = (m + n) / 2;
    if ((m + n) & 0x1) {   //0x1是一个十六进制数，一般返回前一个数二进制的最后一位，如果是奇数，返回1，偶数返回0
        return findkth(nums1, 0, nums2, 0, k + 1);
    } else {
        return (findkth(nums1, 0, nums2, 0, k) + findkth(nums1, 0, nums2, 0, k + 1)) / 2.0;
    }
}


vector<int> merge(vector<int>&A,vector<int>&B){
    int l1 = A.size(),l2 = B.size();
    vector<int> result;
    int i=0,j=0;
    for(i=0,j=0;i<l1&&j<l2;){
        if(A[i]<=B[j]){
            result.push_back(A[i]);
            i++;
        }else{
            result.push_back(B[j]);
            j++;
        }
    }
    if(i==l1){
        while(j<l2){
            result.push_back(B[j]);
            j++;
        }
    }
    if(j == l2){
        while(i<l1){
            result.push_back(A[i]);
            i++;
        }
    }
    return result;
}

//另一种做法：归并排序
double findMedianSortedArrays_merge(vector<int> &nums1, vector<int> &nums2) {
    int m = nums1.size();
    int n = nums2.size();
    vector<int> result = merge(nums1,nums2);
    return (double)(result[(m+n)/2]+result[(m+n-1)/2])/2.0;
}

int main() {
    vector<int> nums1 = { };
    vector<int> nums2 = {2,3};
    double result = findMedianSortedArrays_merge(nums1, nums2);
    cout << result << endl;

    return 0;
}