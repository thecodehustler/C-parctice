#include "public/std_c.h"

int findMin(int* nums, int numsSize) {
    int left = 0, right = numsSize - 1;
    while (right - left > 1) {
        while (right > left && nums[right] == nums[right - 1]) {
            right--;
        }
        while (left < right && nums[left] == nums[left + 1]) {
            left++;
        }
        int mid = left + (right - left) / 2;
        if (left == mid || nums[left] < nums[mid]) {      // 左侧是单调递增的？
            if (right == mid || nums[mid] < nums[right])  // 右侧也是单调递增的……
                return nums[left];
            else
                left = mid;
        } else {
            right = mid;
        }
    }
    return nums[left] > nums[right] ? nums[right] : nums[left];
}

int main() {
    int arr[] = {3, 10, 11, 9, 5, 3, 11, 8, 4, 9, 2, 18, 7, 5, 6};
    printf("%d\n", findMin(arr, sizeof(arr) / sizeof(int)));
}