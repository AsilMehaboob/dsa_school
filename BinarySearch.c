#include <stdio.h>

// Function to perform binary search
int binarySearch(int arr[], int size, int target) {
    int left = 0, right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;  // Avoids overflow

        // Check if the target is present at mid
        if (arr[mid] == target)
            return mid;

        // If target is greater, ignore the left half
        if (arr[mid] < target)
            left = mid + 1;
        // If target is smaller, ignore the right half
        else
            right = mid - 1;
    }

    // Target not present in the array
    return -1;
}

int main() {
    int arr[] = {2, 3, 4, 10, 40};  // Sorted array
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 10;
    
    // Perform binary search
    int result = binarySearch(arr, size, target);

    if (result != -1)
        printf("Element %d found at index %d\n", target, result);
    else
        printf("Element %d not found in the array\n", target);

    return 0;
}