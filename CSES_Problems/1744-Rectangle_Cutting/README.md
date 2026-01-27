# Rectangle Cutting (ID: 1744)

**Problem Link:** [https://cses.fi/problemset/task/1744/](https://cses.fi/problemset/task/1744/)

## Problem Description

Given an a \times b rectangle, your task is to cut it into squares. On each move you can select a rectangle and cut it into two rectangles in such a way that all side lengths remain integers. What is the minimum possible number of moves?

## Solution

```cpp
#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> dp;
int f(int a, int b)
{
    if (a == b)
    return 0;

    if (dp[a][b] != -1)
    return dp[a][b];

    int mini = INT_MAX;
    for (int i = 1; i <= b / 2; i++)
    mini = min(mini, 1 + f(a, i) + f(a, b - i));

    for (int i = 1; i <= a / 2; i++)
    mini = min(mini, 1 + f(i, b) + f(a - i, b));

    return dp[a][b] = mini;
}

int main()
{
    int a, b;
    cin >> a >> b;
    dp.resize(a + 1, vector<int>(b + 1, -1));
    cout << f(a, b) << endl;
}
```
