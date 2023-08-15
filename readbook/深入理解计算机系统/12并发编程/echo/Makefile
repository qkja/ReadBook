.PHONY:all
all:myserver client 

myserver:echo_ser.cc ../open_fd/open_listenfd.cc
	g++ -o $@ $^ -lpthread
client:echo_cli.cc ../open_fd/open_clientfd.cc
	g++ -o $@ $^

.PHONY:clean
clean:
	rm -f myserver client
