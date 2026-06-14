# --- PROJECT DEFINITONS --- #
cmake_minimum_required(VERSION 4.1) # Version on my machine
project(HTTP-Cz 
    VERSION 0.1 # may need to automate this?
    DESCRIPTION "Multi-Threaded Server in C++" 
    HOMEPAGE_URL "https://github.com/chrisjvz/HTTP-C"
    LANGUAGES CXX C) 



# --- GLOBAL SETTINGS & OPTS --- #
# Gtest need C++ 17 and well use it in our project as well
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Compilecommands.json produced on every build
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Put STATIC libraries in build/lib
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)


# --- ORCHESTRATION --- #
add_subdirectory(src)

# --- TESTING FRAMEWORK --- #
#  Need to compile if() based on TEST_MODE 
#	and setup googletest

# --- INSTALLATION --- #
#  Need to do specify this stuff eventually
