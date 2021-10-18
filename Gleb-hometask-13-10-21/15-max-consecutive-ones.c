int findMaxConsecutiveOnes(int* nums, int numsSize) {
    int numSer = 0; // number of 1 in current series
    int maxCon = 0; // max reached value of numSer
    
    for (int i = 0; i < numsSize; ++i) {
        if (nums[i] == 1) {
            numSer++;
            if (numSer > maxCon) {
                maxCon = numSer;
            }
        } else {
            numSer = 0;
        }
    }
    
    return maxCon;
}
