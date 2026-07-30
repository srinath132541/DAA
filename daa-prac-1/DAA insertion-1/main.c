#include <stdio.h>
#include <time.h> // Required for clock(), clock_t, and CLOCKS_PER_SEC

// Function to perform insertion sort
void insertionSort(int arr[], int n) {
    int i, key, j;
    
    // Loop from the second element up to the last element
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        /* Move elements of arr[0..i-1], that are greater than key, 
           to one position ahead of their current position */
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
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
    insertionSort(arr, n);
    
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
    printf("Best Case Time Complexity    : O(n)      -> (When array is already sorted)\n");
    printf("Average Case Time Complexity : O(n^2)    -> (When array has random elements)\n");
    printf("Worst Case Time Complexity   : O(n^2)    -> (When array is reverse sorted)\n");
    printf("Auxiliary Space Complexity   : O(1)      -> (In-place sorting algorithm)\n");
    printf("=========================================\n");

    return 0;
}
