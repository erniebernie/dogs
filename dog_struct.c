#include "dog_struct.h"


struct dog * create_dog(char * name, char * color, uint8_t age, uint8_t weight){

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



