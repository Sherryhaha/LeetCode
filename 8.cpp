//
// Created by sunguoyan on 2017/3/6.
//

#include "LeetCode.h"
int myAtoi(string str) {
    long long  result = 0;
    bool is_positive = true;
    int index = 0;
    long long INT_MIN_abs = INT_MIN;
    INT_MIN_abs = 0-INT_MIN_abs;
    while(str[index]==' '){
        index++;
    }
    if(str[index]=='-'){
        is_positive = false;
        index++;
    }
    else if(str[index] == '+'){
        is_positive = true;
        index++;
    }else if(str[index]-'0'>=0&&str[index]-'0'<=9){
       is_positive = true;
    }else{
        return (int)result;
    }
    while(str[index]-'0'>=0&&str[index]-'0'<=9){
        int digit = str[index]-'0';
        result = result*10+digit;
        if(result>INT_MAX && is_positive){
            result = INT_MAX;
            return result;
        }
        if(result>INT_MIN_abs && !is_positive){
            result = INT_MIN;
            return result;
        }
        index++;
    }
    if(!is_positive){
        return -result;
    }
    return (int)result;

}


int main(){
    string a = "   -1";
    int result = myAtoi(a);
    cout<<result<<endl;
    return 0;
}