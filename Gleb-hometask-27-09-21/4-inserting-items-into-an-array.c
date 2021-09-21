// I was stupid on this one, apparently we don't change the size
// of the array and simply discard the last elements
// And here I was learning about realloc() :D
void duplicateZeros(int* arr, int arrSize) {    
    for (int i = 0; i < arrSize; i++) {
        if (arr[i] == 0) {
            for (int j = arrSize - 1; j > i; --j) {
                arr[j] = arr[j - 1];
            }
            arr[i] = 0;
            // To skip 0 we inserted
            i++;
        }
    }
}

