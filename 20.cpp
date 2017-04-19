//
// Created by sunguoyan on 2017/4/19.
//一道关于栈的使用的题目，括号匹配
#include<stack>
#include "LeetCode.h"
//bool isValid(string s) {
//    if(s.size() % 2 != 0){
//        return false;
//    }
//    bool result = false;
//    int index;
//    string character = {'{','[','(',')',']','}'};
//    for(int i = 0;i<s.size();i++){
//        index = 6;
//        for(int k = 0;k<3;k++){
//            if(s[i]==character[k]){
//                index = 5-k;
//            }
//        }
//        if(index == 6)
//            continue;
//        for(int j = i+1;j<s.size();j++){
//            if(s[j] == character[index] && (i+j) % 2 != 0) {
//                result = true;
//            }
//        }
//    }
//    return result;
//}

bool isValid(string s) {
    stack<char> stack_judge;
    for(char&c:s){
        switch(c){
            case'{':
            case'[':
            case '(':stack_judge.push(c);
                break;
            case'}':if(stack_judge.empty()||stack_judge.top()!='{') return false;else stack_judge.pop();
                break;
            case']':if(stack_judge.empty()||stack_judge.top()!='[') return false;else stack_judge.pop();
                break;
            case')':if(stack_judge.empty()||stack_judge.top()!='(') return false;else stack_judge.pop();
            default:;
        }
    }
    return stack_judge.empty();

}

int main(){
    string a = "(()(";
    bool result = isValid(a);
    cout<<boolalpha<<result<<endl;
    return 0;
}