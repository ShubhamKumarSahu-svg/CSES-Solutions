// CSES Problem 1091: Concert Tickets
// Link: https://cses.fi/problemset/task/1091/
// Description: There are n concert tickets available, each with a certain price. Then, m custom...

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define vi vector<int>
#define pii pair<int, int>
#define vpii vector<pair<int, int>>

void fastIO() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
}

void solve() {
    int n, m;
    cin >> n >> m;

    multiset<int> stt;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        stt.insert(a);
    }

    vi customers(m);
    for (int i = 0; i < m; i++) {
        cin >> customers[i];
    }

    vi ans;

    for (auto c : customers) {
        auto it = stt.upper_bound(c);
        if (it != stt.begin()) {
            int num = *--it;
            ans.push_back(num);
            stt.erase(stt.find(num));
        } else {
            ans.push_back(-1);
        }
    }

    for (int x : ans)
    cout << x << "\n";
}

signed main() {
    fastIO();
    solve();
    return 0;
}
