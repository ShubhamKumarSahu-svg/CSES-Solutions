// CSES Problem 1068: Weird Algorithm
// Link: https://cses.fi/problemset/task/1068/
// Description: Consider an algorithm that takes as input a positive integer n. If n is even, th...

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
