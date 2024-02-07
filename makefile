CC = gcc
AR = ar
FLAGS = -Wall -g
EXECUTABLES = my_graph my_Knapsack

.PHONY: all clean

my_graph.o: my_graph.c my_mat.o my_mat.h
	$(CC) $(FLAGS) -c $<
my_mat.o: my_mat.c my_mat.h
	$(CC) $(FLAGS) -c $<
mymatlib.a: my_mat.o
	$(AR) -rcs $@ $^

# Generate my_graph executable
my_graph: my_graph.o mymatlib.a
	$(CC) $(FLAGS) -o $@ $^

# Generate my_Knapsack executable
my_Knapsack: my_Knapsack.o
	$(CC) $(FLAGS) -o $@ $^
my_Knapsack.o: my_Knapsack.c
	$(CC) $(FLAGS) -c $^

# generate all executables
all: $(EXECUTABLES)

clean:
	rm -f *.o *.a *.so $(EXECUTABLES)