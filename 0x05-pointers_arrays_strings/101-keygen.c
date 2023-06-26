#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * main - Generates a random password
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
    int i;
    char password[11];
    const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()_+{}:\"<>?,./;'[]\\-=`~";

    srand(time(NULL));

    for (i = 0; i < 10; i++) {
        password[i] = charset[rand() % sizeof(charset)];
    }

    password[10] = '\0';

    printf("Random Password: %s\n", password);

    return (0);
}

