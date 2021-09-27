// O(2n), there probably is something better, isn't there? :^)
int* sortedSquares(int* nums, int numsSize, int* returnSize) {
    // numsSize >= 1, so no worries about it
    int *squares = malloc(sizeof(int) * numsSize);
    *returnSize = numsSize;

    int lowestIndex = -1;
    // Getting the index of lowest last (in case of multiple) square in the
    // array, while also making squares in the given one
    if (numsSize == 1) {
        lowestIndex = 0;
    }
    for (int i = 0; i < numsSize; ++i) {
        nums[i] = nums[i] * nums[i];
        if (i > 0 && lowestIndex == -1 && nums[i - 1] < nums[i]) {
           lowestIndex = i - 1;
        }
    }
    // In case the array is descending by square, then setting to the last index
    if (lowestIndex == -1) {
        lowestIndex = numsSize - 1;    
    }
    
    squares[0] = nums[lowestIndex];

    // Filling up the spaces, by starting at the lowest index we got above
    // and going left or right depening on which one is lesser
    // j goes to the left, k - to the right
    for (int i = 1, j = lowestIndex - 1, k = lowestIndex + 1; i < numsSize; ++i) {
        // equality doesn't matter, we could've set the equality for the case
        // of k
        if (j >= 0) {
            if (k >= numsSize) {
                squares[i] = nums[j];
                --j;
            } else if (nums[j] <= nums[k]) {
                squares[i] = nums[j];
                --j;
            } else {
                squares[i] = nums[k];
                ++k;
            }
        } else if (k < numsSize) {
            if (j < 0) {
                squares[i] = nums[k];
                ++k;
            } else if (nums[j] > nums[k]) {
                squares[i] = nums[k];
                ++k;
            } else {
                squares[i] = nums[j];
                --j;
            }

        }
    }


    return squares;
}
