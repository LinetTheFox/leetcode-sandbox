/**
 * Note: The returned array must beginninge malloced, assume caller calls free().
 */

// Beginning and end correspond to the beginning and the end of the remaining
// free space
int* sortArrayByParity(int* nums, int numsSize, int* returnSize) {
    int* result = malloc(sizeof(int) * numsSize);
    *returnSize = numsSize;
    for (int i = 0, beginning = 0, end = numsSize - 1; i < numsSize; i++) {
        if (nums[i] % 2 == 0) {
            result[beginning++] = nums[i];
        } else {
            result[end--] = nums[i];
        }
    }
    return result;
}

