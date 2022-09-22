
/**
题目描述
设有 N×N 的方格图 (N≤9)，我们将其中的某些方格中填入正整数，而其他的方格中则放入数字 0。如下图所示（见样例）:

A
 0  0  0  0  0  0  0  0
 0  0 13  0  0  6  0  0
 0  0  0  0  7  0  0  0
 0  0  0 14  0  0  0  0
 0 21  0  0  0  4  0  0
 0  0 15  0  0  0  0  0
 0 14  0  0  0  0  0  0
 0  0  0  0  0  0  0  0
                         B
某人从图的左上角的 A 点出发，可以向下行走，也可以向右走，直到到达右下角的 B 点。在走过的路上，他可以取走方格中的数（取走后的方格中将变为数字 0）。
此人从 A 点到 B 点共走两次，试找出 2 条这样的路径，使得取得的数之和为最大。

输入格式
输入的第一行为一个整数 N（表示 N×N 的方格图），接下来的每行有三个整数，前两个表示位置，第三个数为该位置上所放的数。一行单独的 0 表示输入结束。

输出格式
只需输出一个整数，表示 2 条路径上取得的最大的和。
 **/

#include <iostream>

using namespace std;

int arr[10][10];
int dp[10][10][10][10];

int main() {
    int n, col, row, num;
    cin >> n;

    while (true) {
        cin >> col >> row >> num;
        if (col == 0 && row == 0 && num == 0)
            break;
        arr[col][row] = num;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int maxk = (i + j) > n ? n : (i + j);
            for (int k = 1; k <= maxk; k++) {
                int l = i + j - k;
                dp[i][j][k][l] = max(max(dp[i - 1][j][k - 1][l], dp[i][j - 1][k - 1][l]),
                                     max(dp[i - 1][j][k][l - 1], dp[i][j - 1][k][l - 1]));
                if (i == k && j == l)
                    dp[i][j][k][l] += arr[i][j];
                else
                    dp[i][j][k][l] += arr[i][j] + arr[k][l];
            }
        }
    }
    cout << dp[n][n][n][n] << endl;
}