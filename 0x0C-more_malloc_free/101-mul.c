#include <stdio.h>
#include <stdlib.h>
#include "main.h"
/**
 * main - Entry point
 * @argc: Number of command-line arguments
 * @argv: Array of command-line arguments
 *
 * Return: 0 on success, 98 on error
 */
int main(int argc, char *argv[])
{
	/* Check the number of arguments */
	if (argc != 3)
	{
		printf("Error\n");
		return (98);
	}

	/* Extract the numbers from command line arguments */
	char *num1_str = argv[1];
	char *num2_str = argv[2];

	/* Check if the inputs are valid numbers */
	for (int i = 0; num1_str[i] != '\0'; i++)
	{
		if (num1_str[i] < '0' || num1_str[i] > '9')
		{
			printf("Error\n");
			return (98);
		}
	}
	for (int i = 0; num2_str[i] != '\0'; i++)
	{
		if (num2_str[i] < '0' || num2_str[i] > '9')
		{
			printf("Error\n");
			return (98);
		}
	}

	/* Convert the numbers to integers */
	int num1 = atoi(num1_str);
	int num2 = atoi(num2_str);

	/* Multiply the numbers */
	int result = num1 * num2;

	/* Print the result */
	printf("%d\n", result);

	return (0);
}

