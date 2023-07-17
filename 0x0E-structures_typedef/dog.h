#ifndef DOG_H
#define DOG_H
/**
* struct dog - Structure representing a dog
* @name: Name of the dog
* @age: Age of the dog
* @owner: Owner of the dog
*
* Description: Structure representing a dog with its name, age, and owner.
*/
typedef struct dog
{
char *name;
float age;
char *owner;
} dog_t;

/* Function prototypes */
void init_dog(struct dog *d, char *name, float age, char *owner);
void print_dog(struct dog *d);
dog_t *new_dog(char *name, float age, char *owner);
void free_dog(dog_t *d);

#endif /* DOG_H */

