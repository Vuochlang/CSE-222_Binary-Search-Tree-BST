plate: main.o dumps.o add.o free.o delete.o search.o balanced.o height.o
	gcc -o plate main.o dumps.o add.o free.o delete.o search.o balanced.o height.o

main.o: main.c add.c dumps.c search.c delete.c free.c all.h
	gcc -c main.c add.c dumps.c search.c delete.c free.c 

add.o: add.c all.h
	gcc -c add.c

dumps.o: dumps.c balanced.c height.c all.h
	gcc -c dumps.c balanced.c height.c 

free.o: free.c all.h
	gcc -c free.c

delete.o: delete.c all.h
	gcc -c delete.c

search.o: search.c all.h
	gcc -c search.c

balanced.o: balanced.c all.h
	gcc -c balanced.c

height.o: height.c all.h
	gcc -c height.c 
