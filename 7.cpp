//
// Created by sunguoyan on 2017/2/27.
//
#include "LeetCode.h"

int reverse(int x) {
    vector<int> reverseArray;
    int quotient = x;
    int remainder;
    long long reverseNumber = 0;
    while (quotient ) {
        remainder = quotient % 10;
        reverseArray.push_back(remainder);
        quotient = quotient / 10;
    }
    int len = reverseArray.size();
    for (int i = 0, pos = len - 1; i < len; i++, pos--) {
        reverseNumber += pow(10, pos) * reverseArray[i];
    }
    if(reverseNumber<INT_MIN||reverseNumber>INT_MAX){
        return 0;
    }

    return (reverseNumber<INT_MIN||reverseNumber>INT_MAX)?0:reverseNumber;
}

int reverse_simple(int x){
    long long reverseNumber = 0;
    while(x){
        reverseNumber = reverseNumber*10 + x%10;
        x = x/10;
    }
    return (reverseNumber<INT_MIN||reverseNumber>INT_MAX)?0:reverseNumber;
}


int main() {
    int x = -1234567899;
    int result = reverse(x);
    cout << result << endl;
}