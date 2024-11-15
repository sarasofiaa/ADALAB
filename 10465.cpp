#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int main() {
    int m, n, t;
    while (cin >> m >> n >> t) {
        int dp[10001];  
        memset(dp, -1, sizeof(dp));
        dp[0] = 0; 

        for (int i = 1; i <= t; ++i) {
            if (i >= m && dp[i - m] != -1) {
                dp[i] = max(dp[i], dp[i - m] + 1);
            }
            if (i >= n && dp[i - n] != -1) {
                dp[i] = max(dp[i], dp[i - n] + 1);
            }
        }

        if (dp[t] != -1) {
            cout << dp[t] << endl; 
	} else {
            int max_burgers = 0, remaining_time = t;
            for (int i = t; i >= 0; --i) {
                if (dp[i] != -1) {
                    max_burgers = dp[i];
                    remaining_time = t - i;
                    break;
                }
            }
            cout << max_burgers << " " << remaining_time << endl;
        }
    }
    return 0;
}