#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

struct dog_array{
    int num_dogs;
    struct dog** arr;
};

struct dog{
    char * name; 	// Name of the dog
    char * color; 	// color of the dog, i.e. brown, black, white, golden
    uint8_t age; 	// 0 - 20 years
    uint8_t weight; 	// 4 - 160 pounds
};

struct dog * create_dog(char * name, char * color, uint8_t age, uint8_t weight);
void delete_dog(struct dog * d);
void print_dogs(struct dog_array* d);



