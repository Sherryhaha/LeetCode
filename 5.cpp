//
// Created by sunguoyan on 16/10/10.
//

#include "LeetCode.h"

const int MAX = 1000;

//**********************************************************
//自底向上的动态规划求解方法
//d[i][j]可以判断字符串s[i][j]是否是回文子串，同时也可以获得回文子串的长度
//
//**********************************************************
string LeetCode::longestPalindrome(string s) {
    int len = s.length();
    int d[MAX][MAX] = {0};
    int maxlen = 1;
    int mlen = 1, first = 0;
    for (int i = 0; i < len; i++) {
        d[i][i] = 1;        //当字符串是一个时，也是一个回文字符串
    }
    for (int i = 0; i < len - 1; i++) { //当字符串是两个相同的字母时，也是一个回文字符串，需要预先负值
        if (s[i] == s[i + 1]) {
            d[i][i + 1] = 1;
            first = i;      //用first来记录所获的最大回文子串的起点
            maxlen = 2;
        }
    }


    //寻找长度为>=3的回文子串
    for (mlen = 3; mlen < len + 1; mlen++) {  //控制字符串的长度
        for (int i = 0; i < len + 1 - mlen; i++) { //控制字符串的起点
            int j = i + mlen - 1;             //字符串的末尾点位置
            if (d[i + 1][j - 1] == 1 && s[i] == s[j]) {
                d[i][j] = 1;
                first = i;
                maxlen = mlen;
            }
        }
    }
    return s.substr(first, maxlen);
}


//自顶向下（递归）

//bool isPalindrome(string s) {
//    int len = s.length();
//    bool flag = false;
//    if (len == 1) {
//        flag = true;
//        return flag;
//    }
//    if (len == 2 && s[0] == s[1]) {
//        flag = true;
//        return flag;
//    }
//    int i = 0, j = len - 1;
//    if (s[i] == s[j]) {
//        return isPalindrome(s.substr(i + 1, len - 2));
//    }
//    return flag;
//}
//
//string LeetCode::longestPalindrome(string s) {
//    int len = s.length();
//    int maxlen = 1;
//    int mlen = 1, first = 0;
//    string ss;
//    ss = s[0];
//    if (len == 1) {
//        ss = s;
//    }
//    if (len == 2 && s[0] == s[1]) {
//        ss = s;
//    }
//
//    string b;
//    for (mlen = 2; mlen < len + 1; mlen++) {
//        for (int i = 0; i < len + 1 - mlen; i++) {
//            int j = i + mlen - 1;
//            if (isPalindrome(s.substr(i, mlen))) {
//                first = i;
//                maxlen = mlen;
//                ss = s.substr(first, maxlen);
//            }
//        }
//    }
//    return ss;
//}

int main() {
    LeetCode l;
    string r;
    r = l.longestPalindrome("abbc");
    cout << r << endl;
    return 0;
}