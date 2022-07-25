#include <cstdio>
#include <algorithm>

using namespace std;

#define MAX_N 350

int n;
int a[MAX_N][MAX_N];
int dp[MAX_N+1][MAX_N+1];

int solve(int n) {
    int res = 0;
    dp[0][0] = a[0][0];
    for (int i = 0; i < n; i++) {
        dp[i+1][0] = dp[i][0]+a[i+1][0];
        res = max(res, dp[i+1][0]);
        for (int j = 1; j <= i+1; j++) {
            dp[i+1][j] = max(dp[i][j-1], dp[i][j]) + a[i+1][j];
            res = max(res, dp[i+1][j]);
        }
    }
    return res;
}

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j <= i; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    printf("%d\n", solve(n));
    return 0;
}
