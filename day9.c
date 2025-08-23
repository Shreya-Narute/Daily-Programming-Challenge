#include <stdio.h>
#include <string.h>

// Function to find the longest common prefix
char* longestCommonPrefix(char strs[][100], int n) {
    static char prefix[100];  // store result
    strcpy(prefix, strs[0]);  // assume first string is prefix

    for (int i = 1; i < n; i++) {
        int j = 0;
        while (prefix[j] && strs[i][j] && prefix[j] == strs[i][j]) {
            j++;
        }
        prefix[j] = '\0'; // shorten prefix to matched part
    }
    return prefix;
}

int main() {
    int n;
    printf("Enter number of strings: ");
    scanf("%d", &n);

    char strs[n][100];
    printf("Enter the strings:\n");
    for (int i = 0; i < n; i++) {
        scanf("%s", strs[i]);
    }

    char* result = longestCommonPrefix(strs, n);
    if (strlen(result) == 0)
        printf("Output: \"\"\n");   // no prefix
    else
        printf("Output: \"%s\"\n", result);

    return 0;
}
