// Worked as well? TODO: may be a better solution since it's sorted tho
int removeDuplicates(int* nums, int numsSize) {
    for (int i = 0; i < numsSize - 1;) {
        if (nums[i] == nums[i + 1]) {
            for (int j = i + 1; j < numsSize - 1; j++) {
                nums[j] = nums[j + 1];
            }
            numsSize--;
        } else {
            i++;
        }
    }
    return numsSize;
}

