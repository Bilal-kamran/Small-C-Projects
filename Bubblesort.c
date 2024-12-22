#include <stdio.h>
#include <stdbool.h>

/*
 * This is the Bubble Sort algorithm function.
 * It takes two arguments:
 * 1. The first argument takes the address of the first element of the passed array.
 * 2. The second argument takes the size of the passed array.
 * The function sorts the array in-place using the Bubble Sort algorithm.
 */
void bubblesort(int *arr, int size) {
    bool swapped;
    int end = size - 1;

    do {
        swapped = false;
        // The loop runs through the array, comparing adjacent elements
        for (int i = 0; i < end; i++) {
            if (arr[i] > arr[i + 1]) {
                // Swap elements if they are in the wrong order
                int temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
                swapped = true;
            }
        }

        // Decrease 'end' as the last element is now sorted
        end--;

    } while (swapped);
}

int main() {
    int arr[8] = {2, 43, 5, 1, 6, 3, 12, 7};
    int n = sizeof(arr) / sizeof(arr[0]); // Calculate size of array

    printf("\nThe value of array before sorting is: \n");
    for (int i = 0; i < n; i++) {
        printf("%d\n", arr[i]);
    }

    printf("\nArray is passed to be sorted\n");
    bubblesort(arr, n); // Use 'n' for size

    printf("\nThe value of array after sorting is: \n");
    for (int i = 0; i < n; i++) {
        printf("%d\n", arr[i]);
    }

    return 0;
}

