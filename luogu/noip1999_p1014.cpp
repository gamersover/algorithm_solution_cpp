//
// Created by 曹钦平 on 2022/7/6.
//
#include<iostream>
#include<cmath>
using namespace std;

int getSum(int n){
    return ceil((pow(1 + 8*n, 0.5) - 1) / 2);
}

int main(){
    int n;
    cin >> n;
    int s = getSum(n);
    int n1 = n - ((s * (s - 1)) >> 1);
    int n2 = (s + 1) - n1;
    if (s % 2){
        cout << n2 << "/" << n1 << endl;
    }
    else{
        cout << n1 << "/" << n2 << endl;
    }
    return 0;
}