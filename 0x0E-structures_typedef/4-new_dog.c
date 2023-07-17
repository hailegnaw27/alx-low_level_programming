#include <stdlib.h>
#include "dog.h"

/**
* new_dog - Creates a new dog
* @name: Name of the dog
* @age: Age of the dog
* @owner: Owner of the dog
*
* Return: Pointer to the created dog, or NULL if allocation fails
*/
dog_t *new_dog(char *name, float age, char *owner)
{
dog_t *new_dog;
int name_len, owner_len, i;

/* Calculate the length of name and owner */
for (name_len = 0; name[name_len] != '\0'; name_len++)
;
for (owner_len = 0; owner[owner_len] != '\0'; owner_len++)
;

/* Allocate memory for the new dog */
new_dog = malloc(sizeof(dog_t));
if (new_dog == NULL)
return (NULL);

/* Allocate memory for the name and owner strings */
new_dog->name = malloc((name_len + 1) * sizeof(char));
new_dog->owner = malloc((owner_len + 1) * sizeof(char));
if (new_dog->name == NULL || new_dog->owner == NULL)
{
free(new_dog->name);
free(new_dog->owner);
free(new_dog);
return (NULL);
}

/* Copy the name and owner strings */
for (i = 0; i <= name_len; i++)
new_dog->name[i] = name[i];
for (i = 0; i <= owner_len; i++)
new_dog->owner[i] = owner[i];

/* Set the age of the new dog */
new_dog->age = age;

return (new_dog);
}
