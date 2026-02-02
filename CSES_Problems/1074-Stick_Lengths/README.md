# Stick Lengths (ID: 1074)

**Problem Link:** [https://cses.fi/problemset/task/1074/](https://cses.fi/problemset/task/1074/)

## Problem Description

There are n sticks with some lengths. Your task is to modify the sticks so that each stick has the same length.

## Solution

```cpp
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define vi vector<int>
#define vvi vector<vector<int>>
#define vc vector<char>
#define vvc vector<vector<char>>
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
#define printarr(v)                                                            \
for (auto &x : v)                                                            \
cout << x << " ";
#define printarrn(v)                                                           \
for (auto &x : v)                                                            \
cout << x << " ";                                                          \
cout << endl;

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

#define input(v, n)                                                            \
for (int i = 0; i < n; i++)                                                  \
cin >> v[i]
#define input1(v, n)                                                           \
for (int i = 1; i <= n; i++)                                                 \
cin >> v[i]

#define read1(a)                                                               \
int a;                                                                       \
cin >> a;
#define read2(a, b)                                                            \
int a, b;                                                                    \
cin >> a >> b;
#define read3(a, b, c)                                                         \
int a, b, c;                                                                 \
cin >> a >> b >> c;

#define forp(i, n) for (int i = 0; i < n; i++)
#define form(i, n) for (int i = n - 1; i >= 0; i--)

int mex(vector<int> a) {
    int n = a.size();
    for (int i = 0; i < n; i++) {
        while (a[i] >= 0 && a[i] < n && a[a[i]] != a[i]) {
            swap(a[i], a[a[i]]);
        }
    }
    for (int i = 0; i < n; i++) {
        if (a[i] != i)
        return i;
    }
    return n;
}

const int mod = 1e9 + 7;
const int inf = INT_MAX;
const int m_inf = INT_MIN;

void fastIO() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
}


void solve() {
    read1(n);
    vi v(n);
    int sum = 0;
    input(v, n);
    sort(all(v));
    int cost = 0;
    for (auto x : v) {
        cost += abs(x - v[n / 2]);
    }
    print(cost);
}

signed main() {
    fastIO();
    solve();
    return 0;
}
```
