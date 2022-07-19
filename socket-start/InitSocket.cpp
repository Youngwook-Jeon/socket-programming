#include "../Common.h"

int main(int argc, char *argv[])
{
  // Create a socket
  SOCKET sock = socket(AF_INET, SOCK_STREAM, 0);
  if (sock == INVALID_SOCKET) err_quit("socket()");
  printf("[Notice] Socket creation success!\n");

  // Close the socket
  close(sock);

  return 0;
}