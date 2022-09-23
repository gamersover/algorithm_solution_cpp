//
// Created by 曹钦平 on 2022/9/23.
// gcd 和 扩展gcd
//

#include <iostream>
using namespace std;


int gcd(int n, int m){
    if (m > n){
        swap(n, m);
    }

    while(m){
        int t = n % m;
        n = m;
        m = t;
    }
    return n;
}

int exgcd(int n, int m, int &x, int &y){
    // x * n + y * m = gcd(n, m)
    bool swaped = false;
    if(m > n) {
        swaped = true;
        swap(n, m);
    }
    int x0 = 1, y0 = 0;
    int x1 = 0, y1 = 1;
    int xt, yt, t;
    while(m){
        int q = n / m;
        xt = x0 - q * x1;
        yt = y0 - q * y1;
        t = n - q * m;
        x0 = x1, y0 = y1;
        x1 = xt, y1 = yt;
        n = m, m = t;
    }
    if (swaped) swap(x0, y0);
    x = x0, y = y0;
    return n;
}


int main(){
    int x = 0, y = 0;
    cout << exgcd(231, 236, x, y) << endl;
    cout << x << "," << y << endl;
}
