#include <stdio.h>
#include <string.h>

#include "dog_struct.h"


int main(){






    printf("Size of dog = %ld bytes\n", sizeof(struct dog));
    printf("Size of dog pointer = %d bytes\n", (int) sizeof(struct dog*));

    struct dog_array dogs, dogs2;
    dogs.num_dogs = 5;
    dogs.arr = (struct dog**) malloc(dogs.num_dogs * sizeof(struct dog**));

    struct dog* d0 = create_dog("Dog0", "White", 1, 4);
    struct dog* d1 = create_dog("Dog1", "Brown", 14, 20);
    struct dog* d2 = create_dog("Dog2", "Black", 13, 30);
    struct dog* d3 = create_dog("Dog3", "Golden", 2, 150);
    struct dog* d4 = create_dog("Dog4", "Black", 5, 70);


    dogs.arr[0] = d0;  
    dogs.arr[1] = d1;  
    dogs.arr[2] = d2;  
    dogs.arr[3] = d3;  
    dogs.arr[4] = d4;  


    print_dogs(&dogs);


    // shallow copy ?
    *d0 = *d1;

    // deep copy ?
    memcpy(d2, d3, sizeof(struct dog));


    printf("After change\n");
    print_dogs(&dogs);

    
    dogs2.num_dogs = dogs.num_dogs;
    dogs2.arr = (struct dog**) malloc(dogs2.num_dogs * sizeof(struct dog**));


    dogs2.arr[0] = create_dog(NULL, NULL, 0, 0);
    dogs2.arr[1] = create_dog(NULL, NULL, 0, 0);
    dogs2.arr[2] = create_dog(NULL, NULL, 0, 0);
    dogs2.arr[3] = create_dog(NULL, NULL, 0, 0);
    dogs2.arr[4] = create_dog(NULL, NULL, 0, 0);



    printf("Copying dogs!\n");
    // memcpy(*dogs2.arr, *dogs.arr, dogs.num_dogs * sizeof(struct dog));
    //
    printf("%d vs %d\n", dogs2.num_dogs, dogs.num_dogs);
    // IDK WHY THIS NEEDS TO BE +2. Makes no sense!
    memcpy(*dogs2.arr, *dogs.arr, ((size_t) (dogs.num_dogs + 2)) * sizeof(struct dog));
    
    
    printf("Done copying dogs!\n");
    print_dogs(&dogs2);



    // free and deleting everything
    printf("Freeing dog array 1!\n");
    free(dogs.arr);
    dogs.arr = NULL;
    
    delete_dog(d0);
    delete_dog(d1);
    delete_dog(d2);
    delete_dog(d3);
    delete_dog(d4);
    
    
    
    printf("Freeing dog array 2!\n");
    delete_dog(dogs2.arr[0]);
    delete_dog(dogs2.arr[1]);
    delete_dog(dogs2.arr[2]);
    delete_dog(dogs2.arr[3]);
    delete_dog(dogs2.arr[4]);
    
    free(dogs2.arr);
    dogs2.arr = NULL;


/*
    int array_num = 10;
    int * arr1 = (int*) malloc(array_num * sizeof(int));
    memset(arr1, 0, array_num * sizeof(int));
    arr1[5] = 5;

    int * arr2 = (int*) malloc(array_num * sizeof(int));
    memset(arr2, 0, array_num * sizeof(int));

    for(int i = 0; i < array_num; i++) {
    printf("arr1[%d] = %d, arr2[%d] = %d\n", array_num, arr1[i], array_num, arr2[i]);
    }

    memcpy(arr2, arr1, array_num * sizeof(int));

    printf("After memcpy()\n");

    for(int i = 0; i < array_num; i++) {
    printf("arr1[%d] = %d, arr2[%d] = %d\n", array_num, arr1[i], array_num, arr2[i]);
    }

    free(arr1);
    free(arr2);
*/


    return 0;
}
