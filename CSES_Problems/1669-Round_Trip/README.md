# Round Trip (ID: 1669)

**Problem Link:** [https://cses.fi/problemset/task/1669/](https://cses.fi/problemset/task/1669/)

## Problem Description

Byteland has n cities and m roads between them. Your task is to design a round trip that begins in a city, goes through two or more other cities, and finally returns to the starting city. Every intermediate city on the route has to be distinct.

## Solution

```cpp
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<int> parent, vis;
int cycle_start = -1, cycle_end = -1;

bool dfs(int node, int par)
{
    vis[node] = 1;

    for (auto nbr : adj[node])
    {
        if (nbr == par) continue;

        if (!vis[nbr])
        {
            parent[nbr] = node;
            if (dfs(nbr, node)) return true;
        }
        else
        {
            cycle_start = nbr;
            cycle_end = node;
            return true;
        }
    }
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    adj.resize(n + 1);
    parent.assign(n + 1, -1);
    vis.assign(n + 1, 0);

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            if (dfs(i, -1)) break;
        }
    }

    if (cycle_start == -1)
    {
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    // reconstruct cycle
    vector<int> path;
    path.push_back(cycle_start);

    for (int v = cycle_end; v != cycle_start; v = parent[v])
    path.push_back(v);

    path.push_back(cycle_start);

    reverse(path.begin(), path.end());

    cout << path.size() << "\n";
    for (auto x : path) cout << x << " ";
}
```
