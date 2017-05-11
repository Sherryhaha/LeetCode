//
// Created by sunguoyan on 2017/5/4.
//
#include "LeetCode.h"


long long int divideLong(long long dividend,long long divisor){

    if(divisor == 0){
        return INT_MAX;
    }
    if(dividend == 0){
        return 0;
    }

    int sign = 1;
    if ((dividend<0)^(divisor<0)){   //异或符号，相同为0,不同为1
        sign = -1;
    }


    long long int ret = 0;

    divisor = abs(divisor);
    dividend = abs(dividend);

    while(divisor<dividend){
        int shift = 0;
        long long int part = 1;
        while(dividend > (divisor<<shift)){
            shift++;
            part<<=1;
        }
        if(dividend == (divisor<<shift)){
            ret += part;
            break;
        }else{
            part>>=1;
            shift--;
        }
        ret += part;
        dividend -= (divisor<<shift);
    }
    if(divisor == dividend){
        ret++;
    }
    return ret*sign;

}

int divide(int dividend, int divisor) {
   long long int ret = divideLong(dividend,divisor);
    if(ret > INT_MAX || ret < INT_MIN)
        return INT_MAX;
    return ret;
}



int divide_2(int dividend, int divisor) {
   if(divisor == 0){
       return INT_MAX;
   }
    int sign = 1;
    if ((dividend<0)^(divisor<0)){   //异或符号，相同为0,不同为1
        sign = -1;
    }

    int res = 0;
    if(dividend == INT_MIN){
        dividend += abs(divisor);
        if(divisor == -1)
            return INT_MAX;
        res++;
    }
    if(divisor == INT_MIN){
        return res;
    }
    dividend = abs(dividend);
    divisor = abs(divisor);
    int digit = 0;
    while(divisor <= (dividend>>1)){
        divisor <<= 1;
        digit++;
    }
    while(digit >= 0){
        if(dividend >= divisor){
            res += 1<<digit;
            dividend -= divisor;
        }
        divisor >>= 1;
        digit--;
    }
    return sign*res;

}

int main(){

   int a = 24,b = 5;
  //  int ret = divide_2(2555555555555
  //                   ,5);
    a = a<<30;
    cout<<a<<endl;
   // cout<<"正确的："<<2555555555555/5<<endl;
   // cout<<ret;
}