// CSES Problem 1754: Coin Piles
// Link: https://cses.fi/problemset/task/1754/
// Description: You have two coin piles containing a and b coins. On each move, you can either r...

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define vi vector<int>
#define vvi vector<vector<int>>
#define pii pair<int, int>
#define sayno cout << "NO" << endl;
#define sayyes cout << "YES" << endl;
#define vpii vector<pair<int, int>>
#define mii map<int, int>
#define umii unordered_map<int, int>
#define si set<int>
#define msi multiset<int>
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define read(v, n)            \
for (int i = 0; i < n; i++) \
cin >> v[i]
#define read1(v, n)            \
for (int i = 1; i <= n; i++) \
cin >> v[i]

const int mod = 1e9 + 7;
const int inf = INT_MAX;
const int m_inf = INT_MIN;

void fastIO()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
}

void solve()
{
    int q;
    cin >> q;

    while (q--)
    {
        int a, b;
        cin >> a >> b;
        if (a == 0 && b == 0)
        {
            cout << "YES" << endl;
        }
        else if (a == 0 || b == 0)
        {
            cout << "NO" << endl;
        }
        else
        {
            if ((a + b) % 3 != 0 || a > 2 * b || b > 2 * a)
            {
                sayno;
            }
            else
            {
                sayyes;
            }
        }
    }
}

signed main()
{
    fastIO();
    solve();
    return 0;
}
