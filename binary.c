#include <stdio.h>
int binary_search(int arr[], int n, int target) {
    int low = 0;
    int high = n - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        int mid_val = arr[mid];
        if (mid_val == target) {
            return mid;
        } else if (mid_val < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}
int main() {
    int sorted_array[] = {2, 5, 8, 12, 16, 23, 38, 45, 56, 72, 91};
    int target_element = 23;
    int array_size = sizeof(sorted_array) / sizeof(sorted_array[0]);
    int result = binary_search(sorted_array, array_size, target_element);

    if (result != -1) {
        printf("Element %d found at index %d.\n", target_element, result);
    } else {
        printf("Element %d not found in the array.\n", target_element);
    }
    return 0;
}

