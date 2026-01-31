# Chessboard and Queens (ID: 1624)

**Problem Link:** [https://cses.fi/problemset/task/1624/](https://cses.fi/problemset/task/1624/)

## Problem Description

Your task is to place eight queens on a chessboard so that no two queens are attacking each other. As an additional challenge, each square is either free or reserved, and you can only place queens on the free squares. However, the reserved squares do not prevent queens from attacking each other.

## Solution

```cpp
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define vi vector<int>
#define vvi vector<vector<int>>
#define pii pair<int, int>
#define vpii vector<pair<int, int>>
#define mii map<int, int>
#define umii unordered_map<int, int>
#define si set<int>
#define msi multiset<int>

#define printno cout << "NO" << endl;
#define printyes cout << "YES" << endl;
#define print(x) cout << (x) << endl;
#define printsp(x) cout << (x) << " ";
#define printarr(v) \
for (auto &x : v) \
cout << x << " ";
#define printarrn(v)  \
for (auto &x : v)   \
cout << x << " "; \
cout << endl;

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define input(v, n)           \
for (int i = 0; i < n; i++) \
cin >> v[i]
#define input1(v, n)           \
for (int i = 1; i <= n; i++) \
cin >> v[i]

const int mod = 1e9 + 7;
const int inf = INT_MAX;
const int m_inf = INT_MIN;

void fastIO()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
}
int n = 8;
vector<vector<char>> v(n, vector<char>(n));

int f(int j, unordered_set<int> &ri, unordered_set<int> &rd1, unordered_set<int> &rd2)
{
    if (j == n)
    return 1;

    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        int d1 = i - j;
        int d2 = i + j;
        if (v[i][j] != '*' && ri.count(i) == 0 && rd1.count(d1) == 0 && rd2.count(d2) == 0)
        {
            ri.insert(i);
            rd1.insert(d1);
            rd2.insert(d2);
            cnt += f(j + 1, ri, rd1, rd2);
            ri.erase(i);
            rd1.erase(d1);
            rd2.erase(d2);
        }
    }
    return cnt;
}

void solve()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> v[i][j];
        }
    }
    unordered_set<int> ri, rd1, rd2;
    cout << f(0, ri, rd1, rd2) << endl;
}

signed main()
{
    fastIO();
    solve();
    return 0;
}
```
