#include "public/std_c.h"

int max(int i, int j) {
  return i > j?i :j;
}

int longestCommonSubsequence(char * text1, char * text2){
  const int len1 = strlen(text1), len2 = strlen(text2);
  printf("%d, %d\n", len1, len2);
  int dp[len1+1][len2+1];
  for (int i = 0; i <= len1; i++) {
    for (int j = 0; j <= len2; j++) {
      dp[i][j] = 0;
    }
  }

  for (int i = 1; i <= len1; i++) {
    for (int j = 1; j <= len2; j++) {
      if (text1[i-1] == text2[j-1]) {
        dp[i][j] = dp[i-1][j-1] + 1;
      } else {
        dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
      }
    }
  }
  return dp[len1][len2];
}

int main() {
  char* str1 = "ezupkr", *str2 = "ubmrapg";
  printf("%d\n", longestCommonSubsequence(str1, str2));
  return 0;
}