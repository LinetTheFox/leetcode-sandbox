/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

// The current subarray, not fully filled at all times, there will always
// be an epmty space to the right where we shift its part to insert
// the num into the middle
void insert_into_array(int *nums, int numsSize, int num) {
    
    // Checking if the number is the largest one - there's no point
    // in the loop then
    if (num > nums[numsSize - 1]) {
        nums[numsSize] = num;
        return;
    }

    // Checking which place to insert into (if there's an equal one - inserting before it)
    // and shifting the right side to the right by one element and inserting
    // num into the "opened" place
    for (int i = 0; i < numsSize; ++i) {
        if (nums[i] >= num) {
            for (int j = numsSize; j > i; --j) {
                nums[j] = nums[j - 1];
            }
            nums[i] = num;
            return;
        }
    }
}

int* sortedSquares(int* nums, int numsSize, int* returnSize) {
    int *squares = malloc(sizeof(int) * numsSize);

    int sq;
    
    // Dunno why we are doing this if the size will be the same anyway
    // Passing size is a good idea in and of itself, but in this case it's useless
    *returnSize = numsSize;
    
    for (int i = 0; i < numsSize; ++i) {
        sq = nums[i] * nums[i];
        // On an empty array - just inserting
        if (i == 0) {
            squares[0] = sq;
        } else {
            insert_into_array(squares, i, sq);   
        }
    }
    
}

