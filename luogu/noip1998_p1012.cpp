//
// Created by 曹钦平 on 2022/6/27.
// https://www.luogu.com.cn/problem/P1012
//
#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

string arr[20];

bool compare(string s1, string s2){
    string a = s1 + s2;
    string b = s2 + s1;
    return a > b;
}

int main(){
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    sort(arr, arr+n, compare);
    string ans = "";
    for(int i=0; i<n; i++){
        ans += arr[i];
    }
    cout << ans << endl;
}