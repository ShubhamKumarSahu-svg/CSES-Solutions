// CSES Problem 1070: Permutations
// Link: https://cses.fi/problemset/task/1070/
// Description: A permutation of integers 1,2,\ldots,n is called beautiful if there are no adjac...

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
    if (n == 1)
    {
        cout << 1 << endl;
        return;
    }
    else if (n < 4)
    {
        cout << "NO SOLUTION" << endl;
        return;
    }
    vector<int> res;
    for (int i = 2; i <= n; i = i + 2)
    {
        res.push_back(i);
    }
    for (int i = 1; i <= n; i = i + 2)
    {
        res.push_back(i);
    }
    for (int i = 0; i < n; i++)
    {
        cout << res[i] << " ";
    }
    cout << endl;
}

signed main()
{
    fastIO();
    solve();
    return 0;
}
