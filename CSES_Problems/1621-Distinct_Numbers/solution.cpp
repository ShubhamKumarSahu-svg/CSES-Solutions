// CSES Problem 1621: Distinct Numbers
// Link: https://cses.fi/problemset/task/1621/
// Description: You are given a list of n integers, and your task is to calculate the number of ...

#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    set<int> s;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        s.insert(x);
    }

    cout << s.size();
}
