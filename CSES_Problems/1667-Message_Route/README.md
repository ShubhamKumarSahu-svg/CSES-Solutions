# Message Route (ID: 1667)

**Problem Link:** [https://cses.fi/problemset/task/1667/](https://cses.fi/problemset/task/1667/)

## Problem Description

Syrjälä's network has n computers and m connections. Your task is to find out if Uolevi can send a message to Maija, and if it is possible, what is the minimum number of computers on such a route.

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
    vector<int> parent(n + 1, -1);

    queue<int> q;
    q.push(1);
    vis[1] = 1;

    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        if (node == n)
        break;

        for (auto nbr : adj[node])
        {
            if (!vis[nbr])
            {
                parent[nbr] = node;
                vis[nbr] = 1;
                q.push(nbr);
            }
        }
    }

    if (vis[n])
    {
        vector<int> path;
        int i = n;
        while (i != -1)
        {
            path.push_back(i);
            i = parent[i];
        }
        int len = path.size();
        cout << len << endl;
        for (int i = len - 1; i >= 0; i--)
        {
            cout << path[i] << " ";
        }
    }
    else
    {
        cout << "IMPOSSIBLE" << endl;
    }
}

signed main()
{
    fastIO();
    solve();
    return 0;
}
```
