bool validMountainArray(int* arr, int arrSize) {
    int inc = 0, dec = 0;
    bool increasing = true;
    for (int i = 0; i < arrSize - 1; ++i) {
        if (arr[i] < arr[i + 1]) {
            if (!increasing) return false;
            inc++;
        }
        if (arr[i] > arr[i + 1]) {
            increasing = false;
            dec++;
        }
    }
    // if last condition doesn't check, we had equals
    return inc > 0 && dec > 0 && (inc + dec == arrSize - 1);
}

