#include <stdio.h>
#include <time.h> // Required for clock(), clock_t, and CLOCKS_PER_SEC

// Merges two subarrays of arr[].
// First subarray is arr[l..m]
// Second subarray is arr[m+1..r]
void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    // Create temporary arrays (Variable Length Arrays)
    int L[n1], R[n2];

    // Copy data to temp arrays L[] and R[]
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    // Merge the temp arrays back into arr[l..r]
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[], if there are any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[], if there are any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// l is for left index and r is right index of the sub-array of arr to be sorted
void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        // Same as (l+r)/2, but avoids overflow for large l and h
        int m = l + (r - l) / 2;

        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

// Function to print the array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n, i;

    // 1. Get array size from user
    printf("Enter the number of elements: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid array size.\n");
        return 1;
    }

    int arr[n]; 

    // 2. Get array elements from user
    printf("Enter %d integers:\n", n);
    for (i = 0; i < n; i++) {
        printf("Element [%d]: ", i);
        scanf("%d", &arr[i]);
    }
    
    printf("\nOriginal array: \n");
    printArray(arr, n);
    
    // 3. Start the clock tracker
    clock_t start_time = clock();
    
    // 4. Run the sorting algorithm (low index = 0, high index = n - 1)
    mergeSort(arr, 0, n - 1);
    
    // 5. Stop the clock tracker
    clock_t end_time = clock();
    
    // 6. Calculate total execution time in seconds
    double time_taken = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
    
    printf("\nSorted array: \n");
    printArray(arr, n);
    
    // 7. Output measured execution time and theoretical complexity limits
    printf("\n=========================================\n");
    printf("      PERFORMANCE & TIME COMPLEXITY      \n");
    printf("=========================================\n");
    printf("Actual Execution Time        : %f seconds\n", time_taken);
    printf("-----------------------------------------\n");
    printf("Best Case Time Complexity    : O(n log n) -> (Divides and merges predictably)\n");
    printf("Average Case Time Complexity : O(n log n) -> (Performance remains uniform)\n");
    printf("Worst Case Time Complexity   : O(n log n) -> (Guaranteed upper bound time)\n");
    printf("Auxiliary Space Complexity   : O(n)       -> (Requires temp arrays for merging)\n");
    printf("=========================================\n");

    return 0;
}
