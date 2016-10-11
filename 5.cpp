//
// Created by sunguoyan on 16/10/10.
//

#include "LeetCode.h"

const int MAX = 1000;

////自底向上
//string LeetCode::longestPalindrome(string s) {
//        int len = s.length();
//        int d[MAX][MAX]={0};
//        int maxlen = 1;
//        int mlen=1,first=0;
//        for(int i = 0;i<len;i++) {
//                d[i][i] = 1;
//        }
//        for(int i = 0;i < len-1;i++){
//                if(s[i]==s[i+1]){
//                        d[i][i+1]=1;
//                        first = i;
//                        maxlen = 2;
//                }
//        }
//
//
//        for(mlen = 3;mlen < len+1;mlen++){
//                for(int i = 0;i<len+1-mlen;i++){
//                        int j = i+mlen-1;
//                        if(d[i+1][j-1]==1&&s[i]==s[j]){
//                                d[i][j] = 1;
//                                first = i;
//                                maxlen = mlen;
//                        }
//                }
//        }
//        return s.substr(first,maxlen);
//}


//自顶向下（递归）

bool isPalindrome(string s) {
    int len = s.length();
    bool flag = false;
    if (len == 1) {
        flag = true;
        return flag;
    }
    if (len == 2 && s[0] == s[1]) {
        flag = true;
        return flag;
    }
    int i = 0, j = len - 1;
    if (s[i] == s[j]) {
        return isPalindrome(s.substr(i + 1, len - 2));
    }
    return flag;
}

string LeetCode::longestPalindrome(string s) {
    int len = s.length();
    int maxlen = 1;
    int mlen = 1, first = 0;
    string ss;
    ss = s[0];
    if (len == 1) {
        ss = s;
    }
    if (len == 2 && s[0] == s[1]) {
        ss = s;
    }

    string b;
    for (mlen = 2; mlen < len + 1; mlen++) {
        for (int i = 0; i < len + 1 - mlen; i++) {
            int j = i + mlen - 1;
            if (isPalindrome(s.substr(i, mlen))) {
                first = i;
                maxlen = mlen;
                ss = s.substr(first, maxlen);
            }
        }
    }
    return ss;
}

int main() {
    LeetCode l;
    string r;
    r = l.longestPalindrome("abc");
    cout << r << endl;
    return 0;
}