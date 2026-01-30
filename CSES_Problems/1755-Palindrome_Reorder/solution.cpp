// CSES Problem 1755: Palindrome Reorder
// Link: https://cses.fi/problemset/task/1755/
// Description: Given a string, your task is to reorder its letters in such a way that it become...

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

#define printno cout << "NO SOLUTION" << endl;
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

void solve()
{
    string s;
    cin >> s;
    unordered_map<char, int> mpp;
    int n = s.length();
    for (auto ch : s)
    mpp[ch]++;

    char mid = '#';
    int start = 0;
    int end = n - 1;
    for (auto it : mpp)
    {
        auto ch = it.first;
        auto itr = it.second;

        if (itr & 1)
        {
            if (n % 2 == 0)
            {
                printno;
                return;
            }
            else
            {
                if (mid != '#')
                {
                    printno;
                    return;
                }
                else
                {
                    mid = ch;
                    itr--;
                }
            }
        }

        while (itr)
        {
            s[start++] = ch;
            s[end--] = ch;
            itr--;
            itr--;
        }
    }
    if (mid != '#')
    s[end] = mid;

    print(s);
}

signed main()
{
    fastIO();
    solve();
    return 0;
}
