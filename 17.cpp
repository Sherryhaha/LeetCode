//
// Created by sunguoyan on 2017/4/17.
//


//电话号码数字对应的字母组合。
#include "LeetCode.h"
vector<string> letterCombinations(string digits) {
    if(digits.empty()) return vector<string>();
    static const vector<string> value = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    vector<string> result;
    result.push_back("");
    for(int i = 0;i<digits.size();i++){
        int num = digits[i]-'0';
        if(num<0||num>9){
            break;
        }
        vector<string> tmp;
        const string& condidate = value[num];
        for(int j = 0;j < condidate.size();j++){
            for(int k =0;k<result.size();k++){
                tmp.push_back(result[k]+condidate[j]);
            }
        }
        result.swap(tmp);           //交换result和tmp
    }
    return result;
}

int main(){
    string test = "23";
    vector<string> result = letterCombinations(test);
    for(int i = 0;i<result.size();i++){
        cout<<result[i]<<" ";
    }
    return 0;
}