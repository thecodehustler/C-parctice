#include "stdio.h"
#include <unordered_map>
#include <vector>

using namespace std;

vector<int> retTest() {
    return {1,2};
}

int main() {
    unordered_map<int, int> mNum;
    int a[] = {1,2,3,3,3,4,5,6};
    for (int& x: a) {
        mNum[x]++; // 为什么这样都可以？
    }

    // vector<vector<bool>> map;

    // bool** map = new[1][2] bool;
    // // map[2][3] = true;
    // printf("Vector[%d][%d]", map.size(), map[0].size());

    // for (unordered_map<int, int>::iterator it = mNum.begin(); it != mNum.end(); it++) {
    //     printf("%d: %d\n", it->first, it->second);
    // }
    return 0;
}

