#include <bits/stdc++.h>
using namespace std;

#define MAXN 200100

bool visited[MAXN];
vector<vector<int>> gr;

void dfs(int node) {
    if (visited[node]) return;
    visited[node] = true;

    for (auto &e : gr[node]) {
        dfs(e);
    }
}

void bfs(int node) {
    queue<int> q;
    visited[node] = true;
    q.push(node);

    while (!q.empty())
    {
        int u = q.front(); q.pop();
        
        for (auto &e : gr[u]) {
            if (!visited[e]) {
                q.push(e);
                visited[e] = true;
            }
        }
    }
}