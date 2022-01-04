#include "public/std_c.h"

/**
 * 照题目那个旋转方法，将数组二分的话，一定会把数组分成一个单调递增，一个不单调递增的两个子序列。
 * 我们先判断哪一部分是单调递增的，然后看目标在不在单调递增的区间之中。不在的话就是在另一半咯.
 * 但是还是需要考虑头尾去重。因为[1,0,1,1,1]这种代表一种极端案例：
 */

bool search(int* nums, int numsSize, int target) {
    int start = 0, end = numsSize - 1, mid = 0;
    while (start <= end) {
        while (start < end && nums[start] == nums[start + 1]) {
            start++;
        }
        while (start < end && nums[end] == nums[end - 1]) {
            end--;
        }
        mid = start + (end - start) / 2;
        if (target == nums[mid]) {
            return true;
        } else if (nums[mid] <= nums[end]) {
            if (nums[mid] <= target && nums[end] >= target) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        } else {
            if (nums[start] <= target && nums[mid] >= target) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
    }
    return false;
}

int main() {
    int* arrays[] = {{4, 5, 6, 6, 7, 0, 1, 2, 4, 4}, {2, 1}, {2, 5, 6, 0, 0, 1, 2}};
    int sizes[] = {10, 2, 7};
    int targets[] = {1, 1, 6};
    for (int i = 0; i < 3; i++) {
        printf("%d\n", search(arrays[i], sizes[i], targets[i]));
    }
}