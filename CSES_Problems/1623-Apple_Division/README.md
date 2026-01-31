# Apple Division (ID: 1623)

**Problem Link:** [https://cses.fi/problemset/task/1623/](https://cses.fi/problemset/task/1623/)

## Problem Description

There are n apples with known weights. Your task is to divide the apples into two groups so that the difference between the weights of the groups is minimal.

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

int n;
vi(v);
int res = inf;
void f(int idx, int s1, int s2)
{
    if (idx == n)
    {
        res = min(res,abs(s1-s2));
        return;
    }

    f(idx + 1, s1 + v[idx], s2);
    f(idx + 1, s1, s2 + v[idx]);
}

void solve()
{
    cin >> n;
    v.resize(n);
    input(v, n);
    f(0, 0, 0);
    cout << res << endl;
}

signed main()
{
    fastIO();
    solve();
    return 0;
}
```
