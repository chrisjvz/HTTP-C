#ifndef INCLUDE_COMMON_UTILS_H_
#define INCLUDE_COMMON_UTILS_H_

#include <string>
namespace http_cjz {
namespace common {

// QOL to avoid cluttered IF statements after using networking API calls
void checkErr(int return_code, const std::string& context_msg);

}  // namespace common
}  // namespace http_cjz

#endif  // INCLUDE_COMMON_UTILS_H_
