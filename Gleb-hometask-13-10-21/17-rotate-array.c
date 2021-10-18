void reverse(int* nums, int from, int to) {
    for (; from != to && from < to; ++from, --to) {
        nums[from] = nums[to] + nums[from];
        nums[to] = nums[from] - nums[to];
        nums[from] = nums[from] - nums[to];
    }
}

void rotate(int* nums, int numsSize, int k) {
    int rotations = k % numsSize; // just in case :^)
    reverse(nums, 0, numsSize - 1);
    reverse(nums, 0, rotations - 1);
    reverse(nums, rotations, numsSize - 1);
}
