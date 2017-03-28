//
// Created by sunguoyan on 2017/3/27.
//

#include "LeetCode.h"

bool isPalindrome(int x) {
    if(x<0|(x!=0&&x%10==0)){
        return false;
    }
    int sum = 0;
    while(x > sum){
        sum = x%10+sum*10;
        x = x / 10;
    }
    return ((x==sum)|(x==sum/10));
}


int main(){
    int x = 9;
    bool test = isPalindrome(x);
    cout<<test<<endl;
    return 0;
}