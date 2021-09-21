int removeDuplicates(int* nums, int numsSize) {
    if (numsSize == 0) return 0;
    int next_pos = 1;
    for (int i = 1; i < numsSize; ++i) {
        if (nums[i] != nums[next_pos - 1]) {
            nums[next_pos] = nums[i];
            next_pos++;
        }
    }
    return next_pos;
}

