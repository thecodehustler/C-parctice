#include "public/qsort.h"

int numRabbits(int* answers, int answersSize) {
    qsort(answers, answersSize);
    int ret = 0;
    for (int i = 0; i < answersSize; i++) {
        ret += (answers[i] + 1);
        int k = answers[i];
        while (k-- > 0 && i < (answersSize - 1) && answers[i] == answers[i + 1])
            i++;
    }
    return ret;
}