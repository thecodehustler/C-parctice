#include <malloc.h>
#include <stdio.h>

// 基于递归的斐波那契数列计算实现。
int fibonacciR(int N) {
    if (N == 1 || N == 2) {
        return 1;
    }
    return fibonacciR(N - 1) + fibonacciR(N - 2);
}

// 基于 Dynamic Programming 实现的斐波那契数列计算实现
int fibonacciDP(int N) {
    int* dp = calloc(N + 1, sizeof(int));
    dp[0] = dp[1] = 1;
    for (int i = 2; i < N; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[N - 1];
}

int main() {
    printf("%d %d\n", fibonacciR(6), fibonacciDP(6));
    return 0;
}