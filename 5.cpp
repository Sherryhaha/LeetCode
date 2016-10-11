//
// Created by sunguoyan on 16/10/10.
//

#include "LeetCode.h"

const int MAX = 1000;
string LeetCode::longestPalindrome(string s) {
        int len = s.length();
        int d[MAX][MAX]={0};
        int maxlen = 1;
        int mlen=1,first=0;
        for(int i = 0;i<len;i++) {
                d[i][i] = 1;
        }
        for(int i = 0;i < len-1;i++){
                if(s[i]==s[i+1]){
                        d[i][i+1]=1;
                        first = i;
                        maxlen = 2;
                }
        }


        for(mlen = 3;mlen < len+1;mlen++){
                for(int i = 0;i<len+1-mlen;i++){
                        int j = i+mlen-1;
                        if(d[i+1][j-1]==1&&s[i]==s[j]){
                                d[i][j] = 1;
                                first = i;
                                maxlen = mlen;
                        }
                }
        }
        return s.substr(first,maxlen);
}
int main(){
        LeetCode l;
        string r ;
        r = l.longestPalindrome("abcbe");
        cout<<r<<endl;
        return 0;
}