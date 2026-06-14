/* C System headers*/
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

/* C++ headers */
#include <iostream>

#include "common/utils.h"

int main(int argc, const char **argv) {
  /*
   * 1- setup listening socket (server_core)
   * 2- bind listening sock to sys port (server_core)
   * 3- actively listen with backlog (server_core & threadpool?)
   * 4- handle requests (threadpool & server_core?)
   *    - (http requests & endpoints)
   * */

  std::cout << "VERSION ???\n";
  // Sets up socket descriptor of type int (server_fd) for an
  // IPv4 stream socket using TCP
  int server_fd = socket(AF_INET, SOCK_STREAM, 0);
  http_cjz::common::checkErr(server_fd, "Failed to create a server socket!\n");

  // Test suite restarts program often, set SO_REUSEADDR to ensure
  // we don't run into 'Addr already in use' error
  int reuse = 1;
  int returncodesockopt = setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR,
                                     &reuse, sizeof(reuse));
  http_cjz::common::checkErr(returncodesockopt, "Setting socket opt failed!\n");

  // Creates listener socket structure to store relevant info
  // type of socket (ipv4), internet addres (any rn), port (4221)
  struct sockaddr_in server_addr;
  server_addr.sin_family = AF_INET;
  server_addr.sin_addr.s_addr = INADDR_ANY;
  server_addr.sin_port = htons(4221);  // FIX: remove magic num

  int bindresult = bind(server_fd, (struct sockaddr *)&server_addr,
                        sizeof(server_addr));
  http_cjz::common::checkErr(bindresult, "Failed to bind to port 4221!\n");

  int connection_backlog = 5;
  http_cjz::common::checkErr(listen(server_fd, connection_backlog),
                             "Listen failed!\n");

  struct sockaddr_in client_addr;
  int client_addr_len = sizeof(client_addr);

  std::cout << "waiting for connections\n";
  int client_fd = accept(server_fd, (sockaddr *)&client_addr,
                         (socklen_t *)&client_addr_len);
  http_cjz::common::checkErr(client_fd, "Connection Failed!\n");
  std::cout << "Accepted Connection!\n";

  close(server_fd);
  return 0;
}
