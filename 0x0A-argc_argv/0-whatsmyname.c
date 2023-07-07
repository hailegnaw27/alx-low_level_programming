#include "main.h"

/**
 * main - Entry point
 * @argc: The number of command line arguments
 * @argv: An array containing the command line arguments
 *
 * Return: Always 0 (Success)
 */
int main(int argc, char *argv[])
{
    /* Print the name of the program */
    print_name(argv[0]);

    return 0;
}

/**
 * print_name - Prints the name of the program
 * @name: The name of the program
 */
void print_name(char *name)
{
    while (*name)
    {
        _putchar(*name);
        name++;
    }
    _putchar('\n');
}

