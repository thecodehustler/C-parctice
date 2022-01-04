#include <stdio.h>

int qpow(int base, int pow) {
    int temp = base, result = 1;
    while (pow) {
        result *= (pow & 1) ? temp : 1;
        temp *= temp;
        pow >>= 1;
    }
    return result;
}

int main() { printf("%d\n", qpow(3, 13)); }