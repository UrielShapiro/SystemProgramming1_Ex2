CC = gcc
FLAGS = -Wall -g
EXECUTABLES = my_graph

my_graph.o: my_graph.c my_mat.o my_mat.h
	$(CC) $(FLAGS) -c my_graph.c
my_mat.o: my_mat.c my_mat.h
	$(CC) $(FLAGS) -c my_mat.c

my_graph: my_graph.o mymatlib.a
	$(CC) $(FLAGS) -o $@ $^

mymatlib.a: my_mat.o
	ar -rcs $@ $^

clean:
	rm -f *.o *.a *.so $(EXECUTABLES)