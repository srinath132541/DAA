#include <stdio.h>
#include <time.h> // Required for clock(), clock_t, and CLOCKS_PER_SEC

// Function to swap two elements using pointers
void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

/* This function takes the last element as pivot, places the pivot element 
   at its correct position in the sorted array, and places all smaller 
   elements to the left of the pivot and all greater elements to the right */
int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // Choosing the last element as pivot
    int i = (low - 1);     // Index of smaller element

    for (int j = low; j <= high - 1; j++) {
        // If current element is smaller than or equal to pivot
        if (arr[j] <= pivot) {
            i++; // Increment index of smaller element
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

// The main function that implements QuickSort
// low  --> Starting index,  high  --> Ending index
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        // pi is partitioning index, arr[p] is now at right place
        int pi = partition(arr, low, high);

        // Separately sort elements before partition and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
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
    quickSort(arr, 0, n - 1);
    
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
    printf("Best Case Time Complexity    : O(n log n) -> (When pivot consistently splits array in half)\n");
    printf("Average Case Time Complexity : O(n log n) -> (With random/jumbled data layout)\n");
    printf("Worst Case Time Complexity   : O(n^2)     -> (When array is already sorted or reverse sorted)\n");
    printf("Auxiliary Space Complexity   : O(log n)   -> (Due to recursive call stack space)\n");
    printf("=========================================\n");

    return 0;
}
