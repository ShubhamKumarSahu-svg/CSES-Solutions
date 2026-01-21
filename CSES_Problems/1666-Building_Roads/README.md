# Building Roads (ID: 1666)

**Problem Link:** [https://cses.fi/problemset/task/1666/](https://cses.fi/problemset/task/1666/)

## Problem Description

Byteland has n cities, and m roads between them. The goal is to construct new roads so that there is a route between any two cities.

## Solution

```cpp
#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const int inf = INT_MAX;
const int m_inf = INT_MIN;
#define int long long

void fastIO()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
}

void dfs(int node, vector<vector<int>> &adj, vector<int> &vis)
{
    vis[node] = 1;
    for (auto it : adj[node])
    {
        if (!vis[it])
        dfs(it, adj, vis);
    }
}

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<int> vis(n + 1, 0);
    vector<int> components;

    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            components.push_back(i);
            dfs(i, adj, vis);
        }
    }

    int len = components.size() - 1;
    cout << len << endl;
    for (int i = 0; i < len; i++)
    {
        cout << components[i] << " " << components[i + 1] << endl;
    }
}

signed main()
{
    fastIO();
    solve();
    return 0;
}
```
