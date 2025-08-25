#include <stdio.h>
#include <string.h>

// Function to swap characters
void swap(char *x, char *y) {
    char temp = *x;
    *x = *y;
    *y = temp;
}

// Recursive function to generate permutations
void permute(char *str, int l, int r) {
    if (l == r) {
        printf("%s\n", str);  // Print one permutation
    } else {
        for (int i = l; i <= r; i++) {
            // Swap current index with l
            swap((str + l), (str + i));

            // Recurse for the rest of the string
            permute(str, l + 1, r);

            // Backtrack (undo the swap)
            swap((str + l), (str + i));
        }
    }
}

int main() {
    char str[20];
    printf("Enter a string: ");
    scanf("%s", str);

    int n = strlen(str);
    printf("All permutations of the string are:\n");
    permute(str, 0, n - 1);

    return 0;
}
