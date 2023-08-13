#ifndef __OPEN_LISTEBFD_H__
#define __OPEN_LISTEBFD_H__
#include <netinet/in.h>
#include <strings.h>
#include <sys/types.h>          
#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdlib.h>
extern int open_listenfd(int port);
#endif
