#ifndef __OPEN_CLIENTFD_H__
#define __OPEN_CLIENTFD_H__
#include <stdlib.h>
#include <strings.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
extern int open_clientfd(char* server_ip, int port);
#endif
