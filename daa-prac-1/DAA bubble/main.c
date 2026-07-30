#include <stdio.h>
#include <time.h> // Required for clock(), clock_t, and CLOCKS_PER_SEC

// Function to perform bubble sort
void bubbleSort(int arr[], int n) {
    int i, j, temp;
    int swapped; 
    
    for (i = 0; i < n - 1; i++) {
        swapped = 0; 
        
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap elements
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                
                swapped = 1; 
            }
        }
        
        // Break early if array becomes sorted
        if (swapped == 0) {
            break;
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
    bubbleSort(arr, n);
    
    // 5. Stop the clock tracker
    clock_t end_time = clock();
    
    // 6. Calculate total execution time in seconds
    double time_taken = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
    
    printf("\nSorted array: \n");
    printArray(arr, n);
    
    // 7. Output measured execution time and theoretical complexity limits
    printf("\n=========================================\n");
    printf("       PERFORMANCE & TIME COMPLEXITY     \n");
    printf("=========================================\n");
    printf("Actual Execution Time        : %f seconds\n", time_taken);
    printf("-----------------------------------------\n");
    printf("Best Case Time Complexity    : O(n)      \n");
    printf("Average Case Time Complexity : O(n^2)    \n");
    printf("Worst Case Time Complexity   : O(n^2)    \n");
    printf("Auxiliary Space Complexity   : O(1)      \n");
    printf("=========================================\n");

    return 0;
}
