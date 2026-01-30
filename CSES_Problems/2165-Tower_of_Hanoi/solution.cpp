// CSES Problem 2165: Tower of Hanoi
// Link: https://cses.fi/problemset/task/2165/
// Description: The Tower of Hanoi game consists of three stacks (left, middle and right) and n ...

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define vi vector<int>
#define vvi vector<vector<int>>
#define pii pair<int, int>
#define vpii vector<pair<int, int>>
#define mii map<int, int>
#define umii unordered_map<int, int>
#define si set<int>
#define msi multiset<int>

#define printno cout << "NO" << endl;
#define printyes cout << "YES" << endl;
#define print(x) cout << (x) << endl;
#define printsp(x) cout << (x) << " ";
#define printarr(v) \
for (auto &x : v) \
cout << x << " ";
#define printarrn(v)  \
for (auto &x : v)   \
cout << x << " "; \
cout << endl;

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define input(v, n)           \
for (int i = 0; i < n; i++) \
cin >> v[i]
#define input1(v, n)           \
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

void hanoi(int n, int from, int to, int aux)
{
    if (n == 0)
    return;
    hanoi(n - 1, from, aux, to);
    cout << from << " " << to << endl;
    hanoi(n - 1, aux, to, from);
}

void solve()
{
    int n;
    cin >> n;
    cout << pow(2, n) - 1 << endl;
    hanoi(n, 1, 3, 2);
}

signed main()
{
    fastIO();
    solve();
    return 0;
}
