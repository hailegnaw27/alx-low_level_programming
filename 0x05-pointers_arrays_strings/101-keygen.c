#include "main.h"

/**
 * print_chessboard - prints a chessboard
 * @a: the chessboard to print
 *
 * Return: void
 */
void print_chessboard(char (*a)[8])
{
    int row, col;

    for (row = 0; row < 8; row++)
    {
        for (col = 0; col < 8; col++)
        {
            putchar(a[row][col]);
            if (col == 7)
                putchar('\n');
        }
    }
}

