# Weird Algorithm (ID: 1068)

**Problem Link:** [https://cses.fi/problemset/task/1068/](https://cses.fi/problemset/task/1068/)

## Problem Description

Consider an algorithm that takes as input a positive integer n. If n is even, the algorithm divides it by two, and if n is odd, the algorithm multiplies it by three and adds one. The algorithm repeats this, until n is one. For example, the sequence for n=3 is as follows:
 3 \rightarrow 10 \rightarrow 5 \rightarrow 16 \rightarrow 8 \rightarrow 4 \rightarrow 2 \rightarrow 1
Your task is to simulate the execution of the algorithm for a given value of n.

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
    int n;
    cin >> n;
    vector<int> arr;
    arr.push_back(n);
    while (n != 1)
    {
        if (n & 1)
        {
            // odd
            n = n * 3 + 1;
        }
        else
        {
            // even
            n = n / 2;
        }
        arr.push_back(n);
    }
    for (int i : arr)
    cout << i << " ";
    cout << endl;
}

signed main()
{
    fastIO();
    solve();
    return 0;
}
```
