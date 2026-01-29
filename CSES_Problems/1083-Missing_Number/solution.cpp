// CSES Problem 1083: Missing Number
// Link: https://cses.fi/problemset/task/1083/
// Description: You are given all numbers between 1,2,\ldots,n except one. Your task is to find ...

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
    int sum = 0;
    for (int i = 0; i < n - 1; i++)
    {
        int a;
        cin >> a;
        sum += a;
    }

    int total_sum = n * (n + 1) / 2;

    cout << total_sum - sum << endl;
}

signed main()
{
    fastIO();
    solve();
    return 0;
}
