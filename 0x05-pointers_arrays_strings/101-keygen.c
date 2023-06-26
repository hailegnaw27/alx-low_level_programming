#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * main - Generates a random password for 101-crackme
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
    int i;
    char password[16];
    const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";

    srand(time(NULL));

    for (i = 0; i < 15; i++) {
        password[i] = charset[rand() % sizeof(charset)];
    }

    password[15] = '\0';

    printf("%s", password);

    return (0);
}

