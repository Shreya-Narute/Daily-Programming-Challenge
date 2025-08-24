#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to sort characters in a string (used to detect anagrams)
void sortString(char *str) {
    int n = strlen(str);
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (str[i] > str[j]) {
                char temp = str[i];
                str[i] = str[j];
                str[j] = temp;
            }
        }
    }
}

// Function to group anagrams
void groupAnagrams(char strs[][20], int n) {
    int visited[n];
    memset(visited, 0, sizeof(visited));

    for (int i = 0; i < n; i++) {
        if (visited[i]) continue;

        // Print new group
        printf("[ ");
        printf("%s ", strs[i]);
        visited[i] = 1;

        // Sort reference string
        char ref[20];
        strcpy(ref, strs[i]);
        sortString(ref);

        for (int j = i + 1; j < n; j++) {
            if (!visited[j]) {
                char temp[20];
                strcpy(temp, strs[j]);
                sortString(temp);

                if (strcmp(ref, temp) == 0) {
                    printf("%s ", strs[j]);
                    visited[j] = 1;
                }
            }
        }
        printf("]\n");
    }
}

int main() {
    char strs[][20] = {"eat", "tea", "tan", "ate", "nat", "bat"};
    int n = sizeof(strs) / sizeof(strs[0]);

    printf("Grouped Anagrams:\n");
    groupAnagrams(strs, n);

    return 0;
}
