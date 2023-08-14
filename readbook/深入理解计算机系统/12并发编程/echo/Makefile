.PHONY:all
all:server client 

server:echo_ser.c ../open_fd/open_listenfd.c
	gcc -o $@ $^
client:echo_cli.c ../open_fd/open_clientfd.c
	gcc -o $@ $^

.PHONY:clean
clean:
	rm -f server client
