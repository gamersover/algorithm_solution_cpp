//
// Created by 曹钦平 on 2022/5/31.
// 并查集 模板
//
#include<iostream>
using namespace std;

const int maxn = 1e6 + 5;

int fa[maxn];


void init(int n){
    for(int i=0; i<n; i++){
        fa[i] = i;
    }
}

int findfa(int i){
    if (fa[i] == i) return i;
    fa[i] = findfa(fa[i]);
    return fa[i];
}

void merge(int x, int y){
    x = findfa(x);
    y = findfa(y);
    fa[x] = y;
}

bool query(int x, int y){
    return findfa(x) == findfa(y);
}


int main(){
    init(10);
    merge(3, 5);
    merge(1, 3);
    cout << query(1, 5) << endl;
    cout << query(1, 4) << endl;
    return 0;
}