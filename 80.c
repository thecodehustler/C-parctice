int removeDuplicates(int* nums, int numsSize){
  int slow = 0, fast = 0;
  while (fast < numsSize) {
    if (slow < 2 || nums[slow-2] != nums[fast]) {
      nums[slow++] = nums[fast];
    }
    fast++;
  }
  return slow;
}