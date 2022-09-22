#include <iostream>
using namespace std;

/**
 棋盘上 A 点有一个过河卒，需要走到目标 B 点。卒行走的规则：可以向下、或者向右。同时在棋盘上 C 点有一个对方的马，
 该马所在的点和所有跳跃一步可达的点称为对方马的控制点。因此称之为“马拦过河卒”。
 棋盘用坐标表示，A 点 (0,0)、B 点 (n,m)，同样马的位置坐标是需要给出的。
 现在要求你计算出卒从 AA 点能够到达 BB 点的路径的条数，假设马的位置是固定不动的，并不是卒走一步马走一步。
    输入格式:
    一行四个正整数，分别表示 BB 点坐标和马的坐标。
    输出格式:
    一个整数，表示所有的路径条数。
    说明/提示：
    对于 100% 的数据，1<=n,m<=20, 0<=马的坐标<=20。
**/

bool is_horse_pos(int x, int y, int hm, int hn){
    return ((abs(x-hm) == 2 and abs(y-hn) == 1)
            or ((abs(x-hm) == 1 and abs(y-hn) == 2))
            or ((x == hm) and (y == hn)));
}

long long solve(int m, int n, int hm, int hn) {
    long long dp[21][21];
    dp[0][0] = 1;
    for(int i=1; i<=m; i++) {
        if (is_horse_pos(i, 0, hm, hn))
            dp[i][0] = 0;
        else
            dp[i][0] = dp[i-1][0];
    }
    for(int j=1; j<=n; j++){
        if (is_horse_pos(0, j, hm, hn))
            dp[0][j] = 0;
        else
            dp[0][j] = dp[0][j-1];
    }
    for (int i = 1; i <= m; i++){
        for (int j = 1; j <= n; j++){
            if (is_horse_pos(i, j, hm, hn))
                dp[i][j] = 0;
            else
                dp[i][j] = dp[i][j-1] + dp[i-1][j];
        }
    }
    return dp[m][n];
}


int main(){
    int m, n, hm, hn;
    cin >> m >> n >> hm >> hn;
    cout << solve(m, n, hm, hn) << endl;
    return 0;
}