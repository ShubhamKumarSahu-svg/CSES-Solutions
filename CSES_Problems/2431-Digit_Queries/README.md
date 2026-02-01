# Digit Queries (ID: 2431)

**Problem Link:** [https://cses.fi/problemset/task/2431/](https://cses.fi/problemset/task/2431/)

## Problem Description

Consider an infinite string that consists of all positive integers in increasing order:

## Solution

```cpp
#include <bits/stdc++.h>
using namespace std;

#define nl '\n'
#define sp ' '
#define len(x) int((x).size())
#define int long long

void solve() {
    int q;
    cin >> q;

    while (q--) {
        int k;
        cin >> k;

        int dig_len = 1; // Current digit length
        int count = 9;   // Count of numbers with 'dig_len' digits
        int start = 1;   // Starting position for numbers with 'digit_len' digits

        // Find which digit-length group contains position k
        while (k > start + dig_len * count - 1) {
            start += dig_len * count; // Move to next group's starting position
            dig_len++;                // Increment digit length
            count *= 10;              // Next group has 10x more numbers
        }

        // Now we know k is in the group of 'dig_len'-digit numbers
        int first_num = pow(10, dig_len - 1); // First number with 'dig_len' digits
        int num_offset = (k - start) / dig_len;
        int target_num =
        first_num + num_offset; // The actual number containing position k

        // Find which digit within target_num
        string num_str = to_string(target_num);
        int digit_offset = k - start;
        int pos_in_num = digit_offset % dig_len;

        cout << num_str[pos_in_num] << "\n";
    }
} //* T:(q*log(k)) ~ O(1e3 x 18) ~ O(1e4), S: O(1)

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
}
```
