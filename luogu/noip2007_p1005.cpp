//
// Created by 曹钦平 on 2022/6/13.
//

/**
# [NOIP2007 提高组] 矩阵取数游戏

## 题目描述

帅帅经常跟同学玩一个矩阵取数游戏：对于一个给定的 $n \times m$ 的矩阵，矩阵中的每个元素 $a_{i,j}$ 均为非负整数。游戏规则如下：

1. 每次取数时须从每行各取走一个元素，共 $n$ 个。经过 $m$ 次后取完矩阵内所有元素；
2. 每次取走的各个元素只能是该元素所在行的行首或行尾；
3. 每次取数都有一个得分值，为每行取数的得分之和，每行取数的得分 = 被取走的元素值 $\times 2^i$，其中 $i$ 表示第 $i$ 次取数（从 $1$ 开始编号）；
4. 游戏结束总得分为 $m$ 次取数得分之和。

帅帅想请你帮忙写一个程序，对于任意矩阵，可以求出取数后的最大得分。

## 输入格式

输入文件包括 $n+1$ 行：

第一行为两个用空格隔开的整数 $n$ 和 $m$。

第 $2\sim n+1$ 行为 $n \times m$ 矩阵，其中每行有 $m$ 个用单个空格隔开的非负整数。

## 输出格式

输出文件仅包含 $1$ 行，为一个整数，即输入矩阵取数后的最大得分。

## 样例 #1

### 样例输入 #1

```
2 3
1 2 3
3 4 2
```

### 样例输出 #1

```
82
```

## 提示

NOIP 2007 提高第三题。

数据范围：

$60\%$ 的数据满足：$1\le n,m\le 30$，答案不超过 $10^{16}$。

$100\%$ 的数据满足：$1\le n,m\le 80$，$0\le a_{i,j}\le1000$。
**/


#include<iostream>
#include<cmath>

using namespace std;

__int128 a[100];
__int128 dp[81][81];


inline void input(__int128 &s)
{
    s=0;
    char c=' ';
    while(c>'9'||c<'0') c=getchar();
    while(c>='0'&&c<='9')
    {
        s=s*10+c-'0';
        c=getchar();
    }
}

inline void output(__int128 x)
{
    if(x>9)
        output(x/10);
    putchar(x%10+'0');
}


__int128 get_sum(__int128 arr[], int i, int j, __int128 p){
    if (i == j){
        return arr[i] * p;
    }
    long long left = get_sum(arr, i+1, j, p+p) + arr[i] * p;
    long long right = get_sum(arr, i, j-1, p+p) + arr[j] * p;
    return max(left, right);
}

__int128 get_sum_dp(__int128 arr[], int m, __int128 p){
    for(int len=1; len<=m; len++){
        for(int i=len; i<=m; i++){
            dp[len][i] = max(dp[len-1][i]*p + arr[i-len]*p, dp[len-1][i-1]*p + arr[i-1]*p);
        }
    }
    return dp[m][m];
}


int main(){
    int n, m;
    cin >> n >> m;
    __int128 ans = 0;
    for(int i=0; i<n; i++){
        for(int j =0; j<m; j++)
            input(a[j]);
        ans += get_sum_dp(a, m, 2);
    }
    output(ans);
    return 0;
}