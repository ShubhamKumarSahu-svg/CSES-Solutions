# Distinct Numbers (ID: 1621)

**Problem Link:** [https://cses.fi/problemset/task/1621/](https://cses.fi/problemset/task/1621/)

## Problem Description

You are given a list of n integers, and your task is to calculate the number of distinct values in the list.

## Solution

```cpp
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    set<int> s;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        s.insert(x);
    }

    cout << s.size();
}
```
