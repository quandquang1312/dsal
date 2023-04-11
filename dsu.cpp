#include <bits/stdc++.h>
using namespace std;

#define MAXN 200100

int n, parent[MAXN], mrank[MAXN];

void init()
{
    for (int i=0; i<n; i++) {
        parent[i] = i;
        mrank[i] = 0; // for linking by rank
    }
}

int find(int node) {
    if (parent[node] == node) return node;
    return parent[node] = find(parent[node]);
}

void unite(int a, int b)
{
    int rootA = find(a);
    int rootB = find(b);
    /* linking by rank*/
    if (mrank[rootA] > mrank[rootB]) {
        parent[rootB] = rootA;
        mrank[rootA] = max(mrank[rootA], mrank[rootB] + 1);
    } else {
        parent[rootA] = rootB;
        mrank[rootB] = max(mrank[rootB], mrank[rootA] + 1);
    }

    /* random linking
    if (rand() % 2) parent[rootA] = rootB;
    else parent[rootB] = rootA;
    */
}