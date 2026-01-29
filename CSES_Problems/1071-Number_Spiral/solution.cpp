// CSES Problem 1071: Number Spiral
// Link: https://cses.fi/problemset/task/1071/
// Description: A number spiral is an infinite grid whose upper-left square has number 1. Here a...

#include <bits/stdc++.h>
using namespace std;
#define int long long

void fastIO() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
}

signed main() {
    fastIO();

    int t;
    cin >> t;
    while (t--) {
        int y, x;
        cin >> y >> x;

        int k = max(x, y);
        int ans;

        if (k & 1) { // odd
        if (x == k)
        ans = k*k - (y - 1);
        else
        ans = (k-1)*(k-1) + x;
    } else {     // even
    if (y == k)
    ans = k*k - (x - 1);
    else
    ans = (k-1)*(k-1) + y;
}

cout << ans << "\n";
}
return 0;
}
