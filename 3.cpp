//
// Created by sunguoyan on 2017/2/22.
//

#include "LeetCode.h"

//求最长不重复子串，利用两重循环，判断重复与否，要注意边界的判断。

int lengthOfLongestSubstring(string s) {
    int max_len = 0;
    if (s.length() == 1) {
        return 1;
    }

    for (int i = 0; i < s.length(); i++) {
        int table[300];
        for (int k = 0; k < 300; k++) {
            table[k] = 0;
        }
        table[s[i]] = 1;
        for (int j = i + 1; j < s.length(); j++) {
            if (table[s[j]] == 1) {
                if (j - i > max_len) {
                    max_len = j - i;
                }
                break;
            }
            //当向后的子串一直没有重复时，直至最后一个字符，截止条件。
            if (j == s.length() - 1) {
                if (j - i + 1 > max_len) {
                    max_len = j - i + 1;
                }
                break;
            }
            table[s[j]] = 1;
        }
    }
    return max_len;

}

int main() {
    string s = "dvdf";

    int result = lengthOfLongestSubstring(s);

    cout << result << endl;
    return 0;
}