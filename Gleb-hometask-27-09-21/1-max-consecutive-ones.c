int findMaxConsecutiveOnes(int* nums, int numsSize) {
    int num_ser = 0; // number of 1 in current series
    int max_con = 0; // max reached value of num_ser
    
    for (int i = 0; i < numsSize; ++i) {
        if (nums[i] == 1) {
            num_ser++;
            if (num_ser > max_con) {
                max_con = num_ser;
            }
        } else {
            num_ser = 0;
        }
    }
    
    return max_con;
}

