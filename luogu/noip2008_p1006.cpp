//
// Created by 曹钦平 on 2022/6/21.
// https://www.luogu.com.cn/problem/P1006
//

#include<iostream>
using namespace std;

const int MAXN = 52;
int arr[MAXN][MAXN];
int dp[MAXN][MAXN][MAXN][MAXN];


int main(){
    int m, n;
    cin >> m >> n;
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cin >> arr[i][j];
        }
    }
    for(int i=1; i<=m; i++){
        for(int j=1; j<=n; j++){
            int maxk = min(i + j - 1, m);
            int mink = max(1, i + j - n);
            for(int k=mink; k<=maxk; k++){
                int l = i + j - k;
                dp[i][j][k][l] = max(max(dp[i-1][j][k-1][l], dp[i-1][j][k][l-1]),
                                     max(dp[i][j-1][k-1][l], dp[i][j-1][k][l-1]));
                if (i == k && j == l)
                    dp[i][j][k][l] += arr[i-1][j-1];
                else
                    dp[i][j][k][l] += arr[i-1][j-1] + arr[k-1][l-1];
            }
        }
    }

    cout << dp[m][n][m][n] << endl;
    return 0;
}