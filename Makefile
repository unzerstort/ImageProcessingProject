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

objects/read.o: src/read.c
	gcc src/read.c -Iinclude -c -o objects/read.o

objects/write.o: src/write.c
	gcc src/write.c -Iinclude -c -o objects/write.o

exe: src/main.c objects/menu.o objects/filters.o objects/util.o objects/read.o objects/write.o
	gcc src/main.c objects/menu.o objects/filters.o objects/util.o objects/read.o objects/write.o -Iinclude -o exe
