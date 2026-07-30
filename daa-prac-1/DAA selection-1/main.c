#include <stdio.h>
#include <time.h> // Required for clock(), clock_t, and CLOCKS_PER_SEC

// Function to perform selection sort
void selectionSort(int arr[], int n) {
    int i, j, min_idx, temp;
    
    // One by one move boundary of unsorted subarray
    for (i = 0; i < n - 1; i++) {
        // Find the minimum element in unsorted array
        min_idx = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        
        // Swap the found minimum element with the first element
        if (min_idx != i) {
            temp = arr[min_idx];
            arr[min_idx] = arr[i];
            arr[i] = temp;
        }
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
    
    // 4. Run the sorting algorithm
    selectionSort(arr, n);
    
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
    printf("Best Case Time Complexity    : O(n^2)    \n");
    printf("Average Case Time Complexity : O(n^2)    \n");
    printf("Worst Case Time Complexity   : O(n^2)    \n");
    printf("Auxiliary Space Complexity   : O(1)      \n");
    printf("=========================================\n");

    return 0;
}
