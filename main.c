#include <stdio.h>

#include "dog_struct.h"


int main(){

    printf("Size of dog = %ld\n", sizeof(struct dog));

    int num_dogs = 4;
    struct dog* d0 = create_dog("Dog0", "White", 1, 4);
    struct dog* d1 = create_dog("Dog1", "Brown", 14, 20);
    struct dog* d2 = create_dog("Dog2", "Black", 13, 30);
    struct dog* d3 = create_dog("Dog3", "Golden", 2, 150);

    struct dog** dog_array = (struct dog**) malloc(num_dogs * sizeof(struct dog**));
    printf("Size of dog pointer = %d\n", (int) sizeof(struct dog*));

    dog_array[0] = d0;  
    dog_array[1] = d1;  
    dog_array[2] = d2;  
    dog_array[3] = d3;  

    for (int i = 0; i < num_dogs; i++) {
	printf("The %s dog, %s, is %d years old and %d lbs!\n", 
		dog_array[i]->name,
		dog_array[i]->color,
		dog_array[i]->age,
		dog_array[i]->weight);
    }

    free(dog_array);
    dog_array = NULL;

    delete_dog(d0);
    delete_dog(d1);
    delete_dog(d2);
    delete_dog(d3);

    return 0;
}
