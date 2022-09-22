//
// Created by 曹钦平 on 2022/5/31.
// 线段树 模板
//

#include<iostream>

using namespace std;

const int maxn = 1e6 + 5;

struct Node {
    int l, r, sum, min, flag;
};

Node tree[4 * maxn];
int arr[maxn];

void build(int p, int l, int r) {
    tree[p].l = l;
    tree[p].r = r;
    if (l == r) {
        tree[p].sum = arr[l];
        return;
    }
    int mid = l + ((r - l) >> 1);
    build(2 * p, l, mid);
    build(2 * p + 1, mid + 1, r);
    tree[p].sum = tree[2 * p].sum + tree[2 * p + 1].sum;
}

// 单点更新与查询
void update(int p, int x, int num) {
    if (tree[p].l == tree[p].r) {
        tree[p].sum += num;
        return;
    }
    int mid = tree[p].l + ((tree[p].r - tree[p].l) >> 1);
    if (x <= mid) update(2 * p, x, num);
    else update(2 * p + 1, x, num);
    tree[p].sum = tree[2 * p].sum + tree[2 * p + 1].sum;
}

int query(int p, int x, int y) {
    if ((x == tree[p].l) && (tree[p].r == y)) return tree[p].sum;
    int mid = tree[p].l + ((tree[p].r - tree[p].l) >> 1), sum = 0;
    if (x <= mid) sum += query(2 * p, x, mid);
    if (mid < y) sum += query(2 * p + 1, mid + 1, y);
    return sum;
}

//区间更新与查询
void pushdown(int p){
    tree[2*p].sum += (tree[2*p].r - tree[2*p].l + 1) * tree[p].flag;
    tree[2*p+1].sum += (tree[2*p+1].r - tree[2*p+1].l + 1) * tree[p].flag;
    tree[2*p].flag += tree[p].flag;
    tree[2*p].flag += tree[p].flag;
    tree[p].flag = 0;
}

void update2(int p, int x, int y, int num){
    if(tree[p].l == x && tree[p].r == y){
        tree[p].sum += (tree[p].r - tree[p].l + 1) * num;
        tree[p].flag += num;
        return;
    }
    if(tree[p].flag && tree[p].l != tree[p].r) pushdown(p);
    int mid = tree[p].l + ((tree[p].r - tree[p].l) >> 1);
    if (x <= mid) update2(p*2, x, mid, num);
    if (mid < y) update2(p*2+1, mid+1, y, num);
    tree[p].sum = tree[2*p].sum + tree[2*p+1].sum;
}

int query2(int p, int x, int y){
    if(tree[p].l == tree[p].r) return tree[p].sum;
    if(tree[p].flag) pushdown(p);
    int mid = tree[p].l + ((tree[p].r - tree[p].l) >> 1), sum=0;
    if (x <= mid) sum += query2(p*2, x, mid);
    if (mid < y) sum += query2(p*2+1, mid+1, y);
    return sum;
}


int main() {
    int N = 5;
    for (int i = 0; i < N; i++) {
        arr[i] = 5 * i;
    }
    build(1, 0, 4);
    cout << query2(1, 2, 4) << endl;
    update2(1, 1, 3, 5);
    update2(1, 1, 3, 5);
    cout << query2(1, 3, 4) << endl;
    return 0;
}
