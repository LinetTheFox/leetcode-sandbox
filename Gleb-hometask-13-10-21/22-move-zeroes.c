void moveZeroes(int* nums, int numsSize) {
    int nzep = 0; // non-zero elements pos, yes, I'm an asshole with such namings :3
    for (int i = 0; i < numsSize; ++i) {
        if (nums[i] != 0) {
            nums[nzep] = nums[i];
            nzep++;
        }
    }
    for (int i = nzep; i < numsSize; i++) {
        nums[i] = 0;
    }
}
