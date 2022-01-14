#include <stdio.h>

#include "./public/hstring.h"

int main() {
    HString hs;
    HS_Init(&hs);
    HS_Append(&hs, "NaRu ");
    HS_Append(&hs, "is king. ");
    HS_Append(&hs,
              "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor "
              "incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud "
              "exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute "
              "irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla "
              "pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia "
              "deserunt mollit anim id est laborum.");
    HS_Append(&hs, "Inf0.");
    printf("%s\n", toString(&hs));
    printf("%d, %d", hs.len, strlen(hs.buf));
    return 0;
}