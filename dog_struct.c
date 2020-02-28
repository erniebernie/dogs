#include "dog_struct.h"


struct dog * create_dog(char * name, char * color, uint8_t age, uint8_t weight){

    static int dog_create_count = 0;
    printf("Dogs created = %d\n", dog_create_count);
    dog_create_count++;

    // create dog struct
    struct dog * d = NULL;
    d = (struct dog *) malloc(sizeof(struct dog));


    // if NULL then exit
    if (d == NULL) {
	exit(1);
    }

    // set variables
    d->name = name;
    d->color = color;
    d->age = age;
    d->weight = weight;

    // return obvi 
    return d;
}

void delete_dog(struct dog * d){
    if (d != NULL) {
	free(d);
	d = NULL;
    }
}

void print_dogs(struct dog_array* d){

    for (int i = 0; i < d->num_dogs; i++) {
	printf("ptr: %p, ", d->arr[i]);
	printf("The %s dog, %s, is %d years old and %d lbs!\n", 
		d->arr[i]->name,
		d->arr[i]->color,
		d->arr[i]->age,
		d->arr[i]->weight);
    }

}




