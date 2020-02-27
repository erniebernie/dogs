CC=gcc
CFLAGS=
DEPS= dogstruct.h
OBJ= dog_struct.o main.o
NAME= dogs
MAIN= 


%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)
default: $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(CFLAGS) 

clean:
	rm $(NAME) *.o

run:
	./$(NAME)






