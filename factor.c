#include <stdio.h>
#include <stdlib.h>

void factorize(unsigned long n) {
    for (unsigned long i = 2; i <= n / 2; i++) {
        if (n % i == 0) {
            printf("%lu=%lu*%lu\n", n, i, n / i);
            return;
        }
    }
    // If no factors are found, print the number itself
    printf("%lu=%lu*1\n", n, n);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <file>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    unsigned long n;
    while (fscanf(file, "%lu", &n) != EOF) {
        if (n > 1) {
            factorize(n);
        }
    }

    fclose(file);
    return 0;
}
