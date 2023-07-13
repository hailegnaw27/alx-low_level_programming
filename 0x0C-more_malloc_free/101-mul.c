#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int validate_arguments(int argc, char *argv[]) {
    int i, j;

    /* Check if the number of arguments is correct */
    if (argc != 3) {
        printf("Error\n");
        return 0;
    }

    /* Check if both arguments are composed of digits */
    for (i = 1; i < argc; i++) {
        for (j = 0; argv[i][j] != '\0'; j++) {
            if (!isdigit(argv[i][j])) {
                printf("Error\n");
                return 0;
            }
        }
    }

    return 1;
}

void multiply_numbers(char *num1, char *num2) {
    /* Convert the string representations of num1 and num2 to integers */
    int n1 = atoi(num1);
    int n2 = atoi(num2);

    /* Multiply num1 and num2 */
    int result = n1 * n2;

    /* Print the result */
    printf("%d\n", result);
}

int main(int argc, char *argv[]) {
    /* Validate the arguments */
    if (!validate_arguments(argc, argv)) {
        return 98;
    }

    /* Multiply the numbers */
    multiply_numbers(argv[1], argv[2]);

    return 0;
}

