#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int is_positive_number(const char* str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (!isdigit(str[i])) {
            return 0;
        }
    }
    return 1;
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        printf("Error\n");
        return (98);
    }

    if (!is_positive_number(argv[1]) || !is_positive_number(argv[2])) {
        printf("Error\n");
        return (98);
    }

    int num1 = atoi(argv[1]);
    int num2 = atoi(argv[2]);
    int result = num1 * num2;

    printf("%d\n", result);

    return (0);
}

