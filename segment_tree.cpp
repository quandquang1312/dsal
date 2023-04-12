#include <bits/stdc++.h>
using namespace std;

#define MAXN 200100
int arr[MAXN], st[MAXN*4];

void build(int node, int l, int r) {
    if (l == r) st[node] = arr[l];
    else {
        int mid = (l+r) >> 1;
        build(node*2, l, mid);
        build(node*2+1, mid+1, r);
        // for sum segment tree
        st[node] = st[node*2] + st[node*2+1];
    }
}

int query(int node, int l, int r, int tl, int tr) {
    if (l <= tl && tr <= r) return st[node];
    if (r < tl || tr < l) return 0; // for sum segment tree
    int mid = (l+r) >> 1;
    // for sum segment tree
    return query(node*2, l, r, tl, mid) + query(node*2+1, l, r, mid+1, tr);
}