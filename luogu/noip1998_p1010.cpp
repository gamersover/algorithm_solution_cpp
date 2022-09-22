//
// Created by 曹钦平 on 2022/6/22.
// https://www.luogu.com.cn/problem/P1010
//

#include<iostream>
#include<string>
#include<vector>
using namespace std;

string get_re(int n){
    if (n == 1) return "";
    if (n == 0) return "(0)";
    vector<int> arr;
    int start = 0;
    while(n){
        if(n & 1) arr.push_back(start);
        n >>= 1;
        start++;
    }
    string ans = "2" + get_re(arr[arr.size()-1]);
    for(int i=arr.size()-2; i>=0; i--){
        ans += "+2" + get_re(arr[i]);
    }
    return "(" + ans + ")";
}

string solve(int n){
     if(n == 1) return "2(0)";
     string ans = get_re(n);
     return ans.substr(1, ans.size()-2);
}


int main(){
    int n;
    cin >> n;
    cout << solve(137) << endl;
    return 0;
}