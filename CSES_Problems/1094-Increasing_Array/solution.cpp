// CSES Problem 1094: Increasing Array
// Link: https://cses.fi/problemset/task/1094/
// Description: You are given an array of n integers. You want to modify the array so that it is...

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
    vector<int> arr(n);
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        if (i > 0)
        {
            int diff = arr[i - 1] - arr[i];
            if (diff > 0)
            {
                res += diff;
                arr[i] += diff;
            }
        }
    }
    cout << res << endl;
}

signed main()
{
    fastIO();
    solve();
    return 0;
}
