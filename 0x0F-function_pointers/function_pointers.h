#ifndef FUNCTION_POINTERS_H
#define FUNCTION_POINTERS_H

#include <stdlib.h>

/* Task 0 */
void print_name(char *name, void (*f)(char *));

/* Task 1 */
void array_iterator(int *array, size_t size, void (*action)(int));

/* Task 2 */
int int_index(int *array, int size, int (*cmp)(int));

/* Task 3 */
typedef int (*op_func)(int, int);

int op_add(int a, int b);
int op_sub(int a, int b);
int op_mul(int a, int b);
int op_div(int a, int b);
int op_mod(int a, int b);

/* Task 4 */
void print_opcodes(char *num_bytes);

#endif /* FUNCTION_POINTERS_H */

