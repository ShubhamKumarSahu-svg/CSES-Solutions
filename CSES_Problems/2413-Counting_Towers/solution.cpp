// CSES Problem 2413: Counting Towers
// Link: https://cses.fi/problemset/task/2413/
// Description: Your task is to build a tower whose width is 2 and height is n. You have an unli...

#include <bits/stdc++.h>

#define MOD 1000000007

using namespace std;

vector<vector<int>> dp(1e6 + 1, vector<int>(2));
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        dp[n][0] = 1;
        dp[n][1] = 1;
        for (int i = n - 1; i >= 0; i--)
        {
            dp[i][0] = (2LL * dp[i + 1][0] + dp[i + 1][1]) % MOD;
            dp[i][1] = (4LL * dp[i + 1][1] + dp[i + 1][0]) % MOD;
        }

        cout << (dp[1][0] + dp[1][1]) % MOD << endl;
    }
}
