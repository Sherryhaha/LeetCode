//
// Created by sunguoyan on 2017/5/3.
//实现判断needle是否在haystack中，如果在，返回第一次出现的下标

//
#include "LeetCode.h"


int strStr(string haystack, string needle) {
    int len_hay = haystack.size();
    int len_needle = needle.size();
    if(len_hay < len_needle){
        return -1;
    }
    if(len_needle==0){
        return 0;
    }
    for(int i = 0;i<len_hay-len_needle+1;i++){
        if(haystack[i] == needle[0]) {
            int j;
            for (j = 1; j < len_needle;) {
                char test = haystack[i+j];
                char test2 = needle[j];
                cout<<test<<"----"<<test2<<endl;
                if(haystack[i+j]==needle[j]){
                    j++;
                }else{
                    break;
                }
            }
            if(j==len_needle){
                return i;
            }
        }
    }
    return -1;
}

int main(){
    string haystack = "a";
    string needle = "a";
    int result = strStr(haystack,needle);
    cout<<result<<endl;
    return 0;
}