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

int lengthOfLongestSubstring_sun(string s) {
    vector<int> dict(256, -1);
    int maxLen = 0, start = -1;
    for (int i = 0; i != s.length(); i++) {
        if (dict[s[i]] > start)
            start = dict[s[i]];
        dict[s[i]] = i;
        maxLen = max(maxLen, i - start);
    }
    return maxLen;
}

//O(n)解法
// i-m+1算出的是以i结尾，不重复的子串长度，意思就是前面m个字符跟后面的i-m+1个字符中有重复的
int lengthOfLongestSubstring_simple(string s) {
    // for ASCII char sequence, use this as a hashmap
    vector<int> charIndex(256, -1);
    int longest = 0, m = 0;

    for (int i = 0; i < s.length(); i++) {
        m = max(charIndex[s[i]] + 1, m);    // automatically takes care of -1 case
        charIndex[s[i]] = i;
        longest = max(longest, i - m + 1);
    }

    return longest;
}

int main() {
    string s = "dvdf";

    int result = lengthOfLongestSubstring_simple(s);

    cout << result << endl;
    return 0;
}