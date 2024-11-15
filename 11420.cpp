#include <iostream>
#include <cstdio>
#include <cstring>

#define ll long long
using namespace std;
#define LOCKED 0
#define UNLOCKED 1

ll dp[70][70][2];

ll solve(int pos, int cntSecure, int prev) {
    if (pos < 0 || cntSecure < 0) return 0;
    if (pos == 0 && cntSecure == 0) return 1;
    if (pos == 0) return 0;

    ll &ret = dp[pos][cntSecure][prev];
    if (ret != -1) return ret;

    if (prev == LOCKED) {
        ret = solve(pos - 1, cntSecure - 1, LOCKED) + 
        solve(pos - 1, cntSecure, UNLOCKED);
    } else { 
        ret = solve(pos - 1, cntSecure, LOCKED) + 
        solve(pos - 1, cntSecure, UNLOCKED);
    }

    return ret;
}

int main() {
    int n, s;

    memset(dp, -1, sizeof(dp));

    while (scanf("%d %d", &n, &s) == 2) {
        if (n < 0 || s < 0) break;

        ll result = solve(n, s, LOCKED);

        printf("%lld\n", result);
    }

    return 0;
} 