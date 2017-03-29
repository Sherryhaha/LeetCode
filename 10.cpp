//
// Created by sunguoyan on 2017/3/28.
//
#include "LeetCode.h"


//这里的*应该是代表对于前序的0个或多个的重复。
bool isMatch(string s, string p) {
    if(p.empty()){
        return s.empty();
    }
    if(p[1]=='*'){
        return (isMatch(s,p.substr(2))) || (!s.empty()&&(p[0]==s[0] || p[0]=='.')) && (isMatch(s.substr(1),p));
    }else{
        return (!s.empty()&&(p[0]==s[0] || p[0]=='.')&&isMatch(s.substr(1),p.substr(1)));
    }
}


int main(){
    bool test = isMatch("baab","c*a*b");
    cout<<test<<endl;
    return 0;
}