//
// Created by 曹钦平 on 2022/5/31.
// https://uoj.ac/problem/2
//
#include<iostream>
#include<string>
using namespace std;


int main(){
    int n, m;
    cin >> n >> m;
    int ones = INT32_MAX, zeros = 0;
    for(int i=0; i<n; i++){
        string s;
        int num;
        cin >> s >> num;
        if(s == "AND") {
            ones &= num;
            zeros &= num;
        }
        else if (s == "OR") {
            ones |= num;
            zeros |= num;
        }
        else{
            ones ^= num;
            zeros ^= num;
        }
    }
    int ans = 0;
    for(int i=0; i<m+1; i++){
        int tmp = (~i & zeros) | (i & ones);
        ans = tmp > ans ? tmp : ans;
    }
    cout << ans << endl;
}