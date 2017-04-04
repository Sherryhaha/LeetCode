//
// Created by sunguoyan on 2017/4/4.
//

#include "LeetCode.h"

string longestCommonPrefix(vector<string>& strs) {
    if(0 == strs.size()){
        return "";
    }
    string prefix = strs[0];

    int len = strs.size();

    for(int i = 1;i<strs.size();i++){
        if(0 == prefix.length() || 0 == strs[i].length()){
            return "";
        }
        int len = prefix.length()>strs[i].length()?prefix.length():strs[i].length();

        int j;
        for(j = 0;j<len;j++){
            if(prefix[j]!=strs[i][j])
                break;
        }

        prefix = prefix.substr(0,j);
    }
    return prefix;
}