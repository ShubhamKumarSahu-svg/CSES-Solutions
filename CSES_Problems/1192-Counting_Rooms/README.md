# Counting Rooms (ID: 1192)

**Problem Link:** [https://cses.fi/problemset/task/1192/](https://cses.fi/problemset/task/1192/)

## Problem Description

You are given a map of a building, and your task is to count the number of its rooms. The size of the map is n \times m squares, and each square is either floor or wall. You can walk left, right, up, and down through the floor squares.

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

vector<int> dr = {-1, 0, 1, 0};
vector<int> dc = {0, 1, 0, -1};

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> matrix(n, vector<int>(m, 0));
    vector<vector<int>> vis(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
    {
        char ch;
        cin >> ch;
        if (ch == '.')
        matrix[i][j] = 1;
    }

    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] == 1 && !vis[i][j])
            {
                cnt++;
                queue<pair<int, int>> q;
                q.push({i, j});
                vis[i][j] = 1;
                while (!q.empty())
                {
                    int row = q.front().first;
                    int col = q.front().second;
                    q.pop();
                    for (int k = 0; k < 4; k++)
                    {
                        int nrow = row + dr[k];
                        int ncol = col + dc[k];
                        if (nrow < 0 || nrow >= n || ncol < 0 || ncol >= m || vis[nrow][ncol] || matrix[nrow][ncol] == 0)
                        continue;

                        vis[nrow][ncol] = 1;
                        q.push({nrow, ncol});
                    }
                }
            }
        }
    }
    cout << cnt << endl;
}

signed main()
{
    fastIO();
    solve();
    return 0;
}
```
