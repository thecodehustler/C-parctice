#include <malloc.h>
#include <string.h>

#ifndef nullptr
#define nullptr (void*)0
#endif
/**
 * A simple string builder.
 */

#define BLOCK_SIZE 15

typedef struct {
    char* buf;
    int bufSize;
    int len;
} HString;

/**
 * Init a HString
 */
void HS_Init(HString* hs) {
    hs->buf = (char*)malloc(BLOCK_SIZE);
    hs->bufSize = BLOCK_SIZE;
    hs->len = 0;
}

void _expandBy(HString* hs, int blockCount) {
    hs->buf = (char*)realloc(hs->buf, hs->bufSize + blockCount * BLOCK_SIZE);
    hs->bufSize += blockCount * BLOCK_SIZE;
}

void HS_Append(HString* hs, char* c) {
    int size = 0;
    char* str = c;
    while (*str) {
        str += 1;
        size++;
    }
    int avail = hs->bufSize - hs->len;
    if (avail < size + 1) {
        int n = (size - avail + 1) / BLOCK_SIZE + 1;
        _expandBy(hs, n);
    }
    strncpy(hs->buf + hs->len, c, size);
    hs->len += size;
    hs->buf[hs->len] = 0;
}

char* toString(HString* hs) { return hs->buf; }

void HS_Free(HString* hs) {
    free(hs->buf);
    hs->buf = nullptr;
    hs->bufSize = 0;
    hs->len = 0;
}