int removeDuplicates(int* nums, int numsSize) {
    int nextPos = 1;
    for (int i = 0; i < numsSize; ++i) {
        if (nums[i] != nums[nextPos - 1]) {
            nums[nextPos++] = nums[i];
        }
    }
    return numsSize ? nextPos : 0;
}
