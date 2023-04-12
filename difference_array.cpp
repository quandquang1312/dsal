#include <bits/stdc++.h>
using namespace std;

#define MAXN 200100
int n, arr[MAXN], diff[MAXN];

void update(int l, int r, int vl) {
    diff[l] += vl;
    if (r + 1 < n) diff[r] -= vl;
}

void apply_update()
{
    /*
    // update the value of arr by the prefix sum of diff
    */
    for (int i=0; i<n; i++) diff[i] += diff[i-1];
    for (int i=0; i<n; i++) arr[i] += diff[i]; 
}