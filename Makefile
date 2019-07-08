# Makefile for the Image Processing Project
#         made by Sandra Bastos

# phony targets ("recipes" to be executed) 

.PHONY: all, build, clean, folders

# the command "make" will build everything that's in build target

all: build

# "make build" will build all modules

build: folders exe

# "make clean" will delete the objects folder and the executable
# created by "make build" (if it already exists)
# also, the -r flag makes the remove command delete the files
# and their content recursively, while -f will force it to
# ignore nonexistent files and arguments

clean:
	rm -rf objects
	rm -f exe

# "make folders" will create the directory where the compiled
# objects will go to

folders:
	mkdir -p objects

# the next targets are referring to the compilation process 
# of the other .c files besides main 

objects/menu.o: src/menu.c
	gcc src/menu.c -Iinclude -c -o objects/menu.o

objects/filters.o: src/filters.c
	gcc src/filters.c -Iinclude -c -o objects/filters.o

objects/util.o: src/util.c
	gcc src/util.c -Iinclude -c -o objects/util.o

objects/file.o: src/file.c
	gcc src/file.c -Iinclude -c -o objects/file.o

objects/transform.o: src/transform.c
	gcc src/transform.c -Iinclude -c -o objects/transform.o

# this target has the instructions needed for the compilation
# of main.c and all the objects previously compiled

exe: src/main.c objects/menu.o objects/filters.o objects/util.o objects/file.o objects/transform.o
	gcc src/main.c objects/menu.o objects/filters.o objects/util.o objects/file.o objects/transform.o -Iinclude -o exe
