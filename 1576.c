#include <malloc.h>
#include <stdio.h>
#include <string.h>

char* modifyString(char* s) {
    const int LEN = strlen(s);
    // create a copy of s, with padding char '?' on both sides.
    // This is to avoid border judges.
    char* ret = (char*)malloc(LEN + 2);
    memset(ret, '?', LEN + 2);
    memcpy(ret + 1, s, LEN);

    for (int i = 1; i <= LEN; i++) {
        if (ret[i] != '?') continue;
        char ch = 'a';
        while (ch <= 'z' && (ch == ret[i - 1] || ch == ret[i + 1])) {
            ch++;
        }
        ret[i] = ch;
    }

    ret[LEN + 1] = 0;
    return ret + 1;
}

int main() {
    printf("Running.");
    char* ret = modifyString("");
    printf("%s", ret);
    return 0;
}