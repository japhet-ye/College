
hello: hello.o hello1.o hello2.o hello3.o
	gcc -o hello.o hello1.o hello2.o hello3.o hello.h 
	./project

hello.o : hello.c
	gcc -c hello.c

hello1.o : hello1.c
	gcc -c hello1.c

hello2.o : hello2.c
	gcc -c hello2.c

hello3.o : hello3.c
	gcc -c hello3.c

remove:
	rm *.o
