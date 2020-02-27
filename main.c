#include <stdio.h>

#include "dog_struct.h"


int main(){

    printf("Size of dog = %ld\n", sizeof(struct dog));

    struct dog * d1 = create_dog("Dog1", 5);



    printf("%s is %d years old!\n", d1->name, d1->age);

    delete_dog(d1);

    return 0;
}
