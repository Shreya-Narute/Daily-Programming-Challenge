#include <stdio.h>

void findLeaders(int arr[], int n) {
    int leaders[n];      // to store leaders
    int count = 0;       // number of leaders found
    
    int max_from_right = arr[n-1];
    leaders[count++] = max_from_right;   // last element is always leader

    // Traverse from right to left
    for (int i = n-2; i >= 0; i--) {
        if (arr[i] >= max_from_right) {
            leaders[count++] = arr[i];
            max_from_right = arr[i];
        }
    }

    // Print leaders in correct order (reverse of storage)
    printf("Leaders: ");
    for (int i = count-1; i >= 0; i--) {
        printf("%d ", leaders[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {16, 17, 4, 3, 5, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    findLeaders(arr, n);

    return 0;
}
