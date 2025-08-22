#include <stdio.h>
#include <string.h>

// Function to reverse words in a string
void reverseWords(char *s) {
    char *words[100];  // Array to store word pointers
    int n = 0;

    // Use strtok to split words (ignores multiple spaces automatically)
    char *token = strtok(s, " ");
    while (token != NULL) {
        words[n++] = token;
        token = strtok(NULL, " ");
    }

    // Print words in reverse order
    for (int i = n - 1; i >= 0; i--) {
        printf("%s", words[i]);
        if (i > 0) printf(" ");  // Add space between words
    }
    printf("\n");
}

int main() {
    char str[] = "   the   sky  is  blue   ";
    reverseWords(str);
    return 0;
}
