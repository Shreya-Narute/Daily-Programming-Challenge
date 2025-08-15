#include <stdio.h>

void sort(int A[], int size) {
    int L = 0, M = 0, H = size - 1;
    int temp;

    while (M <= H) {
        if (A[M] == 0) {
            temp = A[L];
            A[L] = A[M];
            A[M] = temp;
            L++;
            M++;
        } else if (A[M] == 1) {
           M++;
        } else {
            temp = A[M];
            A[M] = A[H];
            A[H] = temp;
            H--;
        }
    }
}

int main() {
    int arr[] = {0, 2, 1, 0, 0, 1, 0,1, 2};
    int n = sizeof(arr)/sizeof(arr[0]);

    sort(arr, n);

    printf("Sorted Array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}

