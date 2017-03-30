//
// Created by sunguoyan on 2017/3/30.
// 将罗马数字转为整数，整数是在1-3999范围内，要先把握下罗马数字的规律，1是"I"，两个I就是2...到4是IV,5是V...
// 9是IX，10是X,50是L,100是C，500是D,10000是M，因此要注意的是如果识别类似IV,IX,XL....等组合成的罗马数字需要
// 有方法，方法就是从字符串后面往前遍历，如果后一个数字大于前一个数字，那么就减去前一个数字，否则就加上前一个数字

#include "LeetCode.h"

int romanToInt(string s) {
    unordered_map<char,int> roman{{'I',1},
                              {'V',5},
                              {'X',10},
                              {'L',50},
                              {'C',100},
                              {'D',500},
                              {'M',1000}};
    int sum = roman[s.back()];
    for(int i = s.length()-2;i>=0;i--){
        if(roman[s[i]] < roman[s[i+1]]){
            sum = sum - roman[s[i]];
        }else{
            sum = sum + roman[s[i]];
        }
    }
    return sum;
}

int main(){
    int sum = romanToInt("MXXX");
    cout<<sum<<endl;
    return 0;
}