//
// Created by sunguoyan on 2017/4/25.
//


//给n对括号，计算可以有多少种匹配情况。这利用递归来做，n表示还剩多少个左括号没有放入，m表示需要放入多少个右括号
//一般来讲，在任意一个位置，从这个位置往前数，左括号的个数肯定>=右括号的个数，右括号是按照已经放入多少个左括号后来确定的。
//
#include "LeetCode.h"
void generateParenthesisDFS(vector<string>&result,string s,int n,int m){
    if(n ==0 &&m==0){
        result.push_back(s);
        return;
    }
    if(m>0) generateParenthesisDFS(result,s+')',n,m-1);
    if(n>0) generateParenthesisDFS(result,s+'(',n-1,m+1);
}

vector<string> generateParenthesis(int n) {
    vector<string> result;
    generateParenthesisDFS(result,"",n,0);
    return result;
}

int main(){
    vector<string> result;
    result  = generateParenthesis(5);
    for(int i = 0;i<result.size();i++){
        cout<<result[i]<<endl;
    }
    return 0;
}