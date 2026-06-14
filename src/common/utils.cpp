#include "common/utils.h"

// C sys headers, & any other headers in <> brackets with the .h extension

// C++ standard lib headers (w/o file ext)
#include <iostream>
#include <string>

// Other lib's .h files

// My project's .h files

namespace http_cjz {
namespace common {

void checkErr(int return_code, const std::string& context_msg) {
  if (return_code < 0) {
    std::cerr << context_msg;
    // TODO: Handle shutting down cleanly here if a socket.h call failed
  }
}

}  // namespace common

}  // namespace http_cjz
