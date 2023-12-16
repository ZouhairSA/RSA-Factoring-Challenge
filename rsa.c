#include <stdio.h>

void factorize_rsa(int n) {
    printf("%d=", n);

    for (int i = 2; i <= n; i++) {
        while (n % i == 0) {
            printf("%d", i);
            n /= i;

            if (n > 1) {
                printf("*");
            }
        }
    }

    printf("\n");
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

    int num;
    while (fscanf(file, "%d", &num) == 1) {
        factorize_rsa(num);
    }

    fclose(file);

    return 0;
}

