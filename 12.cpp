//
// Created by sunguoyan on 2017/3/29.
//
#include "LeetCode.h"
string intToRoman(int num) {
    string result;
    string roman[] = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
    int value[] = {1000,900,500,400,100,90,50,40,10,9,5,4,1};
    for(int i = 0;num!=0;++i){
        while(num>=value[i]){
            num = num-value[i];
            result = result + roman[i];
        }
    }
    return result;
}

int main(){
    int test = 1234;
    string result = intToRoman(test);
    cout<<result<<endl;
    return 0;
}