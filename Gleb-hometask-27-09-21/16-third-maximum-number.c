int thirdMax(int* nums, int numsSize){
    int first, second, third, top_three_size = 0;    
    
    for (int i = 0; i < numsSize; ++i) {
        
        // If we have full top 3 and nums[i] is less than
        // third - don't bother
        if (top_three_size == 3 && nums[i] < third) continue;
        
        if (top_three_size == 0) {
            first = nums[i];
            ++top_three_size;
        } else if (top_three_size == 1) {
            // Existing number check
            if (first == nums[i]) continue;
            if (first < nums[i]) {
                second = first;
                first = nums[i];
            } else {
                second = nums[i];
            }
            ++top_three_size;
        } else if (top_three_size == 2) {
            // Existing number check
            if (first == nums[i] || second == nums[i]) continue;
            if (first < nums[i]) {
                third = second;
                second = first;
                first = nums[i];
            } else if (second < nums[i]) {
                third = second;
                second = nums[i];
            } else {
                third = nums[i];
            }
            ++top_three_size;
        } else {
            // Existing number check
            if (top_three_size == 3 && (first == nums[i] || second == nums[i] || third == nums[i])) {
                continue;
            }
            if (first < nums[i]) {
                third = second;
                second = first;
                first = nums[i];
            } else if (second < nums[i]) {
                third = second;
                second = nums[i];
            } else {
                third = nums[i];
            }
        }
    }
    if (top_three_size < 3) {
        return first;
    } else {
        return third;
    }
}
