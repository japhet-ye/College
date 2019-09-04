all: EE367client.c EE367server.c
	gcc -o clientJaf.out EE367client.c 
	gcc -o serverJaf.out EE367server.c 
	./serverJaf.out &
	./clientJaf.out wiliki.eng.hawaii.edu
clean:
	rm clientJaf.out
	rm serverJaf.out