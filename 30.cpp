//
// Created by sunguoyan on 2017/5/11.
//
// 给一个字符串s和一组长度相等的word，在s中找出由这些word串联后形成的子序列

#include "LeetCode.h"
#include <map>

vector<int> findSubstring_my(string s, vector<string>& words) {
    vector<int> result;
    if(s == "" || words.empty())
        return result;
    int s_len = s.size();
    int words_len = words[0].size();
    int words_count = words.size();
    int sub_len = words_count*words_len;

    map<string,int> wordMap;
    for(int i = 0;i < words_count;i++){
        wordMap[words[i]] += 1;
    }
    int i = 0;
    int count;
    while(i < s_len - sub_len + 1){
         count = 0;
        map<string,int> tmpMap(wordMap);
        int k = i;
        int subCount = i+sub_len;
        while(k <  subCount){
            string tmp = s.substr(k,words_len);
            if(tmpMap.find(tmp) == tmpMap.end()){
                i++;
                break;
            }else{
                if(tmpMap[tmp] > 0){
                    tmpMap[tmp]--;
                    k += words_len;
                    count++;
                }else{
                    i++;
                    break;
                }
            }
            if(count == words_count){
                result.push_back(i);
                tmpMap.clear();
                i++;
            }
        }

    }
    return result;
}


int main(){
    string s = "aaa";
    vector<string> words;
    words.push_back("a");
    words.push_back("a");


    for(int i = 0 ;i<words.size();i++){
        cout<< words[i]<<endl;
    }

    vector<int> result;
    result = findSubstring_my(s,words);
    int len = result.size();
    cout<<"长度为:"<<len<<endl;
    for(int i = 0;i < result.size() ;i++){
        cout<<result[i]<<endl;
    }
    return 0;
}