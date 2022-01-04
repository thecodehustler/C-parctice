#include <malloc.h>
#include <stdio.h>
#include <string.h>

typedef long long LL;

int numDistinct(char* s, char* t) {
    const int len1 = strlen(s), len2 = strlen(t);

    LL** dp = calloc(len1 + 1, sizeof(LL*));
    for (int i = 0; i < len1 + 1; i++) {
        dp[i] = calloc(len2 + 1, sizeof(LL));
        memset(dp[i], 0, sizeof(LL) * (len2 + 1));
    }

    for (int i = 0; i < len1 + 1; i++) {
        for (int j = 0; j < len2 + 1; j++) {
            if (j == 0) {
                dp[i][j] = 1;
            } else if (i == 0) {
                dp[i][j] = 0;
            } else {
                if (s[i - 1] == t[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
    }
    int ret = dp[len1][len2];
    for (int i = 0; i < len1; i++) {
        free(dp[i]);
    }
    free(dp);
    return ret;
}

int main() { printf("%d\n", numDistinct("rabbbit", "rabbit")); }