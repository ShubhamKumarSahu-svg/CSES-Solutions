# Apartments (ID: 1084)

**Problem Link:** [https://cses.fi/problemset/task/1084/](https://cses.fi/problemset/task/1084/)

## Problem Description

There are n applicants and m free apartments. Your task is to distribute the apartments so that as many applicants as possible will get an apartment.

## Solution

```cpp
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define vi vector<int>
#define print(x) cout << (x) << endl;
#define all(x) (x).begin(), (x).end()
#define input(v, n)                                                            \
for (int i = 0; i < n; i++)                                                  \
cin >> v[i]
#define read3(a, b, c)                                                         \
int a, b, c;                                                                 \
cin >> a >> b >> c;
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    read3(n, m, k);
    vi a(n), b(m);
    input(a, n);
    input(b, n);
    sort(all(a));
    sort(all(b));
    int i = 0, j = 0, cnt = 0;
    while (i < n && j < m) {
        if (a[i] > b[j] + k)
        j++;
        else if (a[i] < b[j] - k)
        i++;
        else {
            cnt++;
            i++;
            j++;
        }
    }
    print(cnt);
    return 0;
}
```
