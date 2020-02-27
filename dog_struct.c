#include "dog_struct.h"


struct dog * create_dog(char * name, int age){

    struct dog * d = NULL;
    d = (struct dog *) malloc(sizeof(struct dog));

    d->name = name;
    d->age = age;

    if (d == NULL) {
	exit(1);
    }

    return d;
}

void delete_dog(struct dog * d){
    if (d != NULL) {
	free(d);
    }
}



