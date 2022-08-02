#include <sys/types.h> // basic type definitions
#include <sys/socket.h> // socket(), AF_INET, ...
#include <unistd.h> // close(), ...
#include <arpa/inet.h> // htons(), htonl(), ...
#include <netdb.h> // gethostbyname()...

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

typedef int SOCKET;
#define SOCKET_ERROR   -1
#define INVALID_SOCKET -1

void err_quit(const char *msg)
{
  char *msgbuf = strerror(errno);
  printf("[%s] %s\n", msg, msgbuf);
  exit(1);
}

void err_display(const char *msg)
{
  char *msgbuf = strerror(errno);
  printf("[%s] %s\n", msg, msgbuf);
}
