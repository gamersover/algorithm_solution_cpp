//
// Created by 曹钦平 on 2022/9/22.
// kmp算法模板
//
#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> calc_lps(string p){
    vector<int> lps(p.size(), 0);
    int j = 0;
    for(int i=1; i<p.size(); ++i) {
        while (j > 0 && p[i] != p[j]) {
            j = lps[j - 1];
        }

        if (p[i] == p[j]) {
            lps[i] = ++j;
        }
    }
    return lps;
}

vector<int> kmp(string s, string p){
    vector<int> lps = calc_lps(p);
    vector<int> matched_indices;
    int j = 0;
    for(int i=0; i < s.size(); ++i){
        while (j > 0 && s[i] != p[j]){
            j = lps[j-1];
        }

        if (s[i] == p[j]){
            if(j == p.size() - 1){
                matched_indices.push_back(i - j);
                j = lps[j];
            }
            else{
                ++j;
            }
        }
    }
    return matched_indices;
}


int main(){
    string s = "sfewiofjwiowflakswiowhdfawioefh";
    string p = "wiow";
    vector<int> ans = kmp(s, p);
    for(int index : ans) {
        cout << index << endl;
    }
}