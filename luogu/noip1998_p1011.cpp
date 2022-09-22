//
// Created by 曹钦平 on 2022/6/24.
// https://www.luogu.com.cn/problem/P1011
//

#include<iostream>
using namespace std;

// 前两个值存储出发时人数，后两个值存储上车人数
int cnt[20][4];

int main(){
    int a, n, m, x;
    cin >> a >> n >> m >> x;
    cnt[0][0] = 1;
    cnt[0][1] = 0;
    cnt[0][2] = 1;
    cnt[0][3] = 0;
    cnt[1][0] = 1;
    cnt[1][1] = 0;
    cnt[1][2] = 0;
    cnt[1][3] = 1;
    for(int i=2; i<n-1; i++){
        cnt[i][0] = cnt[i-1][0] + cnt[i-2][2];
        cnt[i][1] = cnt[i-1][1] + cnt[i-2][3];
        cnt[i][2] = cnt[i-1][2] + cnt[i-2][2];
        cnt[i][3] = cnt[i-1][3] + cnt[i-2][3];
    }
    int b = (m - cnt[n-2][0] * a) / cnt[n-2][1];
    cout << cnt[x-1][0] * a + cnt[x-1][1] * b << endl;
    return 0;
}