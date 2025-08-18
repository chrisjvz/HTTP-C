# --- PROJECT DEFINITONS --- #
cmake_minimum_required(VERSION 4.1) # Version on my machine
project(HTTP-Cz) #TODO: Add version and language flags here?

# --- GLOBAL SETTINGS & OPTS --- #
# Gtest requires 17 so even if we dont need it for our app
# well set it as required for now 
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Compilecommands.json produced on every build
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Put executable at top level of source tree
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR})

# Put STATIC libraries in build/lib
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
# Put SHARED libraries in build/lib
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)


# --- ORCHESTRATION --- #
add_subdirectory(src)

# TODO: Add subdirectorys for all libs

add_executable(${PROJECT_NAME} main.cpp)

target_link_libraries(${PROJECT_NAME} PRIVATE server_core)
# --- TESTING FRAMEWORK --- #
#  Need to compile if() based on TEST_MODE 
#	and setup googletest

# --- INSTALLATION --- #
#  Need to do specify this stuff eventually
