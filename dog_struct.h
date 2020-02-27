#include <stdlib.h>

struct dog{
    char * name;
    int age;
};


struct dog * create_dog(char * name, int age);
void delete_dog(struct dog * d);



