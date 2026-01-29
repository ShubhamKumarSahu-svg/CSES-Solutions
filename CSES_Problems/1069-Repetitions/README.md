# Repetitions (ID: 1069)

**Problem Link:** [https://cses.fi/problemset/task/1069/](https://cses.fi/problemset/task/1069/)

## Problem Description

You are given a DNA sequence: a string consisting of characters A, C, G, and T. Your task is to find the longest repetition in the sequence. This is a maximum-length substring containing only one type of character.

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
    string s;
    cin >> s;
    int cnt = 1;
    int res = 1;
    for (int i = 1; i < s.length(); i++)
    {
        if (s[i] == s[i - 1])
        {
            cnt++;
        }
        else
        {
            res = max(cnt, res);
            cnt = 1;
        }
    }
    res = max(cnt, res);
    cout << res << endl;
}

signed main()
{
    fastIO();
    solve();
    return 0;
}
```
