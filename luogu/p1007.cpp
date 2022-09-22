//
// Created by 曹钦平 on 2022/6/22.
// https://www.luogu.com.cn/problem/P1007
//

#include <iostream>
using namespace std;

int main(){
    int l, n, rmax = 0, rmin = 0, curr;
    cin >> l >> n;
    while (n--){
        cin >> curr;
        int cmin = curr > (l + 1 - curr) ? (l + 1 - curr) : curr;
        int cmax = curr > (l + 1 - curr) ? curr : (l + 1 - curr);
        rmin = rmin > cmin ? rmin : cmin;
        rmax = rmax > cmax ? rmax : cmax;
    }
    cout << rmin << " " << rmax << endl;
    return 0;
}
