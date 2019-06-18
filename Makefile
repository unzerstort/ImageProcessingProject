.PHONY: all, build, clean, folders

all: build

build: folders exe

clean:
	rm -rf objects
	rm -f exe

folders:
	mkdir -p objects

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

exe: src/main.c objects/menu.o objects/filters.o objects/util.o objects/file.o objects/transform.o
	gcc src/main.c objects/menu.o objects/filters.o objects/util.o objects/file.o objects/transform.o -Iinclude -o exe
