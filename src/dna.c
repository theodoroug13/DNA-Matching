#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int getDna(char **a, FILE *file) {
    int c, i = 0;
    int buffer_size = 256; // Allocate initial memory
    *a = malloc(buffer_size * sizeof(char));
    if (!*a) return 1;

    while ((c = fgetc(file)) != EOF) {
        if (c == 'A' || c == 'G' || c == 'C' || c == 'T') {
            if (i >= buffer_size - 1) { // Expand memory if needed
                buffer_size *= 2;
                char *temp = realloc(*a, buffer_size * sizeof(char));
                if (!temp) {
                    free(*a);
                    return 1;
                }
                *a = temp;
            }
            (*a)[i++] = c;
        }
    }
    (*a)[i] = '\0';
    return 0;
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <file1> <file2>\n", argv[0]);
        return 1;
    }

    FILE *file1 = fopen(argv[1], "r");
    FILE *file2 = fopen(argv[2], "r");
    if (!file1 || !file2) {
        fprintf(stderr, "Error: Could not open file(s)\n");
        return 1;
    }

    char *s1 = NULL, *s2 = NULL;
    if (getDna(&s1, file1) || getDna(&s2, file2)) {
        fprintf(stderr, "Memory allocation error.\n");
        return 1;
    }

    fclose(file1);
    fclose(file2);

    if (!s1 || !s2 || strlen(s1) == 0 || strlen(s2) == 0) {
        printf("No common substring found.\n");
        return 0;
    }

    int length1 = strlen(s1);
    int length2 = strlen(s2);
    int maxcount = 0, start = 0;

    for (int i = 0; i < length1; i++) {
        for (int j = 0; j < length2; j++) {
            int count = 0, a = i, b = j;
            while (a < length1 && b < length2 && s1[a] == s2[b]) {
                count++;
                a++;
                b++;
            }
            if (count > maxcount) {
                maxcount = count;
                start = i;
            }
        }
    }

    if (maxcount == 0) {
        printf("No common substring found.\n");
    } else {
        char *lcs = malloc((maxcount + 1) * sizeof(char));
        if (!lcs) {
            fprintf(stderr, "Memory allocation error.\n");
            return 1;
        }
        strncpy(lcs, s1 + start, maxcount);
        lcs[maxcount] = '\0';
        printf("Longest Common Substring: %s\n", lcs);
        free(lcs);
    }

    free(s1);
    free(s2);
    return 0;
}
