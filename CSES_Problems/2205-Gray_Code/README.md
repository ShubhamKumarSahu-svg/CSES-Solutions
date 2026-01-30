# Gray Code (ID: 2205)

**Problem Link:** [https://cses.fi/problemset/task/2205/](https://cses.fi/problemset/task/2205/)

## Problem Description

A Gray code is a list of all 2^n bit strings of length n, where any two successive strings differ in exactly one bit (i.e., their Hamming distance is one).

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
#define printarrn(v)   \
for (auto &x : v)    \
cout << x << "\n"; \
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

void f(vector<string> &arr, string s, int i, int n, bool isChanged)
{
    if (i == n)
    {
        arr.push_back(s);
        return;
    }

    if (!isChanged)
    {
        // NOT CHANGED
        // 0
        s[i] = '0';
        f(arr, s, i + 1, n, false);

        // 1
        s[i] = '1';
        f(arr, s, i + 1, n, true);
    }
    else
    {
        // CHANGED
        // 1
        s[i] = '1';
        f(arr, s, i + 1, n, false);

        // 0
        s[i] = '0';
        f(arr, s, i + 1, n, true);
    }
}

void solve()
{
    int n;
    cin >> n;
    char a = '0';
    string s(n, a);
    vector<string> arr;
    f(arr, s, 0, n, false);
    printarrn(arr);
}

signed main()
{
    fastIO();
    solve();
    return 0;
}
```
