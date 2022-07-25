server.o: src/server.c
	gcc -c src/server.c 

server: server.o
	gcc -L "ws2_32" -o server server.o

client.o: client.c
	gcc -c client.c

client: client.o
	gcc -o client client.o
