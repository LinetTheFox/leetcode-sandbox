/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortArrayByParity(int* nums, int numsSize, int* returnSize) {
    int* result = malloc(sizeof(int) * numsSize);
    *returnSize = numsSize;
    for (int i = 0, b = 0, e = numsSize - 1; i < numsSize; i++) {
        if (nums[i] % 2 == 0) {
            result[b++] = nums[i];
        } else {
            result[e--] = nums[i];
        }
    }
    return result;
}

