/* C System headers*/
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

/* C++ headers */
#include <iostream>

int main(int argc, const char **argv) {
  std::cout << "VERSION ???\n";
  // Sets up socket descriptor of type int (server_fd) for an
  // IPv4 stream socket using TCP
  int server_fd = socket(AF_INET, SOCK_STREAM, 0);

  // PERF: Maybe write an encompasing error func for these checks
  if (server_fd < 0) {
    std::cerr << "Failed to create a server socket\n";
    return 1;
  }

  // Test suite restarts program often, set SO_REUSEADDR to ensure
  // we don't run into 'Addr already in use' error
  int reuse = 1;
  int returncodesockopt = setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR,
                                     &reuse, sizeof(reuse));
  if (returncodesockopt) {
    std::cerr << "setting socket opt failed!\n";
    return 1;
  }
  // Creates listener socket structure to store relevant info
  // type of socket (ipv4), internet addres (any rn), port (4221)
  struct sockaddr_in server_addr;
  server_addr.sin_family = AF_INET;
  server_addr.sin_addr.s_addr = INADDR_ANY;
  server_addr.sin_port = htons(4221);  // FIX: remove magic num

  int bindresult = bind(server_fd, (struct sockaddr *)&server_addr,
                        sizeof(server_addr));
  if (bindresult < 0) {
    std::cerr << "Failed to bind to port 4221\n";
    return 1;
  }

  int connection_backlog = 5;
  if (listen(server_fd, connection_backlog) != 0) {
    std::cerr << "listen failed\n";
    return 1;
  }

  struct sockaddr_in client_addr;
  int client_addr_len = sizeof(client_addr);

  std::cout << "waiting for connections\n";
  int client_fd = accept(server_fd, (sockaddr *)&client_addr,
                         (socklen_t *)&client_addr_len);
  if (client_fd < 0) {
    std::cerr << "Connection failed?\n";
    return 1;
  }
  std::cout << "Accepted Connection!\n";

  close(server_fd);
  return 0;
}
