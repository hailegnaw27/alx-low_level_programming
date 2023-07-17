#include <stdio.h>
#include <stdlib.h>

struct dog {
    char *name;
    float age;
    char *owner;
};

/**
 * init_dog - initializes a variable of type struct dog
 * @d: pointer to the struct dog to initialize
 * @name: name of the dog
 * @age: age of the dog
 * @owner: owner of the dog
 */
void init_dog(struct dog *d, char *name, float age, char *owner)
{
    if (d == NULL)
    {
        printf("Error: Invalid pointer\n");
        exit(EXIT_FAILURE);
    }

    d->name = name;
    d->age = age;
    d->owner = owner;
}

int main(void)
{
    struct dog my_dog;

    init_dog(&my_dog, "Poppy", 3.5, "Bob");
    printf("My name is %s, and I am %.1f :) - Woof!\n", my_dog.name, my_dog.age);

    return (0);
}

