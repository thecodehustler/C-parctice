#include <stdint.h>
#include <stdio.h>

uint32_t reverseBits(uint32_t n) {
    uint32_t mask1 = 0x55555555, mask2 = 0x33333333, mask3 = 0x0f0f0f0f,
             mask4 = 0x00ff00ff, mask5 = 0x0000ffff;
    n = ((n & mask1) << 1) | ((n & (mask1 << 1)) >> 1);
    n = ((n & mask2) << 2) | ((n & (mask2 << 2)) >> 2);
    n = ((n & mask3) << 4) | ((n & (mask3 << 4)) >> 4);
    n = ((n & mask4) << 8) | ((n & (mask4 << 8)) >> 8);
    n = ((n & mask5) << 16) | ((n & (mask5 << 16)) >> 16);
    return n;
}

int main() {
    printf("%ld", reverseBits(43261596));
    return 0;
}