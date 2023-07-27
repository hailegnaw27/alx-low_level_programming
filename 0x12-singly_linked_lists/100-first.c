#include <stdio.h>

void print_before_main(void) __attribute__((constructor));

/**
 * print_before_main - Print the main function is executed
 */
void print_before_main(void)
{
	printf("You're beat! and yet, you must allow,\n");
	printf("I bore my house upon my back!\n");
}

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
	printf("(A tortoise, having pretty good sense of a hare's nature,\n");
	printf(" challenges one to a race.)\n");
	return (0);
}

