// CSES Problem 1668: Building Teams
// Link: https://cses.fi/problemset/task/1668/
// Description: There are n pupils in Uolevi's class, and m friendships between them. Your task ...

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
    for (int i = 1; i <= n; i++)
    {
        if (vis[i])
        continue;
        queue<int> q;
        q.push(i);
        vis[i] = 1;

        while (!q.empty())
        {
            int node = q.front();
            q.pop();

            for (auto nbr : adj[node])
            {
                if (!vis[nbr])
                {
                    vis[nbr] = 3 - vis[node];
                    q.push(nbr);
                }
                else if (vis[nbr] == vis[node])
                {
                    cout << "IMPOSSIBLE\n";
                    return;
                }
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout << vis[i] << " ";
    }
    cout << endl;
}

signed main()
{
    fastIO();
    solve();
    return 0;
}
