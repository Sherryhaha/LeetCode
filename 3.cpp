//
// Created by sunguoyan on 2017/2/22.
//

#include "LeetCode.h"

//求最长子串
int lengthOfLongestSubstring(string s) {
    vector<int> table(200, 0);
    int count = 0;
    int max_len = 0;
    if (s.length() == 0) {
        max_len = 0;
    }
    int k = 0;
    for (int i = 0; i < s.length(); i++) {
        if (table[s[i]] < k+1) {
            count++;
            table[s[i]] = k+1;
        } else {
            count = 1;
            k++;
        }
        if (count > max_len) {
            max_len = count;
        }
    }
    return max_len;
}

int main(){
    string s = "dvdf";

    int result = lengthOfLongestSubstring(s);

    cout << result<<endl;
    return 0;
}