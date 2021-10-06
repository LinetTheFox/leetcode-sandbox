int pivotIndex(int* nums, int numsSize){
    int rightSum = 0;
    int index = -1;
    
    for (int i = 0; i < numsSize; ++i) {
        rightSum += nums[i];
    }
    
    int leftSum = 0;
    // We count the sum strictly to the left of current index
    for (int i = 0; i < numsSize; ++i) {
        rightSum -= nums[i];
        // Edge case: leftSum is still 0, since it's on the edge of array
        // It may still count, as the sum of rest of the array can be 0
        // and it will be correct answer
        if (i != 0) leftSum += nums[i - 1];
        
        if (leftSum == rightSum) {
            return i;
        }
    }
    return -1;
}
